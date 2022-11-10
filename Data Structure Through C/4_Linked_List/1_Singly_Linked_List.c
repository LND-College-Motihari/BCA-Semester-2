#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void insertFirst(int val) {
    SLL *newNode;
    newNode = (SLL*) malloc(sizeof(SLL));
    
    newNode->data = val;
    newNode->next = start;
    start = newNode;
}

void insertLast(int val) {
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

void insertPosition(int pos, int val) {
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
    free(target);
}

void deletePosition(int pos) {
    if(start==NULL) {
        printf("List is empty - Nothing to delete!\n");
        return;
    }
    
    int flag = 1;
    SLL *track = start;
    SLL *prev = NULL;

    if(pos==1) {
        start = start->next;
        free(track);
        return;
    }

    while(flag<pos) {
        if(track==NULL) {
            printf("Position not found");
            return;
        }

        prev = track;
        track = track->next;
        flag++;
    }

    prev->next = track->next;
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

int main() {
    for(int i=1; i<=5; i++) {
        insertLast(pow(2,i));
    }

    printf("Linked list : ");
    printList();

    return 0;
}
