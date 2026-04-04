#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int arrSize;
    int *arr;
} Stack;

void initStack(Stack *stack) {
    stack->arrSize = 0;
    stack->arr = NULL;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->arrSize; ++i) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack) {
    return stack->arrSize;
}

void push(Stack *stack, int value) {
    stack->arr = realloc(stack->arr, (stack->arrSize + 1) * sizeof(int));
    if (stack->arr == NULL) {
        printf("Memory realloc fail\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[stack->arrSize] = value;
    stack->arrSize += 1;
}

int top(Stack *stack) {
    if (stack->arrSize == 0) {
        printf("Stack empty\n");
        return 0;
    }
    return stack->arr[stack->arrSize - 1];
}

int pop(Stack *stack) {
    if (stack->arrSize == 0) {
        printf("Stack empty\n");
        return 0;
    }
    int value = top(stack);
    stack->arrSize -= 1;
    stack->arr = realloc(stack->arr, stack->arrSize * sizeof(int));
    return value;
}

void destroyStack(Stack *stack) {
    free(stack->arr);
    stack->arr = NULL;
    stack->arrSize = 0;
}

int main() {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 5; ++i)
        push(&stack, i);

    printStack(&stack);

    printf("Top element: %d\n", top(&stack));

    printf("Pop: %d\n", pop(&stack));
    printStack(&stack);

    destroyStack(&stack);
    return 0;
}
