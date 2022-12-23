#include <stdio.h>

int main(){
    int arr[10000];
    int n, i, req;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to be seached: ");
    scanf("%d", &req);

    for (i=0; i<n; i++){
        if (req == arr[i]){
            printf("FOUND at index %d", i);
            break;
        }
    }

    if (i==n)
        printf("NOT FOUND");

    return 0;
}