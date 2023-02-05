#include <stdio.h>

int main() {
    int count;

    printf("Enter the count of elements in the list for printing : ");
    scanf("%d", &count);

    int first = 0;
    int second = 1;
    int third;

    printf("%d %d", first, second);

    for(int i=2; i<count; i++) {
        third = first + second;

        printf(" %d", third);

        first = second;
        second = third;
    }

    return 0;
}