#include <stdio.h>
#include <stdlib.h>

typedef struct queueLinkedList {
    int data;
    struct queueLinkedList *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

void printQueue() {
    if(front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Queue *temp = front;
    printf("Queue elements : ");
    while(temp != rear) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enQueue(int element) {
    Queue *newNode;
    newNode = (Queue*) malloc(sizeof(Queue));
    newNode->data = element;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deQueue() {
    if(front==NULL) {
        printf("Queue underflow!\n");
        return;
    }

    Queue *target = front;
    front = front->next;

    printf("Element dequeued = %d\n", target->data);
    free(target);
}

int main() {

    enQueue(10);
    enQueue(45);
    enQueue(12);
    enQueue(64);
    enQueue(54);
    
    
    printQueue();

    return 0;
}




//    main() function in the form of a menu card as per the syllabus of lab portion guided by Mam (Anjna Chaudhary)
/*

    int choice;
    
    printf("--------------------------------------------------------");
    printf("\n           Queue - Linked list representation");
    printf("\n--------------------------------------------------------\n\n");

    while(choice != 4) {
        printf("Enter your choice : ");
        printf("\n\t\t1  -  Print Queue");
        printf("\n\t\t2  -  EnQueue");
        printf("\n\t\t3  -  DeQueue");
        printf("\n\t\t4  -  Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printQueue();
                break;
            case 2 : {
                int element;
                printf("Enter an element for enqueue operation : ");
                scanf("%d", &element);
                enQueue(element);
                break;
            }
            case 3 :
                deQueue();
                break;
            case 4 :
                break;
            default :
                printf("Enter correct choice!\n");
        }
    }

*/
