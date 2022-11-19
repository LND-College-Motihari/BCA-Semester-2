#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
} CLL;

CLL *start = NULL;      // Creating a global empty list to access through all the functions of the program

/*
    VARIABLES USED IN THE BELOW ALGORITHMS

    newNode - A new node for insertion
    target - Target node for deletion
    track - Tracker variable to reach the target node
    temp - Temporary variable used for traversing through the nodes
    flag - Counting variable used while traversing
*/

void printList() {
    if(start==NULL) {
        printf("List is empty!\n");
        return;
    }

    CLL *temp = start;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != start);

    printf("\n");
}

void insertAtFirst(int val) {
    CLL *newNode;
    newNode = (CLL*) malloc(sizeof(CLL));
    newNode->data = val;

    if(start == NULL) {
        newNode->next = newNode;
        start = newNode;
        return;
    }

    CLL *track = start->next;
    while(track->next != start) {
        track = track->next;
    }

    newNode->next = start;
    track->next = newNode;
    start = newNode;
}

void insertAtLast(int val) {
    CLL *newNode;
    newNode = (CLL*) malloc(sizeof(CLL));
    newNode->data = val;

    if(start == NULL) {
        newNode->next = newNode;
        start = newNode;
        return;
    }

    CLL *track = start->next;
    while(track->next != start) {
        track = track->next;
    }

    newNode->next = start;
    track->next = newNode;
}

void insertAtPosition(int pos, int val) {
    if(pos<1) {
        printf("Invalid position!\n");
        return;
    }

    CLL *newNode;
    newNode = (CLL*) malloc(sizeof(CLL));
    newNode->data = val;

    if(start == NULL) {
        if(pos!=1) {
            printf("Invalid position!\n");
        } else {
            newNode->next = newNode;
            start = newNode;
        }
        
        return;
    }

    CLL *track = start;
    int flag = 1;

    // Special condition for insertion at first position
    if(pos==1) {
        do {
            track = track->next;
        } while(track->next != start);

        track->next = newNode;
        newNode->next = start;
        start = newNode;
        return;
    }

    while(flag < pos-1) {
        track = track->next;
        flag++;

        if(track==start) {
            printf("Invalid position\n");
            return;
        }
    }

    newNode->next = track->next;
    track->next = newNode;
}

void deleteFirst() {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    CLL *track = start->next;
    while(track->next != start) {
        track = track->next;
    }

    CLL *target = start;
    
    track->next = start->next;
    start = (start==track) ? NULL : start->next;

    free(target);
}

void deleteLast() {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }

    CLL *target = start->next;
    CLL *track = start;

    while(target->next != start) {
        track = target;
        target = target->next;
    }

    track->next = target->next;
    start = (start==target) ? NULL : start;
    free(target);
}

void deleteAtPosition(int pos) {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }

    if(pos<1) {
        printf("Invalid position!\n");
        return;
    }

    CLL *track = start;
    int flag = 1;

    // Special condition for insertion at first position
    if(pos==1) {
        do {
            track = track->next;
        } while(track->next != start);

        track->next = start->next;
        track = start;
        start = start->next;

        free(track);
        return;
    }

    while(flag < pos) {
        track = track->next;
        flag++;

        if(track==start) {
            printf("Invalid position\n");
            return;
        }
    }

    CLL *target = track->next;
    track->next = target->next;
    free(target);
}

void searchLinkedList(int val) {
    if(start==NULL) {
        printf("List is empty - Nothing to search for!\n");
        return;
    }

    CLL *temp = start;
    int pos = 1;

    do {
        if(temp->data == val) {
            printf("Value found at position - %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    } while(temp!=start);

    printf("Value not found!\n");
}

int main() {
    for(int i=1; i<=5; i++) {
        insertAtLast(pow(2,i));
    }

    printf("Linked list : ");
    printList();

    return 0;
}




//    main() function in the form of a menu card as per the syllabus of lab portion guided by Mam (Anjna Chaudhary)
/*

    int choice = 0;
    
    printf("--------------------------------------------------------");
    printf("\n                  Circular Linked List");
    printf("\n--------------------------------------------------------\n\n");

    while(choice != 9) {
        printf("Enter your choice : ");
        printf("\n\t\t1  -  Print list");
        printf("\n\t\t2  -  Insert at first");
        printf("\n\t\t3  -  Insert at last");
        printf("\n\t\t4  -  Insert at desired position");
        printf("\n\t\t5  -  Delete first element");
        printf("\n\t\t6  -  Delete last element");
        printf("\n\t\t7  -  Delete element from desired position");
        printf("\n\t\t8  -  Search in the list");
        printf("\n\t\t9  -  Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printList();
                break;
            case 2 : {
                int element;
                printf("Enter an element to insert at first position : ");
                scanf("%d", &element);
                insertAtFirst(element);
                break;
            }
            case 3 : {
                int element;
                printf("Enter an element to insert at last position : ");
                scanf("%d", &element);
                insertAtLast(element);
                break;
            }
            case 4 : {
                int element, pos;
                printf("Enter an element for insertion : ");
                scanf("%d", &element);
                printf("Enter the position where you want to insert the element : ");
                scanf("%d", &pos);
                insertAtPosition(pos, element);
                break;
            }
            case 5 :
                deleteFirst();
                break;
            case 6 :
                deleteLast();
                break;
            case 7 : {
                int pos;
                printf("Enter the position where you want to perform deletion : ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            }
            case 8 : {
                int element;
                printf("Enter the element you want to search for : ");
                scanf("%d", &element);
                searchLinkedList(element);
                break;
            }
            case 9 :
                break;
            default :
                printf("Enter correct choice!\n");
        }
    }

*/
