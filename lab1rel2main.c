#include <stdio.h>
#include <stdlib.h>

//------Макровизначееня-----------
#define Name "Yehor"
#define LastName "Redko"
#define GroupName "RB-61"
#define Faculty "RTF"
#define University "Igor Sikorsky Kyiv Polytechnic Institute"

//-----------Це початок программи------------------
int main()
{
//---------------Оголошення цілочисельних змінних---------------
    unsigned int semestr;
    unsigned int age;
//-------Оголошення плаваючих змінних-----------
    float admissionScore;
    double averageGrade;

//-----------Змінні цілочисельні------------
    int grade1;
    int grade2;
    int grade3;
    int grade4;
    int grade5;


//---------Виведення імені та прізвища, запити на ввід змінних---------
    printf("%s %s Enter following data.\n", Name, LastName);

    printf("Enter semestr: ");
    scanf("%u", &semestr);

    printf("Enter your admission score: ");
    scanf("%f", &admissionScore);

    printf("Enter grade #1: ");
    scanf("%d", &grade1);

    printf("Enter grade #2: ");
    scanf("%d", &grade2);

    printf("Enter grade #3: ");
    scanf("%d", &grade3);

    printf("Enter grade #4: ");
    scanf("%d", &grade4);

    printf("Enter grade #5: ");
    scanf("%d", &grade5);

    printf("Enter your age: ");
    scanf("%u", &age);

//----------------Вирахування середнього балу за формулою--------------------
    averageGrade = (double)(grade1 + grade2 + grade3 + grade4 + grade5) / 5;

//----------Очищення вікна консолі------------
    system("cls");

//------Виведення розділювачів і введеної інформації------------
    printf("\n-------------------------");
    printf("\n*************************\n");
    printf("%s", University);
    printf("\n%s", Faculty);
    printf("\n%s", GroupName);
    printf("\n-------------------------");
    printf("\nstudent: %s %s", Name, LastName);
    printf("\nage: %u", age);
    printf("\nsemestr: %u", semestr);
    printf("\n-------------------------");
    printf("\nadmission score: %.1f", admissionScore);
    printf("\naverage grade = %.2lf", averageGrade);
    printf("\n");

//----------Завершення main----------
    return 0;
}


