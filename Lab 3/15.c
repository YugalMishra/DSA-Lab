#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[100][100];
    int i, j, r, c, temp;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter array elements:\n");
    for (i=0; i<r; i++){
        printf("Enter %d elements:\n", c);
        for (j=0; j<c; j++)
           scanf("%d", &arr[i][j]);
    }

    for (j=0; j<c/2; j++){
        for (i=0; i<r; i++){
            temp = arr[i][j];
            arr[i][j] = arr[i][c-j-1];
            arr[i][c-j-1] = temp;
        }
    }

    printf("\n");
    for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}