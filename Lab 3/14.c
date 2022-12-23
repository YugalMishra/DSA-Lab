#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr, *res, i;
    int ones, zeroes;

    printf("Enter Number of elements in the array : ");
    scanf("%d", &n);
    arr = (int*) calloc(n, sizeof(int));
    res = (int*) calloc(n, sizeof(int));

    printf("Enter binary elements into array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ones = n - 1;
    zeroes = 0;

    for (i = 0; i < n; i++){
        if (arr[i] == 0){
            res[zeroes] = arr[i];
            zeroes++;
        }
        else{
            res[ones] = arr[i];
            ones--;
        }
    }

    printf("Resultant array: ");
    for (i = 0; i < n; i++)
        printf("%d ", res[i]);
    
    free(arr);
    free(res);
    return 0;
}