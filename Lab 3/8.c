#include <stdio.h>

int main(){
    int arr[1000];
    int max, min, max_2, min_2;
    int i, j, n;

    printf("Enter number of elements in matrix: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if (i==0){
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

    min_2 = max;
    max_2 = min;
    for (i=0; i<n; i++){
        if ((arr[i] > max_2) && (arr[i] < max))
            max_2 = arr[i];

        if ((arr[i] < min_2) && (arr[i] > min))
            min_2 = arr[i];
    }

    printf("\nThe second smallest element is: %d", min_2);
    printf("\nThe second largest element is: %d", max_2);
    return 0;
}