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

void insertionSort() {
    SLL *curr = head;
    SLL *sorted = NULL;
    
    while(curr != head) {
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
        
        curr->next = temp->next;
        temp->next = curr;
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
