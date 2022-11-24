#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} SLL;

SLL *start = NULL;      // Creating a global empty list to access through all the functions of the program

/*
    VARIABLES USED IN THE BELOW ALGORITHMS

    newNode - A new node for insertion
    target - Target node for deletion
    track - Tracker variable to reach the target node
    prev - Variable used to store the address of previous node
    temp - Temporary variable used for traversing through the nodes
    flag - Counting variable used while traversing
*/

void printList() {
    if(start==NULL) {
        printf("List is empty!\n");
        return;
    }

    SLL *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtFirst(int val) {
    SLL *newNode;
    newNode = (SLL*) malloc(sizeof(SLL));
    
    newNode->data = val;
    newNode->next = start;
    start = newNode;
}

void insertAtLast(int val) {
    SLL *newNode;
    SLL *head = start;

    newNode = (SLL*) malloc(sizeof(SLL));
    newNode->data = val;
    newNode->next = NULL;

    // For empty list
    if(head==NULL) {
        start = newNode;
        return;
    }
    
    while(head->next != NULL) {
        head = head->next;
    }

    head->next = newNode;
}

void insertAtPosition(int pos, int val) {
    SLL *newNode;
    newNode = (SLL*) malloc(sizeof(SLL));
    newNode->data = val;

    if(pos==1) {
        newNode->next = start;
        start = newNode;
        return;
    }

    int flag = 2;
    SLL *track;
    track = start;

    while(track!=NULL && flag<pos) {
        track = track->next;
        flag++;
    }

    if(track==NULL || pos<1) {
        printf("Position not found\n");
        return;
    }

    newNode->next = track->next;
    track->next = newNode;
}

void deleteFirst() {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    SLL *target = start;
    start = start->next;
    
    printf("Value deleted = %d\n", target->data);
    free(target);
}

void deleteLast() {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    SLL *target = start;
    SLL *prev = NULL;

    while(target->next != NULL) {
        prev = target;
        target = target->next;
    }

    prev->next = NULL;
    printf("Value deleted = %d\n", target->data);
    free(target);
}

void deleteAtPosition(int pos) {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    int flag = 1;
    SLL *track = start;
    SLL *prev = NULL;

    if(pos==1) {
        start = start->next;
        printf("Value deleted = %d\n", track->data);
        free(track);
        return;
    }

    while(flag<pos) {
        if(track==NULL) {
            printf("Position not found\n");
            return;
        }

        prev = track;
        track = track->next;
        flag++;
    }

    if(track==NULL || pos<1) {
        printf("Position not found\n");
        return;
    }

    prev->next = track->next;
    printf("Value deleted = %d\n", track->data);
    free(track);
}

void searchLinkedList(int val) {
    if(start==NULL) {
        printf("List is empty - Nothing to search for!\n");
        return;
    }
    
    SLL *temp = start;
    int pos = 1;

    while(temp!=NULL) {
        if(temp->data == val) {
            printf("Value found at position - %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Value not found!\n");
}

void menu() {
    system("cls");

    printf("------------------------------------------------------");
    printf("\n                  Singly Linked List");
    printf("\n------------------------------------------------------");
        
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
                printf("Select valid option!\n");
        }

        printf("\nPress any key to continue.........");
        getch();
    }
    
    return 0;
}
