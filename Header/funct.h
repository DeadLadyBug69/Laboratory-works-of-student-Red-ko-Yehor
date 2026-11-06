#ifndef FUNCT_H
#define FUNCT_H

/**
 * @brief Обчислює значення нелінійної функції f(x)
 */
double f(double x);

/**
 * @brief Обчислює значення першої похідної f'(x)
 */
double f_prime(double x);

/**
 * @brief Обчислює значення другої похідної f''(x)
 */
double f_double_prime(double x);

/**
 * @brief Знаходить корінь рівняння методом половинного ділення.
 * 
 * @param debug Прапорець налагодження (1 - виводити кроки, 0 - приховати).
 */
void solve_bisection(double a, double b, double eps, int max_iter, int debug);

/**
 * @brief Знаходить корінь рівняння методом хорд.
 * 
 * @param debug Прапорець налагодження (1 - виводити кроки, 0 - приховати).
 */
void solve_chord(double a, double b, double eps, int max_iter, int debug);

#endif // FUNCT_H
