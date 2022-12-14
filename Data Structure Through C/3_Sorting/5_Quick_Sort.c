#include <stdio.h>

void showArray(int arr[], int n) {
    printf("Elements of the array : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
    COMPLEXITY ANALYSIS OF THE ALGORITHM (Quick Sorting of Arrays)

    Time Complexity : 
        Worst Case - O(n^2)
        Average Case - O(nlogn)
        Best Case - O(nlogn)
    Space Complexity - O(n)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    size - Size of the array
    start - First index of the array
    end - Last index of the array
    p - Index of partition element

    temp - Temporary variable used for swaping elements
    pivot - Pivot index
    i, j - Loop counters
*/
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    
    for(int j=start; j<=end-1; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;

    return i+1;
}

void quickSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    showArray(arr, 10);

    quickSort(arr, 0, 9);

    showArray(arr, 10);

    return 0;
}

/*
    Another logic for quick sort explained by Mam (Anjna Chaudhary)
    
    ---------------------------------
    
    VARIABLES USED IN THE FUNCTION : 

    arr - The given array
    lb - Lower bound of the array
    ub - Upper bound of the array
    loc - Index of pivot element

    temp - Temporary variable used for swaping elements
    L - Left most index of working array
    R - Right most index of working array
    done - Flag variable to check the status of the function
*/

/*

void partition(int arr[], int lb, int ub, int *loc) {
    int L=lb, R=ub, done=0, temp;
    *loc = L;

    while(!done) {
        while(arr[*loc]<=arr[R] && *loc!=R) {
            R--;
        }

        if(R == *loc) {
            done = 1;
        } else if(arr[*loc] > arr[R]) {
            temp = arr[*loc];
            arr[*loc] = arr[R];
            arr[R] = temp;
            *loc = R;
        }

        if(!done) {
            while(arr[*loc]>=arr[L] && *loc!=L) {
                L++;
            }

            if(L == *loc) {
                done = 1;
            } else if(arr[*loc] < arr[L]) {
                temp = arr[*loc];
                arr[*loc] = arr[L];
                arr[L] = temp;
                *loc = L;
            }
        }
    }
}

void quickSort(int arr[], int lb, int ub) {
    int loc;

    if(lb < ub) {
        partition(arr, lb, ub, &loc);
        
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
    }
}

*/