#include <stdio.h>
#include <stdlib.h>

#define Name "Mykola"
#define LastName "Ivanenko"
#define GroupName "GP-13"
#define Faculty "FFF"
#define University "Igor Sikorsky Kyiv Polytechnic Institute"

int main()
{
    //--Оголошення змінних. Цілочисельна. Без знаку.
    unsigned int semestr;
    unsigned int age;
    //--Оголошення змінних. Цілочисельна. Знакова.
    int grade1;
    int grade2;
    int grade3;
    //--Оголошення змінних. Плаваюч. кома.
    double averageGrade;
    float admissionScore;

    //--
    printf("%s %s Enter following data.\n", Name, LastName);

    //--Ініц. змінних
    age = 12;
    grade1 = 5;
    grade2 = 4;
    grade3 = 3;

    averageGrade = (double)(grade1 + grade2 + grade3) / 3;


    printf("Enter semestr:");
    scanf("%u", &semestr);

    printf("\nsemestr: %u", semestr);
    printf("\naverage grade = %.3lf\n", averageGrade);
    printf("Hello world!\n");
    return 0;
}
