#include <stdio.h>

int main(){
    int n, i, j, element;
    int magicMatrix[15][15];
    int valid = 0;

    do{
        printf("Enter the size of magic matrix (odd size only): ");
        scanf("%d", &n);
        if (n%2 != 0)
            valid = 1;
        else
            printf("INVALID INPUT\n\n");
    } while (valid == 0);

    i = n-1;
    j = n/2;
    element = 1;
    while (element < (n*n)+1){
        magicMatrix[i][j] = element;
            
        if (element % n == 0)
            i--;

        else{
            if ((i == n-1) && (j == 0))
                i--;
            else if (i==n-1){
                i = 0;
                j--;
            }
            else if (j == 0){
                j = n-1;
                i++;
            }
            else{
                j--;
                i++;
            }
        }
        element++;
    } 

    printf("\nThe magic matrix of %dx%d is :\n", n, n);
    for (i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d", magicMatrix[i][j]);
            if (magicMatrix[i][j] < 10)
                printf("   ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}