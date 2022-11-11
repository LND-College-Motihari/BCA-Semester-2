#include <stdio.h>
#include <stdlib.h>

typedef struct stackArray {
    int top;
    int size;
    int *arr;
} Stack;

void pushElement(Stack* st, int element) {
    if(st->size - st->top > 1) {
        st->top++;
        st->arr[st->top] = element;
    } else {
        printf("Stack overflow!\n");
    }
}

void popElement(Stack* st) {
    if(st->top == -1) {
        printf("Stack underflow!\n");
    } else {
        st->top--;
    }
}

int main() {
    
    Stack s;
    s.size = 5;
    s.top = -1;
    s.arr = (int*) malloc(s.size * sizeof(int));

    pushElement(&s, 10);
    pushElement(&s, 45);
    pushElement(&s, 12);
    pushElement(&s, 64);

    printf("Top element of stack = %d\n", s.arr[s.top]);

    return 0;
}
