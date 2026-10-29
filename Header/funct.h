#ifndef FUNCT_H
#define FUNCT_H

#define MAX 100 // Максимальний розмір масиву

/**
 * @brief Структура для зберігання масиву та його фактичного розміру.
 */
typedef struct {
    int n;           // Кількість елементів
    double a[MAX];   // Статичний масив
} LabData;

/**
 * @brief Виводить поточний стан масиву на екран.
 */
void print_arr(double a[], int n);

/**
 * @brief Обчислює математичне сподівання (середнє значення).
 */
double get_Mx(double a[], int n);

/**
 * @brief Обчислює дисперсію вибірки.
 */
double get_Dx(double a[], int n, double Mx);

/**
 * @brief Впорядковує масив за зростанням (алгоритм обміну/бульбашки).
 */
void bubble_sort(double a[], int n);

#endif // FUNCT_H