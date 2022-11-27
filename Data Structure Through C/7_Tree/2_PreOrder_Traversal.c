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

    PreOrder (Prefix Order) Traversal of binary search tree
    Algorithm used : NLR (Node - Left - Right)
    
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

void preOrderIterative() {
    BST *stack[20];
    int top = -1;
    stack[++top] = root;

    BST *track = root;

    while(top >= 0) {
        track = stack[top--];

        if(track != NULL) {
            printf("%d ", track->data);
            
            if(track->right != NULL) {
                stack[++top] = track->right;
            }

            if(track->left != NULL) {
                stack[++top] = track->left;
            }
        }
    }
}

void preOrderRecurive(BST *root) {
    if(root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrderRecurive(root->left);
    preOrderRecurive(root->right);
}

int main() {
    // Input : 10 15 20 -1 -1 25 -1 -1 30 40 -1 -1 50 -1 -1
    root = buildBST(root);

    printf("\n\n\nElements of tree in PreOrder Traversal (Iterative method) : ");
    preOrderIterative();

    printf("\nElements of tree in PreOrder Traversal (Recursive method) : ");
    preOrderRecurive(root);

    return 0;
}
