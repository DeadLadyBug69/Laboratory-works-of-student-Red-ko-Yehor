#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "funct.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned int)time(NULL));

    int n_a = 13;  // Розмірність квадратної матриці A 
    int n_b = n_a; // Кількість рядків B дорівнює n_a для коректного множення A * B
    int m_b;

    printf("Розмірність матриці A: %dx%d\n", n_a, n_a);

    do {
        printf("Введіть кількість стовпців матриці B (m_b > 0): ");
        scanf("%d", &m_b);
    } while (m_b <= 0);

    // Виділення пам'яті
    int **A = memory_allocation(n_a, n_a);
    int **B = memory_allocation(n_b, m_b);

    if (A == NULL || B == NULL) {
        printf("Помилка виділення пам'яті!\n");
        if (A) clear_memory(A, n_a);
        if (B) clear_memory(B, n_b);
        return 1;
    }

    // Вибір способу заповнення матриць
    int mode;
    do {
        printf("\nОберіть спосіб заповнення матриць A і B:\n");
        printf("1 - Введення з клавіатури\n");
        printf("2 - Випадкові числа [0..20]\n");
        printf("3 - За формулою (i + j)\n");
        printf("Ваш вибір: ");
        scanf("%d", &mode);
    } while (mode < 1 || mode > 3);

    if (mode == 1) printf("\nЗаповнення матриці A:\n");
    fill_matrix(A, n_a, n_a, mode);

    if (mode == 1) printf("\nЗаповнення матриці B:\n");
    fill_matrix(B, n_b, m_b, mode);

    // Виведення початкових матриць перед обробкою
    print_matrix(A, n_a, n_a, "A (початкова)");
    print_matrix(B, n_b, m_b, "B (початкова)");

    // Головне меню
    int choice;
    do {
        printf("1 - Знайти max та min матриці A (вище головної діагоналі)\n");
        printf("2 - Транспонувати матрицю B\n");
        printf("3 - Знайти матричний добуток C = A * B\n");
        printf("4 - Відсортувати матрицю A за зростанням\n");
        printf("5 - Вивести суми рядків A та стовпців B\n");
        printf("6 - Показати поточні матриці A та B\n");
        printf("0 - Вихід\n");
        printf("Оберіть дію: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int max_a, min_a;
                max_min(A, n_a, &max_a, &min_a);
                printf("\nВище головної діагоналі матриці A:\n");
                printf("Максимум = %d\nМінімум  = %d\n\n", max_a, min_a);
                break;
            }
            case 2: {
                int **B_T = transpose_b(B, n_b, m_b);
                if (B_T != NULL) {
                    print_matrix(B_T, m_b, n_b, "B^T (транспонована)");
                    clear_memory(B_T, m_b);
                }
                break;
            }
            case 3: {
                int **C = mult_a_b(B, n_b, m_b, A, n_a);
                if (C != NULL) {
                    print_matrix(C, n_a, m_b, "C = A * B");
                    clear_memory(C, n_a);
                }
                break;
            }
            case 4: {
                int sort_mode;
                printf("\n1 - Сортувати всю матрицю A\n");
                printf("2 - Сортувати лише обраний рядок матриці A\n");
                printf("Ваш вибір: ");
                scanf("%d", &sort_mode);

                if (sort_mode == 1) {
                    sort_matrix(A, n_a, -1);
                    print_matrix(A, n_a, n_a, "A (відсортована повністю)");
                } else if (sort_mode == 2) {
                    int row;
                    printf("Введіть номер рядка (0..%d): ", n_a - 1);
                    scanf("%d", &row);
                    if (row >= 0 && row < n_a) {
                        sort_matrix(A, n_a, row);
                        print_matrix(A, n_a, n_a, "A (відсортований рядок)");
                    } else {
                        printf("Некоректний номер рядка!\n\n");
                    }
                } else {
                    printf("Некоректний вибір!\n\n");
                }
                break;
            }
            case 5: {
                print_sums(A, n_a, B, n_b, m_b);
                break;
            }
            case 6: {
                print_matrix(A, n_a, n_a, "A");
                print_matrix(B, n_b, m_b, "B");
                break;
            }
            case 0:
                printf("Завершення роботи програми...\n");
                break;
            default:
                printf("Невірний пункт меню. Спробуйте ще раз.\n\n");
        }
    } while (choice != 0);

    // Обов'язкове звільнення пам'яті
    clear_memory(A, n_a);
    clear_memory(B, n_b);

    return 0;
}