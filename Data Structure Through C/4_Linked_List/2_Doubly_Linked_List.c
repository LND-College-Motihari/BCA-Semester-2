#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} DLL;

DLL *start=NULL, *end=NULL;      // Creating a global empty list to access through all the functions of the program
int count = 0;                  // An integer variable to keep the track of number of elements in the list

/*
    VARIABLES USED IN THE BELOW ALGORITHMS

    newNode - A new node for insertion
    target - Target node for deletion
    track - Tracker variable to reach the target node
    temp - Temporary variable used for traversing through the nodes
    flag - Counting variable used while traversing
*/

void printListByStart() {
    if(start==NULL) {
        printf("List is empty!\n");
        return;
    }

    DLL *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListByEnd() {
    if(end==NULL) {
        printf("List is empty!\n");
        return;
    }

    DLL *temp = end;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insertAtFirst(int val) {
    DLL *newNode;
    newNode = (DLL*) malloc(sizeof(DLL));

    newNode->data = val;
    newNode->next = start;
    newNode->prev = NULL;

    if(end==NULL) {
        start = end = newNode;
    } else {
        start = start->prev = newNode;
    }

    count++;
}

void insertAtLast(int val) {
    DLL *newNode;
    newNode = (DLL*) malloc(sizeof(DLL));
    
    newNode->data = val;
    newNode->prev = end;
    newNode->next = NULL;

    // For empty list
    if(start==NULL) {
        end = start = newNode;
    } else {
        end = end->next = newNode;
    }

    count++;
}

void insertAtPosition(int pos, int val) {
    // Checking invalid position entries
    if(pos<1 || pos>count+1) {
        printf("Invalid position!\n");
        return;
    }

    DLL *newNode;
    newNode = (DLL*) malloc(sizeof(DLL));
    newNode->data = val;

    // Handling insertion at first position and start pointer
    if(pos==1) {
        if(count==0) {
            newNode->next = newNode->prev = NULL;
            end = start = newNode;
        } else {
            newNode->next = start;
            start = start->prev = newNode;
        }

        count++;
        return;
    }

    int flag = 2;
    DLL *track = start;

    while(track!=NULL && flag<pos) {
        track = track->next;
        flag++;
    }

    // Checking overflow of position entries
    if(track==NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Handling insertion at last position with changes in end pointer
    if(track->next == NULL) {
        end = newNode;
    } else {
        newNode->next->prev = newNode;
    }

    newNode->next = track->next;
    newNode->prev = track;
    track->next = newNode;
    count++;
}

void deleteFirst() {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    DLL *target = start;

    if(start==end) {
        start = end = NULL;
    } else {
        start = start->next;
        start->prev = NULL;
    }

    free(target);
    count--;
}

void deleteLast() {
    if(end==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    DLL *target = end;

    if(start==end) {
        end = start = NULL;
    } else {
        end = end->prev;
        end->next = NULL;
    }

    free(target);
    count--;
}

void deleteAtPosition(int pos) {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    // Checking invalid position entries
    if(pos<1 || pos>count) {
        printf("Invalid position!\n");
        return;
    }

    int flag = 1;
    DLL *track = start;

    while(track!=NULL && flag<pos) {
        track = track->next;
        flag++;
    }

    if(pos==1) {
        if(start == end) {
            start = end = NULL;
        } else {
            start = start->next;
            start->prev = NULL;
        }
    } else if(pos==count) {
        end = end->prev;
        end->next = NULL;
    } else {
        track->prev->next = track->next;
        track->next->prev = track->prev;
    }

    free(track);
    count--;
}

void searchLinkedList(int val) {
    if(start==NULL) {
        printf("List is empty - Nothing to search for!\n");
        return;
    }
    
    DLL *temp = start;
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

int main() {
    for(int i=1; i<=5; i++) {
        insertAtLast(pow(2,i));
    }

    printf("Linked list by start : ");
    printListByStart();
    
    printf("Linked list by end : ");
    printListByEnd();
    
    return 0;
}




//    main() function in the form of a menu card as per the syllabus of lab portion guided by Mam (Anjna Chaudhary)
/*

    int choice = 0;
    
    printf("------------------------------------------------------");
    printf("\n                  Doubly Linked List");
    printf("\n------------------------------------------------------\n\n");

    while(choice != 9) {
        printf("Enter your choice : ");
        printf("\n\t\t1  -  Print list by start");
        printf("\n\t\t2  -  Print list by end");
        printf("\n\t\t3  -  Insert at first");
        printf("\n\t\t4  -  Insert at last");
        printf("\n\t\t5  -  Insert at desired position");
        printf("\n\t\t6  -  Delete first element");
        printf("\n\t\t7  -  Delete last element");
        printf("\n\t\t8  -  Delete element from desired position");
        printf("\n\t\t9  -  Search in the list");
        printf("\n\t\t10  -  Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printListByStart();
                break;
            case 2 :
                printListByEnd();
                break;
            case 3 : {
                int element;
                printf("Enter an element to insert at first position : ");
                scanf("%d", &element);
                insertAtFirst(element);
                break;
            }
            case 4 : {
                int element;
                printf("Enter an element to insert at last position : ");
                scanf("%d", &element);
                insertAtLast(element);
                break;
            }
            case 5 : {
                int element, pos;
                printf("Enter an element for insertion : ");
                scanf("%d", &element);
                printf("Enter the position where you want to insert the element : ");
                scanf("%d", &pos);
                insertAtPosition(pos, element);
                break;
            }
            case 6 :
                deleteFirst();
                break;
            case 7 :
                deleteLast();
                break;
            case 8 : {
                int pos;
                printf("Enter the position where you want to perform deletion : ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            }
            case 9 : {
                int element;
                printf("Enter the element you want to search for : ");
                scanf("%d", &element);
                searchLinkedList(element);
                break;
            }
            case 10 :
                break;
            default :
                printf("Enter correct choice!\n");
        }
    }

*/
