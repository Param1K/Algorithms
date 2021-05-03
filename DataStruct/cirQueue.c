/*
    First in First out (FIFO)
    Enqueue -> Add an entry at rear
    Dequeue -> removes an entry from front
 */
#include<stdio.h>

#define QUEUE_MAX_LEN 10
typedef struct queue {
    int front;
    int rear;
    int entry[QUEUE_MAX_LEN];
} Queue;

void createQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int queueEmpty (Queue *q)
{
    if(q->front < 0) {
        printf("Queue Empty\n");
        return 1;
    }
    return 0;
}

int queueFull (Queue *q)
{
    if(((q->rear + 1) % QUEUE_MAX_LEN) == q->front) {
        printf("Queue Full\n");
        return 1;
    }
    return 0;
}

int enQueue (Queue *q, int item)
{
    if (!queueFull(q)) {
        q->rear = (q->rear + 1) % QUEUE_MAX_LEN;
        q->entry[q->rear] = item;
        printf("Queue entry %d added at rear %d\n", item, q->rear);
        if (q->front < 0) {
            q->front = 0;
        }
        return 0;
    }
    return -1;
}

int deQueue (Queue *q)
{
    int item;
    if (!queueEmpty(q)) {
        item = q->entry[q->front];
        printf("Queue entry %d removed from front %d\n", item, q->front);
        q->front = (q->front + 1) % QUEUE_MAX_LEN;
        if(q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        return item;
    }
    return -1;
}

int queueSize (Queue *q)
{
    if (q->front == q->rear) {
        return 0;
    } else if (q->rear > q->front) {
        return (q->rear - q->front + 1);
    } else {
        return (QUEUE_MAX_LEN + q->rear - q->front + 1);
    }
}

void main ()
{
    Queue myqueue;
    int count = 0;
    int item;

    createQueue(&myqueue);
    printf("Size returned is %d\n", queueSize(&myqueue));
    while(count <= QUEUE_MAX_LEN) {
        enQueue(&myqueue, count);
        printf("Size returned is %d\n", queueSize(&myqueue));
        count++;
    }
    printf("Size returned is %d\n", queueSize(&myqueue));

    count = 0;
    while(count <= 6) {
        item = deQueue(&myqueue);
        printf("Size returned is %d\n", queueSize(&myqueue));
        count++;
    }
    count = 0;
    while(count <= 7) {
        item = enQueue(&myqueue, count);
        printf("Size returned is %d\n", queueSize(&myqueue));
        count++;
    }

}
