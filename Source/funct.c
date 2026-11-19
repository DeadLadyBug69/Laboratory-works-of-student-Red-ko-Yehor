#include <stdio.h>
#include <stdlib.h>
#include "funct.h"

int **memory_allocation(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            clear_memory(matrix, i);
            return NULL;
        }
    }
    return matrix;
}

void clear_memory(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(int **matrix, int rows, int cols, int mode) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mode == 1) {
                printf("Елемент [%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            } else if (mode == 2) {
                matrix[i][j] = rand() % 21; // Випадкові числа від 0 до 20
            } else {
                matrix[i][j] = i + j;       // Формула A[i][j] = i + j
            }
        }
    }
}

void print_matrix(int **matrix, int rows, int cols, const char *name) {
    printf("\nМатриця %s (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void max_min(int **A, int n_a, int *max_a, int *min_a) {
    *max_a = A[0][1];
    *min_a = A[0][1];

    // Шукаємо вище головної діагоналі (j > i)
    for (int i = 0; i < n_a; i++) {
        for (int j = i + 1; j < n_a; j++) {
            if (A[i][j] > *max_a) {
                *max_a = A[i][j];
            }
            if (A[i][j] < *min_a) {
                *min_a = A[i][j];
            }
        }
    }
}

int **transpose_b(int **B, int n_b, int m_b) {
    int **B_T = memory_allocation(m_b, n_b);
    if (B_T == NULL) return NULL;

    for (int i = 0; i < n_b; i++) {
        for (int j = 0; j < m_b; j++) {
            B_T[j][i] = B[i][j];
        }
    }
    return B_T;
}

int **mult_a_b(int **B, int n_b, int m_b, int **A, int n_a) {
    if (n_a != n_b) return NULL;

    int **C = memory_allocation(n_a, m_b);
    if (C == NULL) return NULL;

    for (int i = 0; i < n_a; i++) {
        for (int j = 0; j < m_b; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n_a; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void sort_matrix(int **A, int n_a, int row) {
    if (row == -1) {
        int total = n_a * n_a;
        for (int i = 0; i < total - 1; i++) {
            for (int j = 0; j < total - i - 1; j++) {
                int r1 = j / n_a, c1 = j % n_a;
                int r2 = (j + 1) / n_a, c2 = (j + 1) % n_a;
                if (A[r1][c1] > A[r2][c2]) {
                    int temp = A[r1][c1];
                    A[r1][c1] = A[r2][c2];
                    A[r2][c2] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < n_a - 1; i++) {
            for (int j = 0; j < n_a - i - 1; j++) {
                if (A[row][j] > A[row][j + 1]) {
                    int temp = A[row][j];
                    A[row][j] = A[row][j + 1];
                    A[row][j + 1] = temp;
                }
            }
        }
    }
}

void print_sums(int **A, int n_a, int **B, int n_b, int m_b) {
    printf("\nСуми елементів рядків матриці A:\n");
    for (int i = 0; i < n_a; i++) {
        int sum = 0;
        for (int j = 0; j < n_a; j++) {
            sum += A[i][j];
        }
        printf("Рядок %2d: %d\n", i, sum);
    }

    printf("\nСуми елементів стовпців матриці B:\n");
    for (int j = 0; j < m_b; j++) {
        int sum = 0;
        for (int i = 0; i < n_b; i++) {
            sum += B[i][j];
        }
        printf("Стовпець %2d: %d\n", j, sum);
    }
    printf("\n");
}
