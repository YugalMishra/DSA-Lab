#include <stdio.h>

int Triplet(int arr[][20], int trip[][3], int size, int count){
    int i, j, k=1;
    trip[0][0] = size;
    trip[0][1] = size;
    trip[0][2] = count;
    for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            if (arr[i][j] != 0){
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = arr[i][j];
                k++;
            }
        }
    }
    return k;
}

int addSparse(int trip1[][3], int trip2[][3], int res[][3], int size1, int size2){
    int i, j, k=1, count=0;
    i = j = 1;
    res[0][0] = trip1[0][0];
    res[0][1] = trip2[0][1];
    while(i<=size1 || j<=size2){
        if(trip1[i][2] != 0 && trip2[j][2] != 0){
            if (trip1[i][0] == trip2[j][0]){
                if(trip1[i][1] == trip2[j][1]){
                    res[k][0] = trip1[i][0];
                    res[k][1] = trip1[i][1];
                    res[k][2] = trip1[i][2] + trip2[j][2];
                    i++; j++; k++; count++;
                }

                else if (trip1[i][1] > trip2[j][1]){
                    res[k][0] = trip2[j][0];
                    res[k][1] = trip2[j][1];
                    res[k][2] = trip2[j][2];
                    j++;  k++; count++;
                }

                else{
                    res[k][0] = trip1[j][0];
                    res[k][1] = trip1[j][1];
                    res[k][2] = trip1[j][2];
                    i++; k++; count++;
                }
            }

            else if(trip1[i][0] > trip2[j][0]){
                    res[k][0] = trip2[j][0];
                    res[k][1] = trip2[j][1];
                    res[k][2] = trip2[j][2];
                    j++; k++; count++;
            }

            else{
                    res[k][0] = trip1[i][0];
                    res[k][1] = trip1[i][1];
                    res[k][2] = trip1[i][2];
                    i++; k++; count++;
            }
        }

        else if (trip1[i][2] == trip2[j][2]){
            i++; j++;
        }
        else if (trip1[i][2] == 0)
            i++;
        else
            j++;
    }
    res[0][2] = count;
    return k;
}

int main(){
    int i, j;
    int size, count = 0;
    int arr1[20][20], arr2[20][20];
    int trip1[20][3] = {0}, trip2[20][3] = {0}, result[41][3];
    printf("Enter size of square matrix: ");
    scanf("%d", &size);
    printf("For first matrix: \n");
    printf("\nEnter array elements\n");
    for (i=0; i<size; i++){
        printf("Row %d\n", i+1);
        for (j=0; j<size; j++){
            scanf("%d", &arr1[i][j]);
            if (arr1[i][j] != 0)
                count++;
        }
    }
    int tripSize1 = Triplet(arr1, trip1, size, count);

    count = 0;
    printf("\nFor second matrix: \n");
    printf("\nEnter array elements\n");
    for (i=0; i<size; i++){
        printf("Row %d\n", i+1);
        for (j=0; j<size; j++){
            scanf("%d", &arr2[i][j]);
            if (arr2[i][j] != 0)
                count++;
        }
    }
    int tripSize2 = Triplet(arr2, trip2, size, count);

    printf("\nArray 1: \n");
    for(i=0; i<tripSize1; i++){
        for(j=0; j<3; j++)
            printf("%d ", trip1[i][j]);
        printf("\n");
    }

    printf("\nArray 2: \n");
    for(i=0; i<tripSize2; i++){
        for(j=0; j<3; j++)
            printf("%d ", trip2[i][j]);
        printf("\n");
    }

    size = addSparse(trip1, trip2, result, tripSize1, tripSize2);
    printf("\nSum of arrays: \n");
    for(i=0; i<size; i++){
        for(j=0; j<3; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}