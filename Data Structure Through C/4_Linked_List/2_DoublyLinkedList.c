#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} DLL;

DLL *start=NULL, *end=NULL;      // Creating a global empty list to access through all the functions of the program
int count = 0;                  // An integer variable to keep the track of number of elements in the list

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

void insertFirst(int val) {
    DLL *temp;
    temp = (DLL*) malloc(sizeof(DLL));

    temp->data = val;
    temp->next = start;
    temp->prev = NULL;

    if(end==NULL) {
        end = temp;
    } else {
        start->prev = temp;
    }

    start = temp;
    count++;
}

void insertLast(int val) {
    DLL *temp;
    temp = (DLL*) malloc(sizeof(DLL));
    
    temp->data = val;
    temp->prev = end;
    temp->next = NULL;

    // For empty list
    if(start==NULL) {
        start = temp;
    } else {
        end->next = temp;
    }

    end = temp;
    count++;
}

void insertPosition(int pos, int val) {
    // Checking invalid position entries
    if(pos<1 || pos>count+1) {
        printf("Position not found\n");
        return;
    }

    DLL *temp;
    temp = (DLL*) malloc(sizeof(DLL));
    temp->data = val;

    // Handling insertion at first position and start pointer
    if(pos==1) {
        temp->next = start;
        start->prev = temp;
        start = temp;
        count++;
        return;
    }

    int count = 2;
    DLL *track = start;

    while(track!=NULL && count<pos) {
        track = track->next;
        count++;
    }

    // Checking invalid position entries
    if(track==NULL || pos<1) {
        printf("Position not found\n");
        return;
    }

    // Handling insertion at last position with changes in end pointer
    if(track->next == NULL) {
        end = temp;
    } else {
        temp->next->prev = temp;
    }

    temp->next = track->next;
    temp->prev = track;
    track->next = temp;
    count++;
}

void deleteFirst() {
    if(start==NULL) {
        printf("List is empty\n");
        return;
    }

    DLL *temp = start;

    start->next->prev = NULL;
    start = start->next;

    free(temp);
}

void deleteLast() {}

void deletePosition() {}

//SLL* searchNode()

int main() {
    for(int i=1; i<=5; i++) {
        insertLast(pow(2,i));
    }

    insertPosition(6, 30);

    printf("Linked list by start : ");
    printListByStart();
    
    printf("Linked list by end : ");
    printListByEnd();

    
    deleteFirst();
    deleteFirst();
    deleteFirst();
    deleteFirst();
    deleteFirst();
    deleteFirst();


    printf("Linked list by start : ");
    printListByStart();
    
    printf("Linked list by end : ");
    printListByEnd();

    
    insertPosition(1, 30);

    printf("Linked list by start : ");
    printListByStart();
    
    printf("Linked list by end : ");
    printListByEnd();

    return 0;
}