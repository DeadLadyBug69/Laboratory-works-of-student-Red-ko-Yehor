#include "../Header/funct.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    // Оголошення змінних
    double x1, x2, delta;
    unsigned int N;
    char group[20] = "";
    char name[100] = "";

    FILE* input_data_file;

    // Спроба відкрити текстовий файл із вхідними даними для читання
    if ((input_data_file = fopen("../Texts/input.txt", "r")) != NULL) {
        // Зчитування числових параметрів: початок, кінець, кількість точок, крок
        fscanf(input_data_file, "%lf", &x1);
        fscanf(input_data_file, "%lf", &x2);
        fscanf(input_data_file, "%u", &N);
        fscanf(input_data_file, "%lf", &delta);

        // Зчитування рядкових даних: групи та імені
        fscanf(input_data_file, "%19s", group);
        fscanf(input_data_file, " %99[^\r\n]", name);

        fclose(input_data_file);
    } else {
        printf("Error! File cannot be opened 1\n");
        return 1;
    }

    // Контрольний вивід зчитаних даних у консоль для перевірки
    printf("x1: %lf\n", x1);
    printf("x2: %lf\n", x2);
    printf("N: %u\n", N);
    printf("delta: %lf\n", delta);
    printf("Group: %s\n", group);
    printf("Name: %s\n", name);

    // Створення текстової таблиці та збереження її у файл
    print_output_data(x1, x2, N, delta, group, name);

    // Запис результатів обчислень у бінарний файл
    write_bin_file(x1, x2, N, delta);

    // Зчитування та вивід даних з бінарного файлу на екран
    print_bin_data();

    return 0;
}