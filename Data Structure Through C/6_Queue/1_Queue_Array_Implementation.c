#include <stdio.h>
#include <stdlib.h>

typedef struct queueArray {
    int front, rear;
    int *arr;
    int size;
} Queue;

void enQueue(Queue *q, int element) {
    if(q->rear == q->size) {
        printf("Queue overflow!\n");
        return;
    }

    q->arr[q->rear] = element;
    q->rear++;
}

void deQueue(Queue *q) {
    if(q->front == q->rear) {
        printf("Queue underflow!\n");
        return;
    }

    q->arr[q->front] = -1;
    q->front++;
}

int main() {

    Queue q;
    q.front = 0;
    q.rear = 0;
    q.size = 5;
    q.arr = (int*) malloc(q.size * sizeof(int));

    enQueue(&q, 10);
    enQueue(&q, 45);
    enQueue(&q, 12);
    enQueue(&q, 64);
    enQueue(&q, 54);
    
    printf("Top element = %d and last element = %d\n", q.arr[q.front], q.arr[q.rear-1]);

    return 0;
}