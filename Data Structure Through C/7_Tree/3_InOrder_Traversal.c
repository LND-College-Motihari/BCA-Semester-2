#include <stdio.h>
#include <stdlib.h>

/*
    A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned property −
    left_subtree (Data items) <= node (Data item) <= right_subtree (Data items)

    ------------------------------------------------------------------

    BST : A structure variable containing three elements - data, left & right
    BST->data : Stores the data of that particular node
    BST->left : Stores the address of left child of that particular node
    BST->right : Stores the address of right child of that particular node
    
    ---------------------------------

    InOrder (Infix Order) Traversal of binary search tree
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

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} BST;

BST *root = NULL;

BST* buildBST(BST *root) {
    int value;
    printf("Enter the value (-1 for NULL) : ");
    scanf("%d", &value);

    if(value == -1) {
        return NULL;
    }

    root = (BST*) malloc(sizeof(BST*));
    root->data = value;
    root->left = NULL;
    root->right = NULL;

    if(value == -1) {
        return NULL;
    }

    printf("Left child of %d - ", value);
    root->left = buildBST(root->left);

    printf("Right child of %d - ", value);
    root->right = buildBST(root->right);

    return root;
}

void inOrderIterative() {
    BST *stack[20];
    int top = -1;
    BST *track = root;

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

void inOrderRecurive(BST *root) {
    if(root == NULL) {
        return;
    }

    inOrderRecurive(root->left);
    printf("%d ", root->data);
    inOrderRecurive(root->right);
}

int main() {
    // Input : 10 15 20 -1 -1 25 -1 -1 30 40 -1 -1 50 -1 -1
    root = buildBST(root);

    printf("\n\n\nElements of tree in InOrder Traversal (Iterative method) : ");
    inOrderIterative();

    printf("\nElements of tree in InOrder Traversal (Recursive method) : ");
    inOrderRecurive(root);

    return 0;
}
