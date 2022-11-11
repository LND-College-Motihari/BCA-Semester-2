#include <stdio.h>
#include <stdlib.h>

typedef struct stackLinkedList {
    int data;
    struct stackLinkedList *next;
} Stack;

Stack *s = NULL;

void pushElement(int element) {
    Stack *newNode;
    newNode = (Stack*) malloc(sizeof(Stack));

    newNode->data = element;
    newNode->next = s;
    s = newNode;
}

void popElement() {
    if(s==NULL) {
        printf("Stack underflow!\n");
        return;
    }

    Stack *target = s;
    s = s->next;
    free(target);
}

int main() {
    
    pushElement(10);
    pushElement(45);
    pushElement(12);
    pushElement(64);

    printf("Top element of stack = %d\n", s->data);

    return 0;
}
