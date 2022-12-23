#include <stdio.h>

int main(){
    int arr[10000];
    int temp, n, i, j;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for (i=0; i<n; i++){
        for (j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nThe array has been sorted in ascending order.\n");
    printf("Sorted array: ");
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
        
    return 0;
}