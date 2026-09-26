#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//---------Підінтегральна функція 1 / (1.1 + x)^2 ------------
double integrand_expression(double x)
 {
    return 1.0 / pow(1.1 + x, 2.0);
}

//---------------------Метод лівих прямокутників-----------------------
double num_comput_integral_l_re(double a, double b, unsigned int n)
 {
    double h = (b - a) / (double)n, s = 0.0;
    for (unsigned int i = 0; i < n; i++) s += integrand_expression(a + i * h);
    return s * h;
}

//----------------------Метод правих прямокутників------------------------
double num_comput_integral_r_re(double a, double b, unsigned int n) 
{
    double h = (b - a) / (double)n, s = 0.0;
    for (unsigned int i = 1; i <= n; i++) s += integrand_expression(a + i * h);
    return s * h;
}

//--------------------------------Метод трапецій-----------------------------------
double num_comput_integral_trap(double a, double b, unsigned int n) 
{
    double h = (b - a) / (double)n, s = 0.0;
    for (unsigned int i = 1; i < n; i++) s += integrand_expression(a + i * h);
    return (h / 2.0) * (integrand_expression(a) + integrand_expression(b) + 2.0 * s);
}

//--------------------------------Метод парабол-------------------------------
double num_comput_integral_parabolas(double a, double b, unsigned int n) 
{
    if (n % 2 != 0) n++; //---------парна кількість проміжків
    double h = (b - a) / (double)n, s_odd = 0.0, s_even = 0.0;
    for (unsigned int i = 1; i < n; i += 2) s_odd += integrand_expression(a + i * h);
    for (unsigned int i = 2; i < n; i += 2) s_even += integrand_expression(a + i * h);
    return (h / 3.0) * (integrand_expression(a) + integrand_expression(b) + 4.0 * s_odd + 2.0 * s_even);
}

int main()
 {
    double left_boundary_a, right_boundary_b, measurement_error;
    double I1, I2, delta;
    unsigned int intervals;
    int var;

    printf("\n\tEnter the left boundary \n X(first)= ");
    scanf("%lf", &left_boundary_a);

    printf("\n\tEnter the right boundary \n X(last)= ");
    scanf("%lf", &right_boundary_b);

    do 
    {
        printf("\n\tEnter the number of intervals (N>0)\n N= ");
        scanf("%u", &intervals);
    } 
    while (intervals <= 0);

    printf("\n\tEnter the measurement error of integration\n Measurement error= ");
    scanf("%lf", &measurement_error);

    do 
    {
        printf("\nChoose the method:\n");
        printf("\t1. By Left Rectangles:\n");
        printf("\t2. By Right Rectangles:\n");
        printf("\t3. By Trapetions method:\n");
        printf("\t4. By Parabola method:\n");
        printf("(1-4): ");
        scanf("%d", &var);

        if (var < 1 || var > 4) printf("\n Not right.\n");
    } 
    while (var < 1 || var > 4);

    system("cls");

    //--------------------Вказівник на обраний метод------------------------
    double (*calc_method)(double, double, unsigned int) = NULL;

    switch (var) 
    {
        case 1:
            printf("\n\n\t*Left Rectangles method*\n");
            calc_method = num_comput_integral_l_re;
            break;
        case 2:
            printf("\n\n\t*Right Rectangles method*\n");
            calc_method = num_comput_integral_r_re;
            break;
        case 3:
            printf("\n\n\t*Trapetions method*\n");
            calc_method = num_comput_integral_trap;
            break;
        case 4:
            printf("\n\n\t*Parabola method*\n");
            calc_method = num_comput_integral_parabolas;
            break;
    }
    //--------------цикл підбору N за точністю (|I1 - I2| <= eps)-------------
    while (1) 
    {
        I1 = calc_method(left_boundary_a, right_boundary_b, intervals);
        I2 = calc_method(left_boundary_a, right_boundary_b, intervals + 2);
        delta = fabs(I1 - I2);
        if (delta <= measurement_error || intervals > 500000) break;
        intervals += 2;
    }

    //--------------------Підсумковий вивід-------------------------------
    printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %u\n\tDelta = %.8lf",
           left_boundary_a, right_boundary_b, I2, intervals, delta);

    printf("\n\nPress any key to finish the program.");
    getch();

    return 0;
}