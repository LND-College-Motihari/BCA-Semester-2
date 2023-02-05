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
    
    return 0;
}
