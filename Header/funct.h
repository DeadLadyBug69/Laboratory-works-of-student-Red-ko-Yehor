#ifndef FUNCT_H
#define FUNCT_H

/**
 * @brief Обчислює значення підінтегральної функції f(x) = 1 / (1.1 + x)^2.
 *
 * @param x Точка, у якій обчислюється значення функції.
 * @return Значення функції f(x) у точці x.
 */
double f(double x);

/**
 * @brief Наближене обчислення інтеграла методом лівих прямокутників.
 */
double left_rect(double a, double b, int n);

/**
 * @brief Наближене обчислення інтеграла методом правих прямокутників.
 */
double right_rect(double a, double b, int n);

/**
 * @brief Наближене обчислення інтеграла методом трапецій.
 */
double trapezoid(double a, double b, int n);

/**
 * @brief Наближене обчислення інтеграла методом парабол (Сімпсона).
 */
double simpson(double a, double b, int n);

/**
 * @brief Обчислює визначений інтеграл обраним методом із заданою точністю.
 *
 * @details Реалізує ітераційний процес (правило Рунге) для підбору кількості розбиттів.
 *          Автоматично зупиняє розрахунок при досягненні ліміту ітерацій.
 *
 * @param method_choice Номер методу (1-Ліві, 2-Праві, 3-Трапеції, 4-Сімпсон).
 * @param a             Ліва межа інтегрування.
 * @param b             Права межа інтегрування.
 * @param n_start       Початкова кількість розбиттів.
 * @param eps           Задана точність (критерій зупинки).
 * @param max_iter      Максимальна кількість ітерацій (запобіжник від зациклення).
 */
void solve_integral(int method_choice, double a, double b, int n_start, double eps, int max_iter);

#endif // FUNCT_H