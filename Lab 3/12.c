#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, *arr;
    int i, j, temp;
    int count = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = (int*) calloc(n, sizeof(int));

    printf("Enter array elements:\n");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    for (i=0; i<n-1; i++){
        for (j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (i=0; i<n-1; i++){
        if (arr[i]!=arr[i+1])
            count++;
        if (count == k){
            printf("\nThe second smallest element is: %d\n", arr[i]);
            break;
        }
    }

    count = 0;
    for (i=n-1; i>0; i--){
        if (arr[i]!=arr[i-1])
            count++;
        if (count == k){
            printf("The second largest element is: %d", arr[i]);
            break;
        }
    }

    return 0;
}