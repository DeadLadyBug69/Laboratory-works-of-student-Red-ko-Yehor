#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//-------------максимальний розмір масиву-----------------
#define MAX 100

//------------підпрограми-функцій------------------------


//----------Функція друку масиву--------------------
void print_arr(double a[], int n)
 {
    for (int i = 0; i < n; i++) printf("%.2lf ", a[i]);
    printf("\n");
}

//---------Функція розрахунку середнього значення (Mx)
double get_mean(double a[], int n)
 {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return sum / n;
}

//------------Функція розрахунку дисперсії (Dx)--------------
double get_disp(double a[], int n, double mean) 
{
    double sum = 0;
    for (int i = 0; i < n; i++) sum += pow(a[i] - mean, 2);
    return sum / (n - 1);
}

//-----------Функція сортування бульбашкою (за зростанням)------------------
void bubble_sort(double a[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (a[j] > a[j + 1])
             {
                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//-----------------Основна програма----------------------------
int main() 
{
    double a[MAX];
    int n;

    //----------Введеня розміру масиву-------------
    printf("Enter size N: ");
    scanf("%d", &n);

    //-------------Заповнення масиву даними----------------
    for (int i = 0; i < n; i++)
     {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    system("cls");

    //----------виведення початкового масиву-------------
    printf("Initial array:\n");
    print_arr(a, n);

    //------------Розрахунок середнє, сігма, дисперсія
    double mean = get_mean(a, n);
    double disp = get_disp(a, n, mean);
    double sigma = sqrt(disp);

    //--------Бульбашкове сортування--------
    bubble_sort(a, n);

    printf("\nSorted:\n");
    print_arr(a, n);

    // ---------Виведення результатів---------
    //--------Оскільки масив відсортовано за зростанням a[0] автоматично є мінімумом, a[n - 1] - максимумом
    printf("\nResults\n");
    printf("Mean (Mx)      = %.4lf\n", mean);
    printf("Dispersion     = %.4lf\n", disp);
    printf("Sigma          = %.4lf\n", sigma);
    printf("Min element    = %.2lf\n", a[0]);
    printf("Max element    = %.2lf\n", a[n - 1]);

    //--------Завершення програми-----------
    printf("\nPress any key to exit...");
    getch();

    return 0;
}