#include <stdio.h>
#include <stdlib.h>

/*
    InOrder (Infix Order) Traversal of binary tree
    Algorithm used : LNR (Left - Node - Right)
    
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

void inOrderIterative() {
    Tree *stack[20];
    int top = -1;
    Tree *track = root;

    while(top != -1 || track != NULL) {
        if(track != NULL) {
            stack[++top] = track;
            track = track->left;
        } else {
            track = stack[top--];
            printf("%d ", track->data);
            track = track->right;
        }
    }
}

void inOrderRecurive(Tree *root) {
    if(root == NULL) {
        return;
    }

    inOrderRecurive(root->left);
    printf("%d ", root->data);
    inOrderRecurive(root->right);
}

int main() {
    // Input : 10 15 20 -1 -1 25 -1 -1 30 40 -1 -1 50 -1 -1
    root = buildTree(root);

    printf("\n\n\nElements of tree in InOrder Traversal (Iterative method) : ");
    inOrderIterative();

    printf("\nElements of tree in InOrder Traversal (Recursive method) : ");
    inOrderRecurive(root);

    return 0;
}