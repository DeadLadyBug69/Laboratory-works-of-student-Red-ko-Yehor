#include <stdio.h>
#include <windows.h>
#include "funct.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double a = 10.0, b = 20.0, eps = 0.00001;
    int max_iter = 1000, choice, debug = 0;

    while (1) {
        printf("\n=======================================================\n");
        printf(" f(x) = (x-10)^3 * sin((x+10)/100) - 10x + 12 = 0\n");
        printf(" Проміжок: [%.1f, %.1f] | Точність: %g\n", a, b, eps);
        printf("=======================================================\n");
        printf("1. Метод половинного ділення\n");
        printf("2. Метод хорд\n");
        printf("3. Змінити параметри (a, b, eps, max_iter)\n");
        printf("4. Режим налагодження: %s\n", debug ? "УВІМКНЕНО" : "ВИМКНЕНО");
        printf("0. Вихід\nОберіть пункт: ");
       
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: 
                solve_bisection(a, b, eps, max_iter, debug); 
                break;
            case 2: 
                solve_chord(a, b, eps, max_iter, debug); 
                break;
            case 3:
                printf("Введіть через пробіл (a b eps max_iter): ");
                scanf("%lf %lf %lf %d", &a, &b, &eps, &max_iter);
                break;
            case 4:
                debug = !debug; // Перемикач режиму
                break;
            case 0:
                printf("Завершення роботи програми.\n");
                return 0;
            default:
                printf("Некоректний вибір.\n");
        }
    }

    return 0;
}
