#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    int variant;
    double X1, X2, delta, x, y;
    unsigned int N;
    unsigned int i;
    double mynule_y;

    //-------Меню вибору режиму введення--------
    do
    {
        printf("Select variant:\n");
        printf("1 - X1, X2 and point quantity N\n");
        printf("2 - X1, X2 and step quantity delta\n");
        printf("1 or 2: ");
        scanf("%d", &variant);

        if (variant != 1 && variant != 2)
        {
            printf("Error! Chose only 1 or 2.\n\n");
        }
    } 
    while (variant != 1 && variant != 2);

    //---------Введення меж-----------
    printf("\nX1: ");
    scanf("%lf", &X1);
    printf("X2: ");
    scanf("%lf", &X2);

    //---------Розрахунок delta або N----------
    if (variant == 1)
    {
        printf("N: ");
        scanf("%u", &N);
        delta = (X2 - X1) / (N - 1);
    }
    else
    {
        printf("delta: ");
        scanf("%lf", &delta);
        N = (unsigned int)((X2 - X1) / delta) + 1;
    }

    system("cls");

    //----------Параметри та шапка таблиці--------------
    printf("X1=%.2lf,  X2=%.2lf,  delta=%.2lf,  N=%u\n\n", X1, X2, delta, N);
    printf("+-------+-----------------------------+-------------------+\n");
    printf("|   N   |              X              |       F(X)        |\n");
    printf("+-------+-----------------------------+-------------------+\n");

    //-----------Табулювання та перевірка зміни знаку в одному циклі---------------
    for (i = 1; i <= N; i++)
    {
        x = X1 + (i - 1) * delta;
        y = pow((x + 10.0) / 100.0, 3.0) - 10.0 * sin(x + 10.0) + 12.0;

        printf("|%7u|%29lf|%19lf|\n", i, x, y);
        printf("+-------+-----------------------------+-------------------+\n");

        //---------Якщо знак змінився порівняно з попередньою точкою----------------
        if (i > 1)
        {
            if ((mynule_y < 0 && y > 0) || (mynule_y > 0 && y < 0))
            {
                printf("Promizhok izoliacii korenia: [%.2lf ; %.2lf]\n", x - delta, x);
                printf("+-------+-----------------------------+-------------------+\n");
            }
        }
        mynule_y = y;

        //------Посторінкова зупинка кожні 10 рядків--------
        if (i % 10 == 0 && i < N)
        {
            if (i == 10)
            {
                printf("Press Any Key to Continue ... ");
                getch();
                printf("\r                              \r");
            }
            else
            {
                getch();
            }
        }
    }

    printf("\nPress any key to finish the program.");
    getch();

    return 0;
}
