#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

void initializeStack(Stack* stack, int capacity) {
    stack->data = (char*)malloc(sizeof(char) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

int isStackEmpty(Stack* stack) { return stack->top == -1; }

int isStackFull(Stack* stack) { return stack->top == stack->capacity - 1; }

void push(Stack* stack, char value) {
    if (isStackFull(stack)) {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }

    stack->data[++stack->top] = value;
}

char pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top--];
}

char peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is Empty!\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top];
}

int isOperator(char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/'; }

int getOperatorPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isDigit(char ch) { return ch >= '0' && ch <= '9'; }

int isVariable(char ch) { return ch == 'x'; }

int isFunction(char ch) { return ch == 's' || ch == 'c' || ch == 't' || ch == 'g' || ch == 'q' || ch == 'l'; }

void convertToPostfix(char* expression, char* postfix) {
    Stack operatorStack;
    initializeStack(&operatorStack, strlen(expression));

    size_t postfixIndex = 0;
    for (size_t i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (isDigit(ch)) {
            postfix[postfixIndex++] = ch;
        } else if (ch == '(') {
            push(&operatorStack, ch);
        } else if (ch == ')') {
            while (!isStackEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }

            if (!isStackEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                printf("Mismatched parentheses!\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&operatorStack);  // Discard '('
            }
        } else if (isOperator(ch)) {
            while (!isStackEmpty(&operatorStack) &&
                   getOperatorPrecedence(ch) <= getOperatorPrecedence(peek(&operatorStack))) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        } else if (isVariable(ch)) {
            postfix[postfixIndex++] = ch;
        } else if (isFunction(ch)) {
            while (!isStackEmpty(&operatorStack) && isFunction(peek(&operatorStack))) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        }
    }

    while (!isStackEmpty(&operatorStack)) {
        if (peek(&operatorStack) == '(') {
            printf("Mismatched parentheses!\n");
            exit(EXIT_FAILURE);
        }
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    postfix[postfixIndex] = '\0';
    free(operatorStack.data);
}

double evaluatePostfix(char* postfix) {
    Stack operandStack;
    initializeStack(&operandStack, strlen(postfix));

    for (size_t i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isDigit(ch)) {
            push(&operandStack, ch - '0');
        } else if (isOperator(ch)) {
            double operand2 = pop(&operandStack);
            double operand1 = pop(&operandStack);
            double result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(&operandStack, result);
        } else if (isVariable(ch)) {  // Variable 'x'
            double value;
            printf("Enter the value of x: ");
            scanf("%lf", &value);
            push(&operandStack, value);
        } else if (isFunction(ch)) {
            double x = pop(&operandStack);
            double result;

            switch (ch) {
                case 's':
                    result = sin(x);
                    break;
                case 'c':
                    result = cos(x);
                    break;
                case 't':
                    result = tan(x);
                    break;
                case 'g':
                    result = 1.0 / tan(x);
                    break;
                case 'q':
                    result = sqrt(x);
                    break;
                case 'l':
                    result = log(x);
                    break;
            }

            push(&operandStack, result);
        }
    }

    double result = pop(&operandStack);
    free(operandStack.data);
    return result;
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove the newline character
    expression[strcspn(expression, "\n")] = '\0';

    char postfix[MAX_EXPRESSION_LENGTH];
    convertToPostfix(expression, postfix);
    printf("Postfix expression: %s\n", postfix);

    double result = evaluatePostfix(postfix);
    printf("Result: %lf\n", result);

    return 0;
}
