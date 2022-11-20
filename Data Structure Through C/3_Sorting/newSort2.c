#include <stdio.h>

void showArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int start, int end) {
    int L=start, R=end, done=0, temp;
    int loc = L;

    while(!done) {
        while(arr[loc]<=arr[R] && loc!=R) {
            R--;
        }

        if(R == loc) {
            done = 1;
        } else if(arr[loc] > arr[R]) {
            temp = arr[loc];
            arr[loc] = arr[R];
            arr[R] = temp;
            loc = R;
        }

        if(!done) {
            while(arr[loc]>=arr[L] && loc!=L) {
                L++;
            }

            if(L == loc) {
                done = 1;
            } else if(arr[loc] < arr[L]) {
                temp = arr[loc];
                arr[loc] = arr[L];
                arr[L] = temp;
                loc = L;
            }
        }
    }

    return loc;
}

int count = 1;

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int loc = partition(arr, start, end);

        printf("%d. loc = %d\n", count, loc);
        showArray(arr, 10);
        count++;

        quickSort(arr, start, loc-1);
        quickSort(arr, loc+1, end);
    }
}

int main() {
    int arr[10] = {7, 9, 15, 49, -87, 0, 21, 54, 16, 76};

    printf("Elements of the array before sorting : ");
    showArray(arr, 10);

    quickSort(arr, 0, 9);

    printf("Elements of the array after sorting : ");
    showArray(arr, 10);

    return 0;
}


