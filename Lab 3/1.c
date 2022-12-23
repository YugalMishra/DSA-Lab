#include <stdio.h>

int main(){
    int arr[10000];
    int max, min, n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if (i == 0){
            max = arr[i];
            min = arr[i];
        }

        else{
            if (arr[i] > max)
                max = arr[i];
            else if (arr[i] < min)
                min = arr[i];
        }
    }

    printf("\nSmallest element: %d", min);
    printf("\nLargest element: %d", max);
    return 0;
}