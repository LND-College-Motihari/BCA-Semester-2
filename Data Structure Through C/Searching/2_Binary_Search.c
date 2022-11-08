#include <stdio.h>

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Binary Searching of Arrays)

    Time Complexity - O(logn)
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array
    val - Value to search for
    low, high - Two pointers to access both ends of the array
    mid - Middle element to compare both parts of the array
*/
void binarySearch(int arr[], int size, int val) {
    int low = 0;
    int high = size-1;

    while(low <= high) {
        int mid = (high+low) / 2;

        if(arr[mid] == val) {
            printf("%d found in the array at position %d\n", val, mid+1);
            return;
        }

        if(arr[mid] > val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d is not present in the array\n", val);
}

int main() {
    int arr[10] = {7, 9, 15, 19, 29, 47, 79, 87, 88, 95};

    binarySearch(arr, 10, 15);

    return 0;   
}