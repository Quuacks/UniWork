#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    unsigned int arrSize;
    Point *arr;
} Stack;

void printPoint(Point p) {
    printf("(%.2f, %.2f) ", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point newPoint = {x, y};
    return newPoint;
}

double getDistance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void initStack(Stack *stack) {
    stack->arrSize = 0;
    stack->arr = NULL;
}

void printStack(Stack *stack) {
    Point pointNull = {0,0};
    for (int i = 0; i < stack->arrSize; ++i)
    {
        printPoint(stack->arr[i]);
        printf("atstumas: %.2f\n", getDistance(pointNull, stack->arr[i]));
    }
    printf("\n");
}

int getStackSize(Stack *stack) {
    return stack->arrSize;
}

void push(Stack *stack, Point point) {
    stack->arr = realloc(stack->arr, (stack->arrSize + 1) * sizeof(Point));
    if (stack->arr == NULL) {
        printf("Memory realloc fail\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[stack->arrSize] = point;
    stack->arrSize++;
}

Point top(Stack *stack) {
    if (stack->arrSize == 0) {
        printf("Stack empty\n");
        Point pointNull = {0, 0};
        return pointNull;
    }
    return stack->arr[stack->arrSize - 1];
}

Point pop(Stack *stack) {
    if (stack->arrSize == 0) {
        printf("Stack empty\n");
        Point pointNull = {0, 0};
        return pointNull;
    }
    Point point = top(stack);
    stack->arrSize--;

    if (stack->arrSize == 0) {
        free(stack->arr);
        stack->arr = NULL;
    } else {
        stack->arr = realloc(stack->arr, stack->arrSize * sizeof(Point));
        if (stack->arr == NULL) {
            printf("Memory realloc fail\n");
            exit(EXIT_FAILURE);
        }
    }
    return point;
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
        push(&stack, createPoint(i, i * 2));

    printStack(&stack);

    destroyStack(&stack);
    return 0;
}
