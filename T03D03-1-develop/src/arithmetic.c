#include <stdio.h>

void arithmetic(int a, int b, int* sum, int* umn, int* del, int* vsh) {
    *sum = a + b;
    *umn = a * b;
    *vsh = a - b;
    if (b != 0) {
        *del = a / b;
        printf("%d %d %d %d\n", *sum, *vsh, *umn, (int)*del);
    } else {
        printf("%d %d %d n/a\n", *sum, *vsh, *umn);
    }
}

int main() {
    int a, b, sum, umn, del, vsh;
    char perenos = '\0';

    if (3 != scanf("%d %d%c", &a, &b, &perenos) || perenos != '\n') {
        printf("n/a\n");
        return 1;
    } else {
        arithmetic(a, b, &sum, &umn, &del, &vsh);
    }

    return 0;
}