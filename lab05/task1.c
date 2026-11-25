#include <stdio.h>
#include <math.h>

int cartesian_to_polar(const double *x, const double *y, double *out_r, double *out_theta) {
    if (x == NULL || y == NULL || out_r == NULL || out_theta == NULL) {
        return 0;
    }
    if (!isfinite(*x) || !isfinite(*y)) {
        return 0;
    }

    double vx = *x;
    double vy = *y;

    *out_r = hypot(vx, vy);
    *out_theta = atan2(vy, vx);
    return 1;
}

int main(void) {
    double x = 3.0;
    double y = 4.0;
    double r = 0.0;
    double theta = 0.0;

    if (cartesian_to_polar(&x, &y, &r, &theta)) {
        printf("Cartesian: (%.4f, %.4f)\n", x, y);
        printf("Polar: r = %.4f, theta = %.4f rad\n", r, theta);
    } else {
        fprintf(stderr, "Error: invalid pointer or non-finite coordinates\n");
        return 1;
    }

    return 0;
}