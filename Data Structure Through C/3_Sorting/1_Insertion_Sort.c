#include <stdio.h>

void showArray(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Insertion Sorting of Arrays)

    Time Complexity - O(n^2)
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array
    i, j - Loop counters
    temp - Temporary variable to store the current element for insertion
*/
void insertionSort(int arr[], int size) {

    for(int i=1; i<=size; i++) {
        int temp = arr[i];
        int j = i-1;

        while(arr[j]>temp && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }

}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    showArray(arr, 10);

    insertionSort(arr, 10);

    showArray(arr, 10);

    return 0;
}
