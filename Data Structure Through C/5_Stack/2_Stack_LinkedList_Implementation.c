#include <stdio.h>
#include <stdlib.h>

typedef struct stackLinkedList {
    int data;
    struct stackLinkedList *next;
} Stack;

void pushElement(Stack* st, int element) {
    Stack *Node;
    Node = (Stack*) malloc(sizeof(Stack));

    printf("Step1 : st->data = %d\n", st->data);
    
    Node->data = element;
    Node->next = st;
    st = Node;

    printf("Step2 : Element = %d  &  Node->data = %d  &  st->data = %d  &  Node->next->data = %d\n\n", element, Node->data, st->data, Node->next->data);
}

int main() {
    
    Stack *s = NULL;
    //s.size = 5;
    //s.top = -1;
    //s = (Stack*) malloc(sizeof(Stack));
    //s->next = NULL;
    //s->data = 55;
    //s->data = -1;
    //s->next = NULL;

    //printf("Push call for elemnent = %d  &  s->data = %d  &  s->next->data = %d\n", 10, s->data, s->next->data);
    pushElement(s, 10);
    //printf("Push call for elemnent = %d  &  s->data = %d  &  s->next->data = %d\n", 45, s->data, s->next->data);
    pushElement(s, 45);
    printf("Push call for elemnent = %d  &  s->data = %d  &  s->next->data = %d\n", 12, s->data, s->next->data);
    pushElement(s, 12);
    printf("Push call for elemnent = %d  &  s->data = %d  &  s->next->data = %d\n", 64, s->data, s->next->data);
    pushElement(s, 64);

    printf("Top element of stack = %d\n", s->data);
    return 0;
}
