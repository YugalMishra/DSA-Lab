#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr, i, temp, temp2;
    printf("Enter Number of elements in the array : ");
    scanf("%d", &n);
    arr = (int*)calloc(n, sizeof(int));

    printf("Enter elements of array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    temp = arr[0];
    for (int i = 1; i < n - 1; i++){
        temp2 = arr[i];
        arr[i] = temp * arr[i + 1];
        temp = temp2;
    }

    printf("Resultant array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}