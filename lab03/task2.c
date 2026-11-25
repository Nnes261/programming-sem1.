#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 4
#define COLS 5

int main(void) {
    setlocale(LC_ALL, "");
    int matrix[ROWS][COLS];
    srand((unsigned int)time(NULL));

    // Заполнение матрицы (Row-Major Order)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 41 - 20; // Диапазон [-20, 20]
        }
    }

    printf("Начальная матрица:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Поиск строки с максимальной суммой
    int max_sum = 0;
    int max_row_idx = 0;

    for (int i = 0; i < ROWS; i++) {
        int current_sum = 0;
        for (int j = 0; j < COLS; j++) {
            current_sum += matrix[i][j];
        }
        if (i == 0 || current_sum > max_sum) {
            max_sum = current_sum;
            max_row_idx = i;
        }
    }

    printf("\nСтрока с максимальной суммой: %d (Сумма = %d)\n", max_row_idx, max_sum);

    // Инвертирование знаков элементов этой строки
    for (int j = 0; j < COLS; j++) {
        matrix[max_row_idx][j] = -matrix[max_row_idx][j];
    }

    printf("\nМатрица после инвертирования знаков в строке %d:\n", max_row_idx);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}