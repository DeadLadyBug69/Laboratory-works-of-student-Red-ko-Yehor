#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//---------Максимальний розмір матриці-----------
#define MAX 20 

//------------Функція друку матриці----------------
void print_mat(int a[MAX][MAX], int r, int c)
 {
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) printf("%4d", a[i][j]);
        printf("\n");
    }
}

//------------Кількість рядків, де є нуль---------------
int get_zero_rows(int a[MAX][MAX], int r, int c) 
{
    int count = 0;
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++)
         {
            if (a[i][j] == 0) 
            { 
                count++; 
                break; //-----------Якщо нуль знайдено, то перехід на новий рядок
            }
        }
    }
    return count;
}

//---------Пошук рядка з найдовшою серією повторок----------
int get_longest_series(int a[MAX][MAX], int r, int c) 
{
    int max_len = 1; //-----------Максимальна знайдена серія
    int row = -1;    //-----------Номер рядка (поки немає)

    for (int i = 0; i < r; i++)
     {
        int len = 1; //-----------Довжина поточної серії
        for (int j = 0; j < c - 1; j++)
         {
            if (a[i][j] == a[i][j + 1]) len++; //--------Якщо сусіди однакові - ++
            else len = 1;                      //--------Якщо різні - вертаємо до початку
            
            if (len > max_len) //----------Якщо серія стала більше за її попереднє макс. значення
            { 
                max_len = len;
                row = i;
            }
        }
    }
    return row;
}

//---------Початок головної програми---------
int main() 
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int a[MAX][MAX], r, c;

    printf("Введи к-сть рядків,стовпців: ");
    scanf("%d %d", &r, &c);

    printf("Введи значення:\n");
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++)
         {
            scanf("%d", &a[i][j]);
        }
    }

    system("cls"); //----------Очищення екрана------------

    printf("Матриця:\n");
    print_mat(a, r, c);

    //---------Виведення результатів--------------
    printf("\nРядків з 0: %d\n", get_zero_rows(a, r, c));
    
    int row_idx = get_longest_series(a, r, c);
    if (row_idx != -1) printf("Найдовша серія однакових в рядку: %d\n", row_idx +1);
    else printf("Немає серій.\n");

    getch();
    return 0;
}