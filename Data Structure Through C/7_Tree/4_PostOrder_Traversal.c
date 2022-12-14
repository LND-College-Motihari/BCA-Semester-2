#include <stdio.h>
#include <stdlib.h>

/*
    PostOrder (Postfix Order) Traversal of binary tree
    Algorithm used : LRN (Left - Right - Node)
    
    ---------------------------------

    VARIABLES USED IN THE PROGRAM :
    
    root : Root node of the tree
    Node->data : Stores the data of that particular node
    Node->left : Stores the address of left child of that particular node
    Node->right : Stores the address of right child of that particular node

    stack : An array based stack type (LIFO) structure to store address of nodes
    top : Index of top element of the stack

    track : A temporary variable used for traversing through the tree
*/

typedef struct Node {
    int data;
    struct Node *left, *right;
} Tree;

Tree *root = NULL;

Tree* buildTree(Tree *root) {
    int value;
    printf("Enter the value (-1 for NULL) : ");
    scanf("%d", &value);

    if(value == -1) {
        return NULL;
    }

    root = (Tree*) malloc(sizeof(Tree*));
    root->data = value;
    root->left = NULL;
    root->right = NULL;

    if(value == -1) {
        return NULL;
    }

    printf("Left child of %d - ", value);
    root->left = buildTree(root->left);

    printf("Right child of %d - ", value);
    root->right = buildTree(root->right);

    return root;
}

void postOrderIterative() {
    Tree *stack[20];
    int FS[20];

    int top = -1;
    int TP = -1;

    Tree *ptr = root;
    stack[++top] = NULL;

    while(ptr != NULL) {
        stack[++top] = ptr;
        FS[top] = 1;

        if(ptr->right != NULL) {
            stack[++top] = ptr->right;
            FS[top] = -1;
        }

        ptr = ptr->left;
        TP = top;
        ptr = stack[top--];

        while(FS[TP] == 1) {
            printf("%d ", ptr->data);
            TP = TP - 1;
            ptr = stack[top];
        }
    }

    while(ptr != NULL) {
        stack[++top] = ptr;

        if(ptr->left == NULL && ptr->right == NULL) {
            printf("%d ", ptr->data);
        }

        if(ptr->left != NULL) {
            ptr = ptr->left;
            stack[++top] = ptr;
        } else if(ptr->right != NULL) {
            ptr = ptr->right;
            stack[++top] = ptr;
        }
    }
}

void postOrderRecurive(Tree *root) {
    if(root == NULL) {
        return;
    }

    postOrderRecurive(root->left);
    postOrderRecurive(root->right);
    printf("%d ", root->data);
}

int main() {
    // Input : 10 15 20 -1 -1 25 -1 -1 30 40 -1 -1 50 -1 -1
    root = buildTree(root);

    printf("\n\n\nElements of tree in PostOrder Traversal (Iterative method) : ");
    //postOrderIterative();

    printf("\nElements of tree in PostOrder Traversal (Recursive method) : ");
    postOrderRecurive(root);

    return 0;
}