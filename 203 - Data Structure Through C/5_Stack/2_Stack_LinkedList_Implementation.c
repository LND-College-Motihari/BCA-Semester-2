#include <stdio.h>
#include <stdlib.h>

typedef struct stackLinkedList {
    int data;
    struct stackLinkedList *next;
} Stack;

Stack *top = NULL;

void printStack() {
    if(top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack : ");
    Stack *temp = top;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void pushElement(int element) {
    Stack *newNode;
    newNode = (Stack*) malloc(sizeof(Stack));

    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

void popElement() {
    if(top == NULL) {
        printf("Stack underflow!\n");
        return;
    }

    Stack *target = top;
    top = top->next;

    printf("Element popped = %d\n", target->data);
    free(target);
}

void topElement() {
    if(top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element of stack = %d\n", top->data);
    }
}

void disposeStack() {
    top = NULL;
}

int main() {

    pushElement(10);
    pushElement(45);
    pushElement(12);
    pushElement(64);

    printStack();
    topElement();

    return 0;
}




//    main() function in the form of a menu card as per the syllabus of lab portion guided by Mam (Anjna Chaudhary)
/*

    int choice;
    
    printf("----------------------------------------------------------");
    printf("\n           Stack - Linked list representation");
    printf("\n----------------------------------------------------------\n\n");

    while(choice != 6) {
        printf("Enter your choice : ");
        printf("\n\t\t1  -  Print stack");
        printf("\n\t\t2  -  Push element");
        printf("\n\t\t3  -  Pop element");
        printf("\n\t\t4  -  Print top element");
        printf("\n\t\t5  -  Dispose stack");
        printf("\n\t\t6  -  Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printStack();
                break;
            case 2 : {
                int element;
                printf("Enter an element for pushing operation : ");
                scanf("%d", &element);
                pushElement(element);
                break;
            }
            case 3 :
                popElement();
                break;
            case 4 :
                topElement();
                break;
            case 5 :
                disposeStack();
                break;
            case 6 :
                break;
            default :
                printf("Enter correct choice!\n");
        }
    }

*/
