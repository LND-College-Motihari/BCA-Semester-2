#include <stdio.h>
#define MAX 100

int Stack[MAX];
int top = -1;

void printStack() {
    if(top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack : ");
    for(int i=0; i<=top; i++) {
        printf("%d ", Stack[i]);
    }
    printf("\n");
}

void pushElement(int element) {
    if(top == MAX-1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        Stack[top] = element;
    }
}

void popElement() {
    if(top == -1) {
        printf("Stack underflow!\n");
    } else {
        printf("Element popped = %d\n", Stack[top]);
        top--;
    }
}

void topElement() {
    if(top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element of stack = %d\n", Stack[top]);
    }
}

void reverseStack() {
    if(top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Reversed stack : ");
        for(int i=top; i>=0; i--) {
            printf("%d ", Stack[i]);
        }
        printf("\n");
    }
}

void disposeStack() {
    top = -1;
}

void stackSize() {
    printf("Current size of stack is %d\n", top+1);
}

int main() {

    pushElement(10);
    pushElement(45);
    pushElement(12);
    pushElement(64);

    printStack();
    topElement();
    stackSize();

    return 0;
}




//    main() function in the form of a menu card as per the syllabus of lab portion guided by Mam (Anjna Chaudhary)
/*

    int choice;
    
    printf("--------------------------------------------------");
    printf("\n           Stack - Array representation");
    printf("\n--------------------------------------------------\n\n");

    while(choice != 8) {
        printf("Enter your choice : ");
        printf("\n\t\t1  -  Print stack");
        printf("\n\t\t2  -  Push element");
        printf("\n\t\t3  -  Pop element");
        printf("\n\t\t4  -  Print top element");
        printf("\n\t\t5  -  Print reversed stack");
        printf("\n\t\t6  -  Dispose stack");
        printf("\n\t\t7  -  Print size of stack");
        printf("\n\t\t8  -  Exit\n");

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
                reverseStack();
                break;
            case 6 :
                disposeStack();
                break;
            case 7 :
                stackSize();
                break;
            case 8 :
                break;
            default :
                printf("Enter correct choice!\n");
        }
    }

*/
