#include <stdio.h>
int main(){
    void push(int *, int *, int);
    void pop(int *, int *, int);
    void display(int *, int *);

    int stack[5];
    int *top, userInput, maxSize = 4;
    int temp, flag = 1;
    top = &temp;
    *top = -1;

    while (flag){
        printf("Press 1 to push into stack\n");
        printf("Enter 2 to pop out of stack\n");
        printf("Enter any other integer to exit\n");
        printf("Your choice: ");
        scanf("%d", &userInput);
        switch (userInput) {
            case 1:
                push(stack, top, maxSize);
                display(stack, top);
                break;
            
            case 2:
                pop(stack, top, maxSize);
                display(stack, top);
                break;

            default:
                flag = 0;
                display(stack, top);
                break;
        }
    }

}

void push(int *stack, int *top, int maxSize){
    if (*top == maxSize){
        printf("STACK OVERFLOW\n");
        return;
    }

    int value;
    (*top)++;
    stack += *top;
    printf("Enter value to be pushed into stack: ");
    scanf("%d", &value);
    *stack = value;
}

void pop(int *stack, int *top, int maxSize){
    if (*top == -1){
        printf("STACK UNDERFLOW\n");
        return;
    }

    stack += *top;
    (*top)--;
    printf("%d popped\n", *stack);
}

void display(int *stack, int *top){
    printf("Stack: ");
    for (int i=0; i<=*top; i++){
        printf("%d ", *stack);
        stack++;
    }
    printf("\n\n");
}