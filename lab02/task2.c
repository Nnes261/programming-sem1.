#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100000

int main(void) {
    double x, eps;
    printf("=== Task 2: Approximating cos(X) (Variant 3) ===\n");
    printf("Enter X and eps: ");
    
    if (scanf("%lf %lf", &x, &eps) != 2) {
        fprintf(stderr, "Error: invalid input.\n");
        return 1;
    }
    if (eps <= 0.0) {
        fprintf(stderr, "Error: eps must be > 0.\n");
        return 1;
    }

    double sum = 0.0;
    double term = 1.0;
    int n = 0;

    sum += term;

    while (fabs(term) >= eps) {
        n++;
        if (n > MAX_ITERATIONS) {
            printf("\nWARNING: Max iterations reached (%d).\n", MAX_ITERATIONS);
            break;
        }

        double r_n = - (x * x) / ((2.0 * n) * (2.0 * n - 1.0));
        term = term * r_n;
        sum += term;
    }

    double exact_value = cos(x);
    double abs_error = fabs(sum - exact_value);

    printf("\n--- Results ---\n");
    printf("X:            %.6lf\n", x);
    printf("eps:          %.8lf\n", eps);
    printf("Sum:          %.10lf\n", sum);
    printf("cos(x) math:  %.10lf\n", exact_value);
    printf("Abs Error:    %.10e\n", abs_error);
    printf("Iterations:   %d\n", n);

    return 0;
}