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
    
    ------------------------------------------------------------------

    VARIABLES USED IN THE PROGRAM :
    
    root : Root node of the tree
    loc - Stores the location of searched element
    Parent - Stores the address of parent node for insertion
    value - Element to be inserted
    newNode - Newly created node for insertion

    track - Local varibale to traverse through the tree for searching
    prev - Previous node which will ultimately become parent node
*/

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} BST;

BST *root = NULL;

void findPosition(int value, BST **loc, BST ** Parent) {
    BST *track, *prev;

    if(root == NULL) {
        *loc = NULL;
        *Parent = NULL;
        return;
    }

    if(root->data == value) {
        *loc = root;
        *Parent = NULL;
        return;
    }

    track = root;
    prev = root;

    if(value < track->data) {
        track = track->left;
    } else {
        track = track->right;
    }

    while(track != NULL) {
        if(track->data == value) {
            *loc = track;
            *Parent = prev;
            return;
        }

        prev = track;

        if(track->data > value) {
            track = track->left;
        } else {
            track = track->right;
        }
    }

    *loc = NULL;
    *Parent = prev;
}

void insertInBST(int value) {
    BST *loc, *Parent, *newNode;
    findPosition(value, &loc, &Parent);
    
    if(loc != NULL) {
        printf("Duplicate value!\n");
        return;
    }

    newNode = (BST*) malloc(sizeof(BST));
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    if(Parent == NULL) {
        root = newNode;
    } else {
        if(Parent->data > value) {
            Parent->left = newNode;
        } else {
            Parent->right = newNode;
        }
    }
}

void caseA(BST *Parent, BST *loc) {
    if(Parent == NULL) {
        root = NULL;
    } else {
        if(Parent->left == loc) {
            Parent->left = NULL;
        } else {
            Parent->right = NULL;
        }
    }
}

void caseB(BST *Parent, BST *loc) {
    BST *ptr;

    if(loc->left != NULL) {
        ptr = loc->left;
    } else {
        ptr = loc->right;
    }

    if(Parent == loc) {
        root = ptr;
    } else if(Parent->left == loc) {
        Parent->left = ptr;
    } else {
        Parent->right = ptr;
    }
}

void caseC(BST *Parent, BST *loc) {
    BST *ptr, *ps, *suc, *parsuc;

    // WTF !!!!!
    // ps = ws;

    ptr = loc->left;

    while(ptr->left != NULL) {
        ps = ptr;
        ptr = ptr->left;
    }

    suc = ptr;
    parsuc = ps;

    if(suc->left == NULL && suc->right == NULL) {
        caseA(parsuc, suc);
    } else {
        caseB(parsuc, suc);
    }

    if(Parent == NULL) {
        root = suc;
    } else {
        if(Parent->left == loc) {
            Parent->left = suc;
        } else {
            Parent->right = suc;
        }
    }

    suc->left = loc->left;
    suc->right = loc->right;
}

void deleteInBST(int target) {
    BST *Parent, *loc;

    if(root == NULL) {
        printf("List is empty!\n");
        return;
    }

    findPosition(target, &Parent, &loc);

    if(loc == NULL) {
        printf("Item not present!\n");
        return;
    }

    if(loc->left == NULL && loc->right == NULL) {
        caseA(Parent, loc);
    }

    if(loc->left != NULL && loc->right != NULL) {
        caseB(Parent, loc);
    }
    
    if(loc->left == NULL && loc->right != NULL) {
        caseB(Parent, loc);
    }
    
    if(loc->left != NULL && loc->right != NULL) {
        caseC(Parent, loc);
    }

    free(loc);
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

    while(1) {
        int value;
        printf("\nEnter the element for insertion in BST (-1 to stop) : ");
        scanf("%d", &value);

        if(value == -1) {
            break;
        }

        insertInBST(value);
    }
    
    printf("\nElements of tree (InOrder) : ");
    inOrderRecurive(root);

    return 0;
}