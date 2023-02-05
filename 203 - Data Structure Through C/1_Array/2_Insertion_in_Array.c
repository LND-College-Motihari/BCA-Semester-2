#include <stdio.h>
#define MAX 100

void inputArray(int arr[], int n) {
    printf("Enter the elements of the array : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        // scanf("%d", arr++);          If we take the array parameter as pointer
    }
}

void showArray(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    pos - Index number for insertion
    val - Value to be inserted
    noe - Current number of elements in the array
*/
void insertElement(int arr[], int pos, int val, int *noe) {
    if(*noe == MAX) {
        printf("Array is full");
        return;
    }

    for(int i=*noe; i>=pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos] = val;
    *noe = *noe + 1;
}

int main() {
    int noe;        // A variable to keep the track of number of elements in the array
    int arr[100];

    NOE:
    printf("Enter the number of elements of the array : ");
    scanf("%d", &noe);

    if(noe>100 || noe<1) {
        printf("Enter the number of elements in range!\n");
        goto NOE;
    }

    inputArray(arr, noe);
    showArray(arr, noe);

    insertElement(arr, 2, 50, &noe);

    showArray(arr, noe);
    
    return 0;
}