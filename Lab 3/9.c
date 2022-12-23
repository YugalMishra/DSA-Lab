#include <stdio.h>

int main(){
    int arr[1000], sortedArr[1000];
    int i, n, j=0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements into array:\n");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0){
            sortedArr[j] = arr[i];
            j++;
        }
    }

    for (i=0; i<n; i++){
        if (arr[i] % 2 != 0){
            sortedArr[j] = arr[i];
            j++;
        }
    }

    printf("Required array: ");
    for (i=0; i<j; i++){
        printf("%d ", sortedArr[i]);
    }
    return 0;
}