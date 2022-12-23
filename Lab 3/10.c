#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr;
    int n, i, j;
    
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    arr = (int*) calloc(n, sizeof(int));

    printf("Enter array elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            if (arr[j] > arr[i]){
                arr[i] = arr[j];
                break;   
            }
        }
    }
        
    printf("\nAltered Array: ");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}