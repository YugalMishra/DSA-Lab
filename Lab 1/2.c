#include <stdio.h>
int main(){
    int B1, B2, B3, B4, num;
    printf("Enter content of 1st byte: ");
    scanf("%d", &B1);
    printf("Enter content of 2nd byte: ");
    scanf("%d", &B2);
    printf("Enter content of 3rd byte: ");
    scanf("%d", &B3);
    printf("Enter content of 4th byte: ");
    scanf("%d", &B4);

    B1 = B1<<24;
    B2 = B2<<16;
    B3 = B3<<8;
    printf("%d", B1|B2|B3|B4);
    return 0;
}