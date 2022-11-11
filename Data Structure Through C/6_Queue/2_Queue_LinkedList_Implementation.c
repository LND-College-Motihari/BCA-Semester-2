#include <stdio.h>
#include <stdlib.h>

typedef struct queueLinkedList {
    int data;
    struct queueLinkedList *next;
} Queue;

Queue *start = NULL;
Queue *end = NULL;

void enQueue(int element) {
    Queue *newNode;
    newNode = (Queue*) malloc(sizeof(Queue));
    newNode->data = element;
    newNode->next = NULL;

    if(start == NULL) {
        start = end = newNode;
    } else {
        end->next = newNode;
        end = newNode;
    }
}

void deQueue() {
    if(start==NULL) {
        printf("Queue underflow!\n");
        return;
    }

    Queue *target = start;
    start = start->next;
    free(target);
}

int main() {

    enQueue(10);
    enQueue(45);
    enQueue(12);
    enQueue(64);
    enQueue(54);
    
    printf("Top element = %d and last element = %d\n", start->data, end->data);

    return 0;
}