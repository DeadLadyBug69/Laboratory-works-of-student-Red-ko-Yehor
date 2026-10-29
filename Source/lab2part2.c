#include <stdio.h>
#include <windows.h>

#include "funct.h"

int main() {
    // Встановлення кодування UTF-8 для коректного відображення української мови
    SetConsoleOutputCP(CP_UTF8);

    // Параметри за замовчуванням
    double a = 0.0, b = 2.0;
    double eps = 0.001;
    int n_start = 10;
    int max_iter = 500000;
    int choice;

    while (1) {
        printf("\n========================================================\n");
        printf("  f(x) = 1 / (1.1 + x)^2 на проміжку [%.2f, %.2f]\n", a, b);
        printf("========================================================\n");
        printf("1. Метод лівих прямокутників\n");
        printf("2. Метод правих прямокутників\n");
        printf("3. Метод трапецій\n");
        printf("4. Метод парабол (Сімпсона)\n");
        printf("0. Вихід\n");
        printf("Оберіть пункт: ");
       
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                solve_integral(choice, a, b, n_start, eps, max_iter);
                break;
            case 0:
                printf("Завершення роботи програми.\n");
                return 0;
            default:
                printf("Некоректний вибір. Спробуйте ще раз.\n");
        }
    }

    return 0;
}