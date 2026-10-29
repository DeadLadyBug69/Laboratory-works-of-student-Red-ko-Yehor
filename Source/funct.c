#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "funct.h"

double f(double x) {
    return 1.0 / pow(1.1 + x, 2.0);
}

double left_rect(double a, double b, int n) {
    double h = (b - a) / n, s = 0;
    for (int i = 0; i < n; i++) s += f(a + i * h);
    return s * h;
}

double right_rect(double a, double b, int n) {
    double h = (b - a) / n, s = 0;
    for (int i = 1; i <= n; i++) s += f(a + i * h);
    return s * h;
}

double trapezoid(double a, double b, int n) {
    double h = (b - a) / n, s = 0;
    for (int i = 1; i < n; i++) s += f(a + i * h);
    return (h / 2.0) * (f(a) + f(b) + 2.0 * s);
}

double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++; 
    double h = (b - a) / n, s_odd = 0, s_even = 0;
    for (int i = 1; i < n; i += 2) s_odd += f(a + i * h);
    for (int i = 2; i < n; i += 2) s_even += f(a + i * h);
    return (h / 3.0) * (f(a) + f(b) + 4.0 * s_odd + 2.0 * s_even);
}

void solve_integral(int method_choice, double a, double b, int n_start, double eps, int max_iter) {
    double (*calc)(double, double, int) = NULL;
    const char* method_name = "";
    
    switch (method_choice) {
        case 1: calc = left_rect; method_name = "Метод лівих прямокутників"; break;
        case 2: calc = right_rect; method_name = "Метод правих прямокутників"; break;
        case 3: calc = trapezoid; method_name = "Метод трапецій"; break;
        case 4: calc = simpson; method_name = "Метод парабол (Сімпсона)"; break;
        default: return;
    }

    int n = n_start;
    double I1, I2, delta;
    int iter = 0;

    // Ітераційний процес підбору точності (Рунге)
    while (1) {
        iter++;
        I1 = calc(a, b, n);
        I2 = calc(a, b, n + 2);
        delta = fabs(I1 - I2);

        // Критерій зупинки: досягнуто точність
        if (delta <= eps) {
            n += 2;
            break;
        }

        n += 2;

        // Критерій зупинки: перевищено ліміт ітерацій (запобіжник)
        if (iter >= max_iter) {
            printf("\n[УВАГА] Досягнуто ліміт ітерацій (%d). Точність може бути не досягнута повністю.\n", max_iter);
            break;
        }
    }

    // Миттєве виведення фінального результату
    printf("\n--- %s ---\n", method_name);
    printf("Значення інтеграла I = %.8f\n", I2);
    printf("Кількість розбиттів  = %d\n", n);
    printf("Кількість ітерацій   = %d\n", iter);
    printf("Досягнута похибка    = %.8e\n", delta);
}