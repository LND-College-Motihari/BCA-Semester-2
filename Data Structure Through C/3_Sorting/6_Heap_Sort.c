#include <stdio.h>

void showArray(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Heap Sorting of Arrays)

    Time Complexity - O(nlogn)
    Space Complexity - O(n)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array

    temp - Temporary variable used for swaping elements
    i - Loop counters
    largest - Index of largest element
    left - Index of the left node of the heap
    right - Index of the right node of the heap
*/
int heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<size && arr[left]>arr[largest]) {
        largest = left;
    }

    if(right<size && arr[right]>arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {

    for(int i=size/2-1; i>=0; i--) {
        heapify(arr, size, i);
    }

    for(int i=size-1; i>=0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    showArray(arr, 10);

    heapSort(arr, 10);

    showArray(arr, 10);

    return 0;
}
