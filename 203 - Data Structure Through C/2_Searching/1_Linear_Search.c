#include <stdio.h>

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Linear Searching of Arrays)

    Time Complexity - O(n)
    Space Complexity - O(1)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array
    val - Value to search for
    i - Loop counter
*/
void linearSearch(int arr[], int size, int val) {
    for(int i=0; i<size; i++) {
        if(arr[i] == val) {
            printf("%d found in the array at position %d\n", val, i+1);
            return;
        }
    }

    printf("%d is not present in the array\n", val);
}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    linearSearch(arr, 10, 15);

    return 0;   
}