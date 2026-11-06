#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // Бібліотека для заміру часу (clock)
#include "funct.h"

// Варіант 13: f(x) = (x-10)^3 * sin((x+10)/100) - 10x + 12
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
void solve_bisection(double a, double b, double eps, int max_iter, int debug) {
    if (f(a) * f(b) >= 0) {
        printf("\nПомилка: f(a) та f(b) повинні мати різні знаки!\n");
        return;
    }

    int iter = 0;
    double c = a;
    clock_t start_time = clock(); // Старт таймера

    if (debug) printf("\n--- Режим налагодження (Дихотомія) ---\n");

    while (iter < max_iter) {
        c = (a + b) / 2.0;
        iter++;
        
        if (debug) printf("Ітерація: %d | c = %.8f | f(c) = %.8f\n", iter, c, f(c));
        
        if (fabs(f(c)) < eps || (b - a) / 2.0 < eps) break;
        
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }

    clock_t end_time = clock(); // Зупинка таймера
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (iter >= max_iter) printf("\n[УВАГА] Досягнуто ліміт ітерацій!\n");
    
    printf("\n--- Результат (Дихотомія) ---\n");
    printf("Корінь x      = %.8f\n", c);
    printf("Значення f(x) = %.8e\n", f(c));
    printf("Ітерацій      = %d\n", iter);
    printf("Час виконання = %.6f сек\n", time_spent);
}

// Метод хорд
void solve_chord(double a, double b, double eps, int max_iter, int debug) {
    if (f(a) * f(b) >= 0) {
        printf("\nПомилка: f(a) та f(b) повинні мати різні знаки!\n");
        return;
    }

    double fixed_point = (f(a) * f_double_prime(a) > 0) ? a : b;
    double x_curr = (fixed_point == a) ? b : a;
    double x_next;
    int iter = 0;
    clock_t start_time = clock(); // Старт таймера
   
    if (debug) printf("\n--- Режим налагодження (Метод хорд) ---\n");

    while (iter < max_iter) {
        x_next = x_curr - (f(x_curr) * (fixed_point - x_curr)) / (f(fixed_point) - f(x_curr));
        iter++;
        double diff = fabs(x_next - x_curr);
        
        if (debug) printf("Ітерація: %d | x = %.8f | Похибка = %.8f\n", iter, x_next, diff);
        
        if (diff < eps) {
            x_curr = x_next;
            break;
        }
        x_curr = x_next;
    }

    clock_t end_time = clock(); // Зупинка таймера
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (iter >= max_iter) printf("\n[УВАГА] Досягнуто ліміт ітерацій!\n");
    
    printf("\n--- Результат (Метод хорд) ---\n");
    printf("Корінь x      = %.8f\n", x_curr);
    printf("Значення f(x) = %.8e\n", f(x_curr));
    printf("Ітерацій      = %d\n", iter);
    printf("Час виконання = %.6f сек\n", time_spent);
}
