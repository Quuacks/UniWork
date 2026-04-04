#ifndef QUEUE_H
#define QUEUE_H

typedef struct Element{
    int data;
    struct Element *nextElement;
}Element;
typedef struct Queue{
    Element *head;
    Element *tail;
    size_t size;
} Queue;

void initQueue(Queue *queue);
int enqueue(Queue *queue, int value);
int dequeue(Queue *queue, int *out);
Element* getFront(Queue *queue);
Element* getRear(Queue *queue);
int isEmpty(Queue *queue);
size_t queueSize(Queue *queue);

#endif