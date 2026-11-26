#include "../Header/funct.h"

double calc_func(double x) {
    // Функція Варіанта 13 (ЛР 1): (x - 10)^3 * sin((x + 10) / 100) - 10x + 12
    return pow(x - 10.0, 3) * sin((x + 10.0) / 100.0) - 10.0 * x + 12.0;
}

char* make_table(double x1, double x2, unsigned int N, double delta) {
    // Перевірка на мінімально необхідну кількість точок для побудови таблиці
    if (N < 2) {
        printf("Кількість точок повинна бути не менше 2!\n");
        return NULL;
    }

    // Виділення достатнього обсягу пам'яті для збереження текстової таблиці
    char *result = (char *)malloc(N * 120 + 256);
    if (result == NULL) {
        printf("Помилка виділення пам'яті для таблиці!\n");
        return NULL;
    }

    // Копіювання початкового заголовка таблиці у виділену пам'ять
    strcpy(result, "*****************************************\n*     N    *     X      *     F(X)      *\n*****************************************");

    // Цикл для проходу по всіх N точках
    for (unsigned int i = 1; i <= N; i++) {
        char temp[120];
        double func = calc_func(x1);

        // Зупинка обчислень, якщо поточний x вийшов за межі кінцевого значення інтервалу
        if (x1 > x2 + 1e-9) break;

        strcat(result, "\n+----------+------------+---------------+");
        sprintf(temp, "\n|%10u|%12.2lf|%15.2lf|", i, x1, func);
        strcat(result, temp);

        x1 += delta;
    }

    strcat(result, "\n+----------+------------+---------------+\n");
    return result;
}

void print_output_data(double x1, double x2, unsigned int N, double delta, char* group, char* name) {
    FILE* output_file;

    // Спроба відкрити або створити текстовий файл для запису
    if ((output_file = fopen("../Texts/output_data.txt", "w")) != NULL) {
        char *table = make_table(x1, x2, N, delta);
        if (table != NULL) {
            fprintf(output_file, "%s", table);
            free(table);
        }

        // Запис додаткової інформації (група та ім'я)
        fprintf(output_file, "Group: %s\n", group);
        fprintf(output_file, "Name: %s\n", name);

        fclose(output_file);
    } else {
        printf("Error! File cannot be opened 2\n");
    }
}

void write_bin_file(double x1, double x2, unsigned int N, double delta) {
    FILE* bin_file;

    // Спроба відкрити бінарний файл для запису
    if ((bin_file = fopen("../Texts/bin_file.bin", "wb")) != NULL) {
        // Підрахунок реальної кількості точок у межах [x1, x2]
        unsigned int count = 0;
        double cur_x = x1;
        for (unsigned int j = 0; j < N; j++) {
            if (cur_x > x2 + 1e-9) break;
            count++;
            cur_x += delta;
        }

        // Спочатку записуємо кількість розрахункових точок
        fwrite(&count, sizeof(unsigned int), 1, bin_file);

        // Цикл для обчислення та збереження кожної пари значень
        cur_x = x1;
        for (unsigned int j = 0; j < count; j++) {
            double func = calc_func(cur_x);
            fwrite(&cur_x, sizeof(double), 1, bin_file);
            fwrite(&func, sizeof(double), 1, bin_file);
            cur_x += delta;
        }

        fclose(bin_file);
    } else {
        printf("Error! File cannot be opened 3\n");
    }
}

void print_bin_data(void) {
    FILE* bin_file;

    // Відкриття бінарного файлу для читання
    if ((bin_file = fopen("../Texts/bin_file.bin", "rb")) != NULL) {
        unsigned int check_N = 0;

        // Зчитування кількості точок, яка була збережена на початку файлу
        fread(&check_N, sizeof(unsigned int), 1, bin_file);

        // Виділення динамічної пам'яті для масиву розміром 2*N (пари x та f(x))
        double* dynamic_array = (double*)malloc(2 * check_N * sizeof(double));

        if (dynamic_array != NULL) {
            // Зчитування всіх значень з файлу одним блоком у масив
            fread(dynamic_array, sizeof(double), 2 * check_N, bin_file);

            printf("\nДані з бінарного файлу (динамічний масив):\n");
            printf("%12s | %20s | %20s\n", "Номер точки", "Значення аргументу", "Значення функції");

            for (unsigned int j = 0; j < check_N; j++) {
                double x = dynamic_array[2 * j];
                double fx = dynamic_array[2 * j + 1];
                printf("%12u | %20.4lf | %20.4lf\n", j + 1, x, fx);
            }

            free(dynamic_array);
        } else {
            printf("Помилка! Не вдалося виділити пам'ять для масиву.\n");
        }

        fclose(bin_file);
    } else {
        printf("Error! File cannot be opened 4\n");
    }
}