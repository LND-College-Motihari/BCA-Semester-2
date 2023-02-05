#include <stdio.h>
#define MAX 100

int Queue[MAX];
int front = -1;
int rear = -1;

void printQueue() {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements : ");
    for(int i=front; i<=rear; i++) {
        printf("%d ", Queue[i]);
    }
    printf("\n");
}

void enQueue(int element) {
    if(front == 0 && rear == MAX-1) {
        printf("Queue overflow!\n");
        return;
    }

    if(rear == -1) {
        front = rear = 0;
    } else if(front > 0 && rear == MAX-1) {
        int i;

        for(i=front; i<=rear; i++) {
            Queue[i-front] = Queue[i];
        }

        rear = i-front;
        front = 0;
    } else {
        rear++;
    }

    Queue[rear] = element;
}

void deQueue() {
    if(front == -1) {
        printf("Queue underflow!\n");
        return;
    }

    printf("Element dequeued = %d\n", Queue[front]);

    if(front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
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
    
    printf("--------------------------------------------------");
    printf("\n           Queue - Array representation");
    printf("\n--------------------------------------------------\n\n");

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
