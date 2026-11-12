#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n, int *total_primes);

int main(void) {
    int numbers[] = {2, 4, 7, 10, 13, 15, 17, 21, 29};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int prime_count = 0;

    printf("=== Перев╕рка чисел на простоту (Вар╕ант 3) ===\n");
    for (int i = 0; i < size; i++) {
        bool result = is_prime(numbers[i], &prime_count);
        printf("Число %2d -> %s (Всього знайдено простих: %d)\n",
               numbers[i], result ? "ПРОСТЕ" : "складене", prime_count);
    }
    return 0;
}

bool is_prime(int n, int *total_primes) {
    static int session_primes = 0;
    if (n < 2) {
        if (total_primes != NULL) *total_primes = session_primes;
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (total_primes != NULL) *total_primes = session_primes;
            return false;
        }
    }
    session_primes++;
    if (total_primes != NULL) *total_primes = session_primes;
    return true;
}
