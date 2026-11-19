/**
 * @file funct.h
 * @brief Заголовний файл з оголошенням функцій для роботи з двовимірними динамічними матрицями (ЛР 4.2, Варіант 13).
 */

#ifndef FUNCT_H
#define FUNCT_H

/**
 * @brief Виділяє динамічну пам'ять для двовимірної матриці.
 * 
 * @param rows Кількість рядків.
 * @param cols Кількість стовпців.
 * @return int** Вказівник на виділену матрицю.
 */
int **memory_allocation(int rows, int cols);

/**
 * @brief Звільняє динамічну пам'ять, виділену під матрицю.
 * 
 * @param matrix Вказівник на матрицю.
 * @param rows   Кількість рядків.
 */
void clear_memory(int **matrix, int rows);

/**
 * @brief Заповнює матрицю обраним способом (клавіатура, рандом або формула i + j).
 * 
 * @param matrix Вказівник на матрицю.
 * @param rows   Кількість рядків.
 * @param cols   Кількість стовпців.
 * @param mode   Спосіб заповнення (1 - клавіатура, 2 - рандом, 3 - формула).
 */
void fill_matrix(int **matrix, int rows, int cols, int mode);

/**
 * @brief Виводить матрицю у консоль із вирівнюванням стовпців.
 * 
 * @param matrix Вказівник на матрицю.
 * @param rows   Кількість рядків.
 * @param cols   Кількість стовпців.
 * @param name   Назва матриці для заголовка.
 */
void print_matrix(int **matrix, int rows, int cols, const char *name);

/**
 * @brief Знаходить максимальний та мінімальний елементи матриці A вище головної діагоналі (Варіант 13).
 * 
 * @param A     Квадратна матриця A.
 * @param n_a   Розмірність матриці A.
 * @param max_a Вказівник для збереження максимуму.
 * @param min_a Вказівник для збереження мінімуму.
 */
void max_min(int **A, int n_a, int *max_a, int *min_a);

/**
 * @brief Транспонує матрицю B.
 * 
 * @param B   Початкова матриця B розміром n_b x m_b.
 * @param n_b Кількість рядків матриці B.
 * @param m_b Кількість стовпців матриці B.
 * @return int** Нова транспонована матриця розміром m_b x n_b.
 */
int **transpose_b(int **B, int n_b, int m_b);

/**
 * @brief Обчислює матричний добуток C = A * B.
 * 
 * @param B   Матриця B.
 * @param n_b Кількість рядків B.
 * @param m_b Кількість стовпців B.
 * @param A   Квадратна матриця A.
 * @param n_a Розмірність матриці A.
 * @return int** Матриця-результат C розміром n_a x m_b.
 */
int **mult_a_b(int **B, int n_b, int m_b, int **A, int n_a);

/**
 * @brief Сортує за зростанням усю матрицю A (якщо row == -1) або обраний рядок (якщо row >= 0).
 * 
 * @param A   Матриця A.
 * @param n_a Розмірність матриці A.
 * @param row Індекс рядка (0..n_a-1) або -1 для сортування всієї матриці.
 */
void sort_matrix(int **A, int n_a, int row);

/**
 * @brief Виводить суму елементів кожного рядка матриці A та кожного стовпця матриці B.
 * 
 * @param A   Матриця A.
 * @param n_a Розмірність A.
 * @param B   Матриця B.
 * @param n_b Кількість рядків B.
 * @param m_b Кількість стовпців B.
 */
void print_sums(int **A, int n_a, int **B, int n_b, int m_b);

#endif // FUNCT_H
