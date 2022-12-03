#include <stdio.h>

// Pass by reference method
void changeValues(int *num1, int *num2) {
    *num1 = *num1 * 10;
    *num2 = *num2 * 10;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    printf("Before changing values : num1 = %d & num2 = %d\n", num1, num2);

    changeValues(&num1, &num2);

    printf("Before changing values : num1 = %d & num2 = %d\n", num1, num2);

    return 0;
}