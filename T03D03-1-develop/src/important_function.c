#include <math.h>
#include <stdio.h>

int main() {
    double x, y;
    char otstup;
    if (2 != scanf("%lf%c", &x, &otstup) || otstup != '\n') {
        printf("n/a\n");
        return 0;
    } else {
        y = 7e-3 * pow(x, 4) + (((22.8 * pow(x, (1.0 / 3.0)) - 1e3) * x + 3.0) / (x * x / 2)) -
            x * pow((10 + x), (2.0 / x)) - 1.01;
        if (isnan(y)) {
            printf("n/a\n");
            return 0;
        }
        printf("%.1lf\n", y);
        return 0;
    }
    return 0;
}