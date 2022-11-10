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

void insertFirst(int val) {
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

void insertLast(int val) {
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

void insertPosition(int pos, int val) {
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

void deletePosition(int pos) {
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
        insertLast(pow(2,i));
    }

    printf("Linked list by start : ");
    printListByStart();
    
    printf("Linked list by end : ");
    printListByEnd();
    
    return 0;
}
