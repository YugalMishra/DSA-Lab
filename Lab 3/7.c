#include <stdio.h>

int main(){
    int numOfNonZeroEle(int arr[][100], int);
    int sumAboveLeadDiag(int arr[][100], int);
    void disBelowMinDiag(int arr[][100], int);
    int prodDiagEle(int arr[][100], int);
    int A[100][100];
    int n, i, j, userInput;
    char continueInput = 'y';

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i=0; i<n; i++){
        printf("For row %d (Enter %d elements):\n", i+1, n);
        for (j=0; j<n; j++){
            scanf("%d", &A[i][j]); 
        }
    }

    while ((continueInput == 'y') || (continueInput == 'Y')){
        printf("\nEnter 1 to find number of non zero elements in square matrix.\n");
        printf("Enter 2 to find the sum of elements above leading diagonal.\n");
        printf("Enter 3 to display the elements below the minor diagonal.\n");
        printf("Enter 4 to find the product of the diagonal elements.\n");
        printf("Your input: ");
        scanf("%d", &userInput);

        if (userInput == 1)
            printf("\nNumber of non zero elements: %d", numOfNonZeroEle(A, n));
        else if (userInput == 2)
            printf("\nSum of elements above leading diagonal: %d", sumAboveLeadDiag(A, n));
        else if (userInput == 3)
            disBelowMinDiag(A, n);
        else if (userInput == 4)
            printf("\nProduct of diagonal elements: %d", prodDiagEle(A, n));

        printf("\nWould you like to continue (y/n): ");
        getchar();
        scanf("%c", &userInput);
    }

    return 0;
}


//i)
int numOfNonZeroEle(int arr[][100], int size){
    int i, j, count = 0;
    for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            if (arr[i] != 0)
                count++;
        }
    }
    return count;
}


//ii)
int sumAboveLeadDiag(int arr[][100], int size){
    int i, j, sum = 0;
    for (i=0; i<size-1; i++){
        for (j=i+1; j<size; j++){
            if (j>i)
                sum += arr[i][j];
        }
    }
    return sum;
}


//iii)
void disBelowMinDiag(int arr[][100], int size){
    int i, j;
    printf("\n");
    for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            if (i+j >= size)
                printf("%d   ", arr[i][j]);
            else
                printf("    ");
        }
        printf("\n");
    }
}


//iv)
int prodDiagEle(int arr[][100], int size){
    int i, j, prod = 1;
    for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            if ((i==j) || (i+j == size-1))
                prod *= arr[i][j];
        }
    }
    return prod;
}