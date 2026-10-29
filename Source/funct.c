#include <stdio.h>
#include <math.h>

#include "funct.h"

void print_arr(double a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    printf("\n");
}

double get_Mx(double a[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s / n;
}

double get_Dx(double a[], int n, double Mx) {
    double s = 0;
    // Запобіжник ділення на нуль для масиву з 1 елемента
    if (n <= 1) return 0; 
    for (int i = 0; i < n; i++) s += pow(a[i] - Mx, 2);
    return s / (n - 1);
}

void bubble_sort(double a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                double t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}