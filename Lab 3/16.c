#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, odd, even, i;
    printf("Enter Number of elements in the array : ");
    scanf("%d", &n);
    int* arr = (int*) calloc(n, sizeof(int));
    int* res = (int*) calloc(n, sizeof(int));

    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    odd = n - 1;
    even = 0;

    for (i = 0; i < n; i++){
        if (arr[i] % 2 == 0){
            res[even] = arr[i];
            even++;    
        }
        else{
            res[odd] = arr[i];
            odd--;
        }
    }

    printf("\nResultant array: ");
    for (i = 0; i < n; i++)
        printf("%d ", res[i]);

    free(arr);
    free(res);
    return 0;
}