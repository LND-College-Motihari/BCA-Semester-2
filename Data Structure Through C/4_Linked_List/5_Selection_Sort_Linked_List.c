#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} SLL;

SLL *head = NULL;

void printList() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    SLL *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insertAtHead(int element) {
    SLL *newNode;
    newNode = (SLL*) malloc(sizeof(SLL));
    newNode->data = element;
    newNode->next = head;
    head = newNode;
}

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Selection Sorting of Linked Lists)

    Time Complexity - O(n^2)
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    haed - Pointer variable pointing at the first element of the given linked list
    head->data - Data memeber of the list
    head->next - Pointer variable of the list
    
    track - Node variable used to traverse through the list (from head to NULL)
    min - Contains smallest element of the list
    minNode - Node pointer containing address of node with minimum value
    temp - Node variable used to traverse through the list inside the loop (from track->next to NULL)
*/
void selectionSort() {
    SLL *track = head;

    while(track != NULL) {
        int min = track->data;
        SLL *minNode = track;
        SLL *temp = track->next;

        while(temp != NULL) {
            if(temp->data < min) {
                min = temp->data;
                minNode = temp;
            }
            
            temp = temp->next;
        }

        minNode->data = track->data;        
        track->data = min;

        track = track->next;
    }
}

int main() {
    insertAtHead(56);
    insertAtHead(0);
    insertAtHead(12);
    insertAtHead(65);
    insertAtHead(-64);
    insertAtHead(31);
    insertAtHead(11);
    insertAtHead(-98);
    insertAtHead(99);
    insertAtHead(36);
    
    printf("Before sorting : ");
    printList();

    selectionSort();

    printf("After sorting : ");
    printList();

    return 0;
}
