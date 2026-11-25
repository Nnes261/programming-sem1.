#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double x_start, x_end, dx;
    printf("=== Task 1: Tabulation (Variant 3) ===\n");
    printf("Enter X_start, X_end, dX: ");
    
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        fprintf(stderr, "Error: invalid input format.\n");
        return 1;
    }
    if (x_start >= x_end || dx <= 0.0) {
        fprintf(stderr, "Error: X_start must be < X_end and dX > 0.\n");
        return 1;
    }

    printf("\n+------------+----------------+\n");
    printf("|     X      |      Y(X)      |\n");
    printf("+------------+----------------+\n");

    double x = x_start;
    double eps = dx / 1000.0;

    while (x <= x_end + eps) {
        double y = 0.0;
        int is_defined = 1;

        if (x <= 1.0) {
            y = 2.0 * x + 1.0;
        } else if (x <= 3.0) {
            if (fabs(x - 2.0) < 1e-7) {
                is_defined = 0;
            } else {
                y = x / (x - 2.0);
            }
        } else {
            if (x < 0.0) {
                is_defined = 0;
            } else {
                y = sqrt(x);
            }
        }

        if (is_defined) {
            printf("| %10.4lf | %14.4lf |\n", x, y);
        } else {
            printf("| %10.4lf |  [Undefined]  |\n", x);
        }

        x += dx;
    }

    printf("+------------+----------------+\n");
    return 0;
}