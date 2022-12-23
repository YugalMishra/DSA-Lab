#include <stdio.h>

int main(){
    int arr[10000], NGE[10000];
    int n, i, j;
    
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            if (arr[j] > arr[i]){
                NGE[i] = arr[j];
                break;   
            }
        }

        if (j==n)
            NGE[i] = -1;
    }
        

    printf("\nArray\tNext Greater Element\n");
    for (i=0; i<n; i++){
        printf("%d\t\t%d\n", arr[i], NGE[i]);
    }

    return 0;
}