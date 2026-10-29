#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    int arr[SIZE];
    srand((unsigned int)time(NULL));

    // Заповнення масиву числами від -50 до 50
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50;
    }

    printf("Початковий масив:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    // Пошук індексу мінімального елемента
    int min_idx = 0;
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    // Пошук першого та останнього додатних елементів
    int first_pos = -1, last_pos = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > 0) {
            if (first_pos == -1) {
                first_pos = i;
            }
            last_pos = i;
        }
    }

    int sum_between = 0;
    if (first_pos != -1 && last_pos != -1 && last_pos > first_pos + 1) {
        for (int i = first_pos + 1; i < last_pos; i++) {
            sum_between += arr[i];
        }
    }

    printf("\nРезультати:\n");
    printf("Номер (Індекс) мінімального елемента: %d (значення: %d)\n", min_idx, arr[min_idx]);

    if (first_pos != -1 && last_pos != -1 && last_pos > first_pos + 1) {
        printf("Перший додатний елемент на індексі [%d], останній на [%d]\n", first_pos, last_pos);
        printf("Сума елементів між ними: %d\n", sum_between);
    } else {
        printf("Неможливо обчислити суму: недостатньо додатних елементів.\n");
    }

    return 0;
}