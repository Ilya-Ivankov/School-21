#include <stdio.h>

int main() {
    double x, y, R;
    char otstup;

    if (3 != scanf("%lf %lf%c", &x, &y, &otstup) || otstup != '\n') {
        printf("n/a\n");
        return 0;
    } else {
        R = 5.0;
        if ((x * x) + (y * y) <= (R * R)) {
            printf("GOTCHA\n");
        } else {
            printf("MISS\n");
        }
    }

    return 0;
}
