#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funct.h" 

int main() {
    SetConsoleOutputCP(CP_UTF8);

    unsigned int *A;
    float *B;
    unsigned int Size;

    double average_value;
    unsigned int min_value;
    float max_value;

    printf("Введіть розмір масивів: ");
    if (scanf("%u", &Size) != 1 || Size == 0) {
        printf("Некоректний розмір масиву.\n");
        return 1;
    }

    // Виділення динамічної пам'яті
    A = (unsigned int *)calloc(Size, sizeof(unsigned int));
    B = (float *)malloc(Size * sizeof(float));

    // Перевірка на успішне виділення пам'яті
    if (A == NULL || B == NULL) {
        printf("Помилка виділення пам'яті.\n");
        if (A) free(A);
        if (B) free(B);
        return 1;
    }

    // Заповнення масивів за заданими формулами
    fill_int_array(A, Size);
    fill_float_array(B, Size);

    // Виведення згенерованих масивів у консоль
    print_int_array(A, Size);
    print_float_array(B, Size);

    // Обробка масивів 
    average_value = mean_value(A, Size);
    min_value = find_min(A, Size);
    max_value = find_max(B, Size);

    // Виведення результатів обчислень
    printf("Середнє значення в масиві A: %.2lf\n", average_value);
    printf("Мінімальне значення в масиві A: %u\n", min_value);
    printf("Максимальне значення в масиві B: %.2f\n", max_value);

    // Обов'язкове звільнення динамічної пам'яті перед виходом
    free(A);
    free(B);

    return 0;
}