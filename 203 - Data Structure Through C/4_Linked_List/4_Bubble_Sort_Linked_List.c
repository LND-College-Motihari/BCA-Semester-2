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
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Bubble Sorting of Linked Lists)

    Time Complexity - O(n^2)
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    haed - Pointer variable pointing at the first element of the given linked list
    head->data - Data memeber of the list
    head->next - Pointer variable of the list
    
    curr - Node pointer used to traverse through the list (from head to barr)
    barr - Node pointer used as a barrier for loops (traversing from end to start)
    val - Temporary variable used for swaping values
*/
void bubbleSort() {
    SLL *curr = head;
    SLL *barr = NULL;

    while(curr != barr) {
        while(curr->next != barr) {

            if(curr->data > curr->next->data) {
                int val = curr->data;
                curr->data = curr->next->data;
                curr->next->data = val;
            }

            curr = curr->next;
        }

        barr = curr;
        curr = head;
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

    bubbleSort();

    printf("After sorting : ");
    printList();

    return 0;
}
