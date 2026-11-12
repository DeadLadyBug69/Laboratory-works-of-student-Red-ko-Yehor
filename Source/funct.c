#include <stdio.h>
#include "funct.h"

// Функція для заповнення масиву A
void fill_int_array(unsigned int *A, unsigned int Size) {
    for (unsigned int j = 0; j < Size; j++) {
        A[j] = Size - (j + 1);
    }
}

// Функція для заповнення масиву B
void fill_float_array(float *B, unsigned int Size) {
    for (unsigned int j = 0; j < Size; j++) {
        B[j] = 5.0f * j + 5.0f;
    }
}

// Функція для виведення масиву A
void print_int_array(const unsigned int *A, unsigned int Size) {
    printf("\nМасив A (unsigned int):\n");
    for (unsigned int j = 0; j < Size; j++) {
        printf("%5u", A[j]);
    }
    printf("\n");
}

// Функція для виведення масиву B
void print_float_array(const float *B, unsigned int Size) {
    printf("\nМасив B (float):\n");
    for (unsigned int j = 0; j < Size; j++) {
        printf("%7.2f", B[j]);
    }
    printf("\n\n");
}

// Функція пошуку середнього значення в масиві A
double mean_value(const unsigned int *A, unsigned int Size) {
    double sum = 0.0;
    for (unsigned int j = 0; j < Size; j++) {
        sum += A[j];
    }
    return sum / Size;
}

// Функція пошуку мінімального значення в масиві A
unsigned int find_min(const unsigned int *A, unsigned int Size) {
    unsigned int min = A[0];
    for (unsigned int j = 1; j < Size; j++) {
        if (A[j] < min) {
            min = A[j];
        }
    }
    return min;
}

// Функція пошуку максимального значення в масиві B
float find_max(const float *B, unsigned int Size) {
    float max = B[0];
    for (unsigned int j = 1; j < Size; j++) {
        if (B[j] > max) {
            max = B[j];
        }
    }
    return max;
}