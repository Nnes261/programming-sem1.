x#include <stdio.h>
#include <math.h>

int main(void) {
    double m, v;
    double E_k, p;

    printf("=== Engineering Calculation (Task 3) ===\n");

    printf("Enter mass m (kg): ");
    if (scanf("%lf", &m) != 1 || m < 0) {
        printf("Error: Invalid mass value!\n");
        return 1;
    }

    printf("Enter velocity v (m/s): ");
    if (scanf("%lf", &v) != 1 || v < 0) {
        printf("Error: Invalid velocity value!\n");
        return 1;
    }

    E_k = (m * v * v) / 2.0;
    p = m * v;

    printf("\n--- Calculation Results ---\n");
    printf("Kinetic energy (E_k): %.2f J\n", E_k);
    printf("Momentum (p):         %.2f kg*m/s\n", p);

    return 0;
}
