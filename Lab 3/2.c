#include <stdio.h>

int main(){
    int n, i, temp;
    int arr[10000];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for (i=0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    printf("\nAfter reversal\n");
    printf("Array: ");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}