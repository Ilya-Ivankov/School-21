
int s21_strlen(const char *data) {
    int count = 0;
    while (data[count] != '\0') {
        count++;
    }
    return count;
}

int s21_strcmp(const char *str1, const char *str2) {
    int test = 0;
    int i = 0;
    if (s21_strlen(str1) > s21_strlen(str2)) {
        test = 1;
    } else if ((s21_strlen(str1) < s21_strlen(str2))) {
        test = -1;
    } else {
        for (int j = 0; j < s21_strlen(str1); j++) {
            if (str1[i] == str2[i]) {
                i++;
            } else if (str1[i] > str2[i]) {
                test = 1;
            } else if (str1[i] < str2[i]) {
                test = -1;
            }
        }
    }

    return test;
}

char *s21_strcpy(char *dest, const char *src) {
    for (int i = 0; i < (s21_strlen(src)); i++) {
        dest[i] = src[i];
    }
    dest[s21_strlen(src)] = '\0';
    return dest;
}

char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }

    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

const char *s21_strchr(const char *str, int c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }
    return 0;
}

int s21_strstr(const char *src1, const char *src2) {
    int index = -1;
    if (s21_strlen(src1) < s21_strlen(src2)) {
        index = -1;
    }
    if (s21_strlen(src2) == 0) {
        index = -1;
    }
    for (int i = 0; i < (s21_strlen(src1)); i++) {
        if (src1[i] == src2[0]) {
            for (int j = 1; j < (s21_strlen(src2)); j++) {
                if (src1[i + j] != src2[j]) {
                    break;
                } else {
                    index = i;
                }
            }
        }
    }
    return index;
}

char *s21_strtok(char *str, const char *delimiters) {
    static char *token = 0;
    if (str != 0) {
        token = str;
    }

    while (*token != '\0' && s21_strchr(delimiters, *token) != 0) {
        token++;
    }

    if (*token == '\0') {
        return 0;
    }

    char *start = token;

    while (*token != '\0' && s21_strchr(delimiters, *token) == 0) {
        token++;
    }

    if (*token != '\0') {
        *token = '\0';
        token++;
    }

    return start;
}
