#include "stack.h"

#include <stdbool.h>
#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int pop_test();
int push_test();

int main() {
    int pop_test_result = pop_test();
    if (pop_test_result == SUCCESS) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    int push_test_result = push_test();
    if (push_test_result == SUCCESS) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    return 0;
}

int pop_test() {
    struct Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    int data = pop(&stack);
    if (data != 3) {
        return FAIL;
    }

    data = pop(&stack);
    if (data != 2) {
        return FAIL;
    }

    data = pop(&stack);
    if (data != 1) {
        return FAIL;
    }
    destroy(&stack);
    return SUCCESS;
}

int push_test() {
    struct Stack stack;
    init(&stack);

    push(&stack, 1);
    if (stack.top->data != 1) {
        return FAIL;
    }
    push(&stack, 2);
    if (stack.top->data != 2) {
        return FAIL;
    }
    push(&stack, 3);
    if (stack.top->data != 3) {
        return FAIL;
    }
    destroy(&stack);
    return SUCCESS;
}