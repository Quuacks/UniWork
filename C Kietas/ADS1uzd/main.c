#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void sizeTest(Queue *queue, int size)
{
    int value = 0;
    for(int i = 0; i < size; i++)
    {
        enqueue(queue, i);
    }

    for(int i = 0; i < size; i++)
    {
        dequeue(queue, &value);
        printf("dequeue1: %d    size: %d\n", value, queueSize(queue));
    }
}
void test(Queue *queue)
{
    int value = 2;

    enqueue(queue, 5);
    enqueue(queue, 1551);
    enqueue(queue, 12);
    enqueue(queue, 47);

    printf("size: %d\n", queueSize(queue));
    printf("Front: %d\n", getFront(queue)->data);
    printf("Rear: %d\n", getRear(queue)->data);

    dequeue(queue, &value);
    printf("dequeue1: %d    size: %d\n", value, queueSize(queue));
    dequeue(queue, &value);
    printf("dequeue2: %d    size: %d\n", value, queueSize(queue));
    dequeue(queue, &value);
    printf("dequeue3: %d    size: %d\n", value, queueSize(queue));
    dequeue(queue, &value);
    printf("dequeue4: %d    size: %d\n", value, queueSize(queue));
    dequeue(queue, &value);
    printf("dequeue5 (Should be empty): %d  size: %d\n", value, queueSize(queue));
}
int main(){
    Queue queue;
    initQueue(&queue);
    int value = 2;

    sizeTest(&queue, 100);
    //test(&queue);
}