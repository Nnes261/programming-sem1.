#include <stdio.h>
#include <stddef.h>

int sum_above_average_ptr_arith(const double *start, size_t n, double *out_avg, double *out_sum_above) {
    if (start == NULL || out_avg == NULL || out_sum_above == NULL || n == 0) {
        return 0;
    }

    const double *ptr = start;
    const double *end_ptr = start + n;
    double total = 0.0;

    while (ptr < end_ptr) {
        total += *ptr;
        ptr++;
    }

    double avg = total / (double)n;
    double sum_above = 0.0;

    for (size_t i = 0; i < n; ++i) {
        double elem = *(start + i);
        if (elem > avg) {
            sum_above += elem;
        }
    }

    *out_avg = avg;
    *out_sum_above = sum_above;
    return 1;
}

int main(void) {
    double data[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    size_t n = sizeof(data) / sizeof(*data);

    double avg = 0.0;
    double sum_above = 0.0;

    if (sum_above_average_ptr_arith(data, n, &avg, &sum_above)) {
        printf("Average: %.2f\n", avg);
        printf("Sum of elements > average: %.2f\n", sum_above);
    } else {
        fprintf(stderr, "Error: invalid input or empty buffer\n");
        return 1;
    }

    return 0;
}