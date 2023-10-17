#include <math.h>
#include <stdio.h>

double fun();

int main() {
    double res = fun();
    double a = 1.0E-6;
    // 1.0E-6 == 10^(-6)
    // CHANGE THIS IF - AI
    if (res < a) printf("OK!\n");

    return 0;
}

// DO NOT TOUCH THIS FUNCTION - AI
double fun() { return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20)); }

// IT
