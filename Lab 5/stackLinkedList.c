#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} stack;

stack *PUSH(stack *);
stack *POP(stack *);
void display(stack *);

int main(){
    stack *top;
    top = NULL;
    int flag, userInput;
    flag = 1;

    while(flag){
        printf("Enter 1 to push into stack\n");
        printf("Enter 2 to pop out of stack\n");
        printf("Enter any other integer to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userInput);
        switch(userInput){
            case 1:
                top = PUSH(top);
                display(top);
                break;

            case 2:
                top = POP(top);
                display(top);
                break;

            default:
                flag = 0;
                display(top);
                break;
            }
    }

    return 0;
}

stack *PUSH(stack *top){
    stack *new = (stack *) malloc(sizeof(stack));
    printf("Enter data to be pushed: ");
    scanf("%d", &new -> data);
    new -> next = NULL;

    if (top == NULL)
        top = new;

    else{
        new -> next = top;
        top = new;
    }

    return top;
}

stack *POP(stack *top){
    stack *temp = top;
    if (top == NULL){
        printf("STACK UNDERFLOW");
        return top;
    }

    top = top -> next;
    free(temp);
    return top;
}

void display(stack *top){
    stack *ptr = top;
    printf("\nStack: ");
    while (ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n\n");
}