#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//-------Підінтегральна функція-------------
double f(double x)
 {
    return 1.0 / pow(1.1 + x, 2.0);
}

//---------Метод лівих прямокутників-----------
double left_rect(double a, double b, int n)
 {
    double h = (b - a) / n, s = 0;
    for (int i = 0; i < n; i++) s += f(a + i * h);
    return s * h;
}

//----------Метод правих прямокутників------------
double right_rect(double a, double b, int n)
{
    double h = (b - a) / n, s = 0;
    for (int i = 1; i <= n; i++) s += f(a + i * h);
    return s * h;
}

//--------Метод трапецій--------------
double trapezoid(double a, double b, int n) 
{
    double h = (b - a) / n, s = 0;
    for (int i = 1; i < n; i++) s += f(a + i * h);
    return (h / 2.0) * (f(a) + f(b) + 2.0 * s);
}

//----------Метод парабол (Сімпсона)------------
double simpson(double a, double b, int n) 
{
    if (n % 2 != 0) n++; //------Робимо n парним------------
    double h = (b - a) / n, s_odd = 0, s_even = 0;
    for (int i = 1; i < n; i += 2) s_odd += f(a + i * h);
    for (int i = 2; i < n; i += 2) s_even += f(a + i * h);
    return (h / 3.0) * (f(a) + f(b) + 4.0 * s_odd + 2.0 * s_even);
}
//--------Головна програма--------------
int main() 
{
    double a, b, eps, I1, I2, delta;
    int n, method;

    //---------Введення базових даних--------------------
    printf("Enter limits [a, b], N(>0), and error (eps):\n> ");
    scanf("%lf %lf %d %lf", &a, &b, &n, &eps);

    //-----------Захист від неправильного вибору методу------------
    do
     {
        printf("\nChoose method (1-Left, 2-Right, 3-Trap, 4-Parab): ");
        scanf("%d", &method);
    } 
    while (method < 1 || method > 4);

    system("cls");

    //------------Вказівник на обрану функцію-----------
    double (*calc)(double, double, int) = NULL;
    switch (method)
     {
        case 1: calc = left_rect; break;
        case 2: calc = right_rect; break;
        case 3: calc = trapezoid; break;
        case 4: calc = simpson; break;
    }

    //-----------Цикл підбору точності (Рунге)-------------
    while (1) 
    {
        I1 = calc(a, b, n);
        I2 = calc(a, b, n + 2);
        delta = fabs(I1 - I2);
        if (delta <= eps || n > 500000) break;
        n += 2;
    }

    //-----------Фінальний вивід---------------
    printf("RESULTS:\n");
    printf("a = %.2lf, b = %.2lf\n", a, b);
    printf("Integral = %.8lf\n", I2);
    printf("N = %d\n", n + 2);
    printf("Delta = %.8lf\n", delta);

    printf("\nPress any key to finish the program...");
    getch();
    return 0;
}
