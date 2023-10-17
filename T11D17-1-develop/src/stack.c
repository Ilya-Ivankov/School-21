#include "stack.h"

#include <stdlib.h>

void init(struct Stack* stack) { stack->top = NULL; }

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    int data = 0;
    if (stack->top == NULL) {
        data = 0;

    } else {
        data = stack->top->data;
        struct Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }

    return data;
}

void destroy(struct Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
}
