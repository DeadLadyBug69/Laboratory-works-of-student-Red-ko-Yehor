#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funct.h"

// f(x) = (x-10)^3 * sin((x+10)/100) - 10x + 12
double f(double x) {
    return pow(x - 10.0, 3.0) * sin((x + 10.0) / 100.0) - 10.0 * x + 12.0;
}

// Перша похідна f'(x)
double f_prime(double x) {
    return 3.0 * pow(x - 10.0, 2.0) * sin((x + 10.0) / 100.0) 
         + 0.01 * pow(x - 10.0, 3.0) * cos((x + 10.0) / 100.0) - 10.0;
}

// Друга похідна f''(x)
double f_double_prime(double x) {
    return 6.0 * (x - 10.0) * sin((x + 10.0) / 100.0) 
         + 0.06 * pow(x - 10.0, 2.0) * cos((x + 10.0) / 100.0) 
         - 0.0001 * pow(x - 10.0, 3.0) * sin((x + 10.0) / 100.0);
}

// Метод половинного ділення
void solve_bisection(double a, double b, double eps, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("\nПомилка: f(a) та f(b) повинні мати різні знаки.\n");
        return;
    }

    int iter = 0;
    double c = a;

    while (iter < max_iter) {
        c = (a + b) / 2.0;
        iter++;
        
        if (fabs(f(c)) < eps || (b - a) / 2.0 < eps) break;
        
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }

    if (iter >= max_iter) printf("\nДосягнуто ліміт ітерацій.\n");
    
    printf("\n--- Результат ---\n");
    printf("Корінь x = %.8f\nЗначення f(x) = %.8e\nІтерацій = %d\n", c, f(c), iter);
}

// Метод хорд
void solve_chord(double a, double b, double eps, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("\nПомилка: f(a) та f(b) повинні мати різні знаки.\n");
        return;
    }

    double fixed_point = (f(a) * f_double_prime(a) > 0) ? a : b;
    double x_curr = (fixed_point == a) ? b : a;
    double x_next;
    int iter = 0;
   
    while (iter < max_iter) {
        x_next = x_curr - (f(x_curr) * (fixed_point - x_curr)) / (f(fixed_point) - f(x_curr));
        iter++;
        double diff = fabs(x_next - x_curr);
        
        if (diff < eps) {
            x_curr = x_next;
            break;
        }
        x_curr = x_next;
    }

    if (iter >= max_iter) printf("\nДосягнуто ліміт ітерацій.\n");
    
    printf("\n--- Результат (Метод хорд) ---\n");
    printf("Корінь x = %.8f\nЗначення f(x) = %.8e\nІтерацій = %d\n", x_curr, f(x_curr), iter);
}
