#include <stdio.h>
#include <limits.h>

int main(void) {
    // Розміри типів даних у байтах
    printf("Size of char: %zu byte(s)\n", sizeof(char));
    printf("Size of int: %zu byte(s)\n", sizeof(int));
    printf("Size of short: %zu byte(s)\n", sizeof(short));
    printf("Size of long: %zu byte(s)\n", sizeof(long));
    printf("Size of float: %zu byte(s)\n", sizeof(float));
    printf("Size of double: %zu byte(s)\n", sizeof(double));

    // Демонстрація Integer Overflow (переповнення)
    int max_int = INT_MAX;
    printf("\nINT_MAX: %d\n", max_int);
    printf("INT_MAX + 1 (Overflow): %d\n", max_int + 1);

    return 0;
}

