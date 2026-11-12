#ifndef FUNCT_H
#define FUNCT_H

/**
 * @brief Заповнює масив A значеннями за формулою: A[j] = Size - (j + 1).
 * 
 * @param A Вказівник на динамічний масив типу unsigned int.
 * @param Size Розмір масиву.
 */
void fill_int_array(unsigned int *A, unsigned int Size);

/**
 * @brief Заповнює масив B значеннями за формулою: B[j] = 5.0 * j + 5.0.
 * 
 * @param B Вказівник на динамічний масив типу float.
 * @param Size Розмір масиву.
 */
void fill_float_array(float *B, unsigned int Size);

/**
 * @brief Виводить масив A у консоль.
 * 
 * @param A Вказівник на константний масив типу unsigned int.
 * @param Size Розмір масиву.
 */
void print_int_array(const unsigned int *A, unsigned int Size);

/**
 * @brief Виводить масив B у консоль.
 * 
 * @param B Вказівник на константний масив типу float.
 * @param Size Розмір масиву.
 */
void print_float_array(const float *B, unsigned int Size);

/**
 * @brief Обчислює середнє значення елементів масиву A.
 * 
 * @param A Вказівник на константний масив типу unsigned int.
 * @param Size Розмір масиву.
 * @return Середнє значення елементів масиву.
 */
double mean_value(const unsigned int *A, unsigned int Size);

/**
 * @brief Знаходить мінімальне значення в масиві A.
 * 
 * @param A Вказівник на константний масив типу unsigned int.
 * @param Size Розмір масиву.
 * @return Мінімальне значення.
 */
unsigned int find_min(const unsigned int *A, unsigned int Size);

/**
 * @brief Знаходить максимальне значення в масиві B.
 * 
 * @param B Вказівник на константний масив типу float.
 * @param Size Розмір масиву.
 * @return Максимальне значення.
 */
float find_max(const float *B, unsigned int Size);

#endif // FUNCT_H