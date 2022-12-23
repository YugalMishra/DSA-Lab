#include <stdio.h>
int main(){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num/2*2 == num)
        printf("EVEN");
    else
        printf("ODD");
    return 0;
}