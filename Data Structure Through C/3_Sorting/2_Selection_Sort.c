#include <stdio.h>

void showArray(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Selection Sorting of Arrays)

    Time Complexity - O(n^2) {Best case -  O(n)}
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array
    i, j - Loop counters
    minIndex - Index of current smallest element in the array
    temp - Temporary variable used for swaping elements
*/
void selectionSort(int arr[], int size) {
    
    for(int i=0; i<size-1; i++) {
        int minIndex = i;

        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    showArray(arr, 10);

    selectionSort(arr, 10);

    showArray(arr, 10);

    return 0;
}
