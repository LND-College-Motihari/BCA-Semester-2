#include <stdio.h>

void showArray(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Flag Sorting of Arrays)

    Time Complexity - O(n^2) {Best case -  O(n)}
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array
    flag - Flag variable to check whether the array is sorted or not in that particular iteration
    i, j - Loop counters
*/
void flagSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        int flag = 1;

        for(int j=i+1; j<size; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                flag = 0;
            }
        }

        if(flag)
            return;
    }
}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    showArray(arr, 10);

    flagSort(arr, 10);

    showArray(arr, 10);

    return 0;
}
