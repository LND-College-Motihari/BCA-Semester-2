#include <stdio.h>
#define MAX 100

int main() {
    int mat_1[MAX][MAX];
    int mat_2[MAX][MAX];
    int product[MAX][MAX];

    int row1, col1;
    int row2, col2;

    printf("Enter the number of rows and columns of first matrix (in the range of 0-100) : ");
    scanf("%d %d", &row1, &col1);
    
    printf("Enter the number of rows and columns of second matrix (in the range of 0-100) : ");
    scanf("%d %d", &row2, &col2);

    printf("\nEnter the elements of first matrix : \n");
    for(int i=0; i<row1 && i<MAX; i++) {
        for(int j=0; j<col1 && j<MAX; j++) {
            scanf("%d", &mat_1[i][j]);
        }
    }

    printf("\nEnter the elements of second matrix : \n");
    for(int i=0; i<row2 && i<MAX; i++) {
        for(int j=0; j<col2 && j<MAX; j++) {
            scanf("%d", &mat_2[i][j]);
        }
    }

    if(col1 == row2) {
        
        for(int i=0; i<row1; i++) {
            for(int j=0; j<col2; j++) {

                product[i][j] = 0;

                for(int k=0; k<row2; k++) {
                    product[i][j] += mat_1[i][k] * mat_2[k][j];
                }

            }
        }

        printf("\n\nThe product matrix : \n");

        for(int i=0; i<row1; i++) {
            for(int j=0; j<col2; j++) {
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("Matrix multiplication is not possible!");
    }

    return 0;
}