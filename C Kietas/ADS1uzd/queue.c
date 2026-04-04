#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *queue)
{
    queue->tail = NULL;
    queue->head = NULL;
    queue->size = 0;

}
int enqueue(Queue *queue, int value)
{
    Element *newElement = malloc(sizeof(Element));
    if(!newElement)
        return 0;

    newElement->data = value;
    newElement->nextElement = NULL;

    if(queue->tail == NULL)
    {
        queue->tail = newElement;
        queue->head = newElement;
    }
    else
    {
        queue->tail->nextElement = newElement;
        queue->tail = newElement;
    }
    queue->size++;
    return 1;
}
int dequeue(Queue *queue, int *out)
{
    if(queue->head == NULL)
        return 0;

    Element *temp = queue->head;
    *out = temp->data;
    queue->head = queue->head->nextElement;
    if(queue->head == NULL)
        queue->tail = NULL;

    free(temp);
    queue->size--;

    return 1;
}
Element* getFront(Queue *queue)
{
    return queue->head;
}
Element* getRear(Queue *queue)
{
    return queue->tail;
}
int isEmpty(Queue *queue)
{
    if(queue->head == NULL)
        return 1;
    return 0;
}
size_t queueSize(Queue *queue)
{
    return queue->size;
}