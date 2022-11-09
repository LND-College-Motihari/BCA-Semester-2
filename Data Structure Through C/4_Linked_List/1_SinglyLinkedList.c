#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node *next;
} SLL;

SLL *start = NULL;      // Creating a global empty list to access through all the functions of the program

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

void insertFirst(int val) {
    SLL *temp;
    temp = (SLL*) malloc(sizeof(SLL));
    
    temp->data = val;
    temp->next = start;
    start = temp;
}

void insertLast(int val) {
    SLL *temp;
    SLL *head = start;

    temp = (SLL*) malloc(sizeof(SLL));
    temp->data = val;
    temp->next = NULL;

    // For empty list
    if(head==NULL) {
        start = temp;
        return;
    }
    
    while(head->next != NULL) {
        head = head->next;
    }

    head->next = temp;
}

void insertPosition(int pos, int val) {
    SLL *temp;
    temp = (SLL*) malloc(sizeof(SLL));
    temp->data = val;

    if(pos==1) {
        temp->next = start;
        start = temp;
        return;
    }

    int count = 2;
    SLL *track;
    track = start;

    while(track!=NULL && count<pos) {
        track = track->next;
        count++;
    }

    if(track==NULL || pos<1) {
        printf("Position not found\n");
        return;
    }

    temp->next = track->next;
    track->next = temp;
}

void deleteFirst() {
    if(start==NULL) {
        printf("List is empty\n");
        return;
    }

    SLL *temp = start;

    start = start->next;
    free(temp);
}

void deleteLast() {
    if(start==NULL) {
        printf("List is empty\n");
        return;
    }

    SLL *temp = start;
    SLL *prev = NULL;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deletePosition(int pos) {
    if(start==NULL) {
        printf("List is empty\n");
        return;
    }

    int count = 1;
    SLL *temp = start;
    SLL *prev = NULL;

    if(pos==1) {
        start = start->next;
        free(temp);
        return;
    }

    while(count<pos) {
        if(temp==NULL) {
            printf("Position not found");
            return;
        }

        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = temp->next;
    free(temp);
}

//SLL* searchNode()

int main() {
    
    for(int i=1; i<=5; i++) {
        insertLast(pow(2,i));
    }

    printf("Linked list : ");
    printList();

    deletePosition(2);
    deletePosition(1);
    deletePosition(2);

    printf("Linked list : ");
    printList();

    return 0;
}