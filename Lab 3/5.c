#include <stdio.h>

int main(){
    int arr[10000], store[10000];
    int n, a, b, i, j = -1;
    int count = 0;
    int index_a;
    
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter required elements a and b: ");
    scanf("%d %d", &a, &b);

    for (i=0; i<n; i++){
        if (arr[i] == a){
            count++;
            index_a = i;
            ++j;
            store[j] = a;
        }

        else if (i > index_a){
            count++;
            ++j;
            store[j] = arr[i];

            if (arr[i] == b)
                break;
        }
    }

    printf("%d and the numbers are: ", count);
    for (i=0; i<=j; i++){
        printf("%d, ", store[i]);
    }

    return 0;
}