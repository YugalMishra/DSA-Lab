#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr, i, max, count;
    printf("Enter Number of elements in the array : ");
    scanf("%d", &n);
    arr = (int*) calloc (n, sizeof(int));

    printf("Enter elements : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = 0;
    count = 0;

    for (i = 0; i < n; i++){
        if (arr[i] > max) {
            count = 1;
            max = arr[i];
        }
        
        else if (arr[i] == max)
            count++;
    }

    printf("\nLargest element : %d\n", max);
    printf("Number of occurrences : %d\n", count);
    free(arr);
    return 0;
}