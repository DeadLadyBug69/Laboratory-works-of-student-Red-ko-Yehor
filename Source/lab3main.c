#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#include "funct.h"

int main() {
    // Встановлення кодування UTF-8 для коректного відображення
    SetConsoleOutputCP(CP_UTF8);

    LabData data;
    
    // Ручний ввід кількості елементів
    printf("Введіть кількість елементів масиву (не більше %d): ", MAX);
    if (scanf("%d", &data.n) != 1 || data.n <= 0 || data.n > MAX) {
        printf("Помилка: Некоректний розмір масиву.\n");
        system("pause");
        return 1;
    }

    // Ручний ввід самих елементів
    printf("Введіть %d елементів масиву через пробіл або Enter:\n", data.n);
    for (int i = 0; i < data.n; i++) {
        if (scanf("%lf", &data.a[i]) != 1) {
            printf("Помилка: Некоректний ввід числа.\n");
            system("pause");
            return 1;
        }
    }

    // Комплексна обробка в один хід
    printf("\n====================== РЕЗУЛЬТАТИ ======================\n");
    
    printf("Початковий масив: ");
    print_arr(data.a, data.n);

    double Mx = get_Mx(data.a, data.n);
    double Dx = get_Dx(data.a, data.n, Mx);
    
    printf("\n--- Статистика ---\n");
    printf("Математичне сподівання (Mx) = %.4lf\n", Mx);
    printf("Дисперсія вибірки (Dx)      = %.4lf\n", Dx);
    printf("Сер. квадрат. відхилення    = %.4lf\n", sqrt(Dx));

    bubble_sort(data.a, data.n);

    printf("\n--- Сортування та екстремуми ---\n");
    printf("Відсортований масив: ");
    print_arr(data.a, data.n);
    printf("Мінімальний елемент  = %.2lf\n", data.a[0]);
    printf("Максимальний елемент = %.2lf\n", data.a[data.n - 1]);
    
    printf("========================================================\n\n");

    system("pause");
    return 0;
}