#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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

    printf("Value deleted = %d\n", target->data);
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
    
    printf("Value deleted = %d\n", target->data);
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

    // Special Case : When list has single element
    if(track->next == track) {
        start = NULL;
        printf("Value deleted = %d\n", track->data);
        free(track);
        return;
    }

    // Special Case : When pos = 1
    // Reason : We have to handle the link of last node which is pointing current start
    if(pos==1) {
        do {
            track = track->next;
        } while(track->next != start);

        track->next = start->next;
        track = start;
        start = start->next;

        printf("Value deleted = %d\n", track->data);
        free(track);
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

    CLL *target = track->next;
    track->next = target->next;
    
    printf("Value deleted = %d\n", target->data);
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

void menu() {
    system("cls");

    printf("--------------------------------------------------------");
    printf("\n                  Circular Linked List");
    printf("\n--------------------------------------------------------");
        
    printf("\n\t01  -  Print list");
    printf("\n\t02  -  Insert at first");
    printf("\n\t03  -  Insert at last");
    printf("\n\t04  -  Insert at desired position");
    printf("\n\t05  -  Delete first element");
    printf("\n\t06  -  Delete last element");
    printf("\n\t07  -  Delete element from desired position");
    printf("\n\t08  -  Search in the list");
    printf("\n\t09  -  Exit\n");

    printf("Enter your choice : ");
}

int main() {
    int choice = 0;
    int element, pos;

    while(choice != 9) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printList();
                break;
            case 2 : {
                printf("Enter an element to insert at first position : ");
                scanf("%d", &element);
                insertAtFirst(element);
                break;
            }
            case 3 : {
                printf("Enter an element to insert at last position : ");
                scanf("%d", &element);
                insertAtLast(element);
                break;
            }
            case 4 : {
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
                printf("Enter the position where you want to perform deletion : ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            }
            case 8 : {
                printf("Enter the element you want to search for : ");
                scanf("%d", &element);
                searchLinkedList(element);
                break;
            }
            case 9 :
                printf("\n---------------------------------");
                printf("\n            THANK YOU");
                printf("\n---------------------------------\n");
                break;
            default :
                printf("Enter correct choice!\n");
        }

        printf("\nPress any key to continue.........");
        getch();
    }
    
    return 0;
}
