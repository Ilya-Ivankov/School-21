#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void init(struct Stack* stack);
void push(struct Stack* stack, int data);
int pop(struct Stack* stack);
void destroy(struct Stack* stack);

#endif
