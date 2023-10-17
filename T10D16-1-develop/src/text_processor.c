#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void formatText(int width, const char *text);

int main(int argc, char *argv[]) {
    if (argc < 2 || s21_strcmp(argv[1], "-w") != 0) {
        printf("n/a");
        return 0;
    }

    int width;
    scanf("%d", &width);

    char text[101];
    fgets(text, sizeof(text), stdin);

    formatText(width, text);

    return 0;
}

void formatText(int width, const char *text) {
    int currWidth = 0;
    char *token = s21_strtok((char *)text, " \n");

    while (token != NULL) {
        int wordLen = s21_strlen(token);

        if (currWidth + wordLen > width) {
            printf("\n");
            currWidth = 0;
        }

        if (currWidth > 0 && currWidth + wordLen + 1 <= width) {
            printf(" ");
            currWidth++;
        }

        printf("%s", token);
        currWidth += wordLen;

        token = s21_strtok(NULL, " \n");
    }

    printf("\n");
}
