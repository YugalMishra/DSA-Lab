#include <stdio.h>
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Content of B1 is: %d\n", (num>>24)&255);
    printf("Content of B2 is: %d\n", (num>>16)&255);
    printf("Content of B3 is: %d\n", (num>>8)&255);
    printf("Content of B4 is: %d\n", (num)&255);
    return 0;
}