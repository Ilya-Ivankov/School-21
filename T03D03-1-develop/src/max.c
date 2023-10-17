#include <stdio.h>

void maxx(int a, int b, int* max_num) {
    if (a >= b) {
        *max_num = a;
    } else {
        *max_num = b;
    }
    printf("%d\n", *max_num);
}

int main() {
    int a, b, max_num;
    char otstup;
    if (3 != scanf("%d %d%c", &a, &b, &otstup) || otstup != '\n') {
        printf("n/a\n");
        return 0;
    } else {
        maxx(a, b, &max_num);
    }
    return 0;
}
