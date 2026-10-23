#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//------Максимальний розмір масиву---------
#define MAX 100 

//--------Функція друку масиву------------
void print_arr(double a[], int n)
 {
    for (int i = 0; i < n; i++) printf("%.2lf ", a[i]);
    printf("\n");
}

//---------Розрахунок середнього (Mx)------------
double get_Mx(double a[], int n) 
{
    double s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s / n;
}

//----------Розрахунок дисперсії (Dx)------------
double get_Dx(double a[], int n, double Mx)
{
    double s = 0;
    for (int i = 0; i < n; i++) s += pow(a[i] - Mx, 2);
    return s / (n - 1);
}

//---------Сортування бульбашкою (за зростанням)----------
void bubble_sort(double a[], int n) 
{
    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                double t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

//----------Головна програма--------------
int main() 
{
    double a[MAX];
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    //-----------Введення масиву-------------
    for (int i = 0; i < n; i++) 
    {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

//-------------Очищення екрана--------------
    system("cls"); 

    printf("Initial: ");
    print_arr(a, n);

    //-----------Обчислення статистики--------------
    double Mx = get_Mx(a, n);
    double Dx = get_Dx(a, n, Mx);

    //----------------Сортування-----------------
    bubble_sort(a, n);

    printf("Sorted:  ");
    print_arr(a, n);

    //-----------Виведення результатів єдиним блоком-------------
    //-------Мінімум — це a[0], максимум — a[n-1], оскільки масив уже відсортовано-------2
    
    printf("\n--- Results ---\nMx = %.4lf\nDx = %.4lf\nSigma = %.4lf\nMin = %.2lf\nMax = %.2lf\n", 
           Mx, Dx, sqrt(Dx), a[0], a[n - 1]);

    getch();
    return 0;
}
