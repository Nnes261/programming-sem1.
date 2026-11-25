#include <stdio.h>
#include <locale.h>

#define BUFFER_SIZE 256

int main(void) {
    setlocale(LC_ALL, "");
    char str[BUFFER_SIZE];

    printf("Введіть рядок тексту (латинськими літерами): ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    // Ручна обробка ASCII-кодів до null-термінатора '\0' без string.h
    for (int i = 0; str[i] != '\0'; i++) {
        // Якщо символ є малою латинською літерою ('a'..'z')
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A'); // Перетворення на верхній регістр
        }
    }

    printf("Результат: %s", str);

    return 0;
}