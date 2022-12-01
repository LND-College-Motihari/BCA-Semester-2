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
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Insertion Sorting of Linked Lists)

    Time Complexity - O(n^2)
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    haed - Pointer variable pointing at the first element of the given linked list
    head->data - Data memeber of the list
    head->next - Pointer variable of the list
    
    sorted - Node pointer used to store the first node of the sorted list
    curr - Node pointer used to store the current element for insertion
    next - Node pointer containing address of the next node
    temp - Node variable used to traverse through the sorted list to find the right position for curr
*/
void insertionSort() {
    SLL *sorted = NULL;
    SLL *curr = head;

    while(curr != NULL) {
        SLL *next = curr->next;

        if(sorted == NULL || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            SLL *temp = sorted;

            while(temp->next != NULL && temp->next->data < curr->data) {
                temp = temp->next;
            }

            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next;
    }

    head = sorted;
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

    insertionSort();

    printf("After sorting : ");
    printList();

    return 0;
}
