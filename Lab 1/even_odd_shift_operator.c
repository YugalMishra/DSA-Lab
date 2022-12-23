#include <stdio.h>

int main(){
    int num, temp;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    if ((num>>1<<1) != temp)
        printf("ODD");
    else
        printf("EVEN");

    return 0;
}