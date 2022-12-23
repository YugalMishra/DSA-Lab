// 5) WAP to implement queue using stack

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void deQueue(int);
void enQueue(int);
void push1();
void push2();
int pop1();
int pop2();
void display();

int stack1[MAXSIZE], stack2[MAXSIZE];
int top1, top2;

void main(){
    top1 = top2 = -1;
    int userInput, count = -1;
    
    while(1){
        printf("\n--------------------------------\n");
        printf("1: To ENQUEUE\n");
        printf("2: To DEQUEUE\n");
        printf("3: To display queue elements\n");
        printf("0: To exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &userInput);

        switch (userInput){
            case 1:
                count++;
                enQueue(count);
                break;
            case 2:
                count--;
                deQueue(count);
                break;
            case 3:
                display(count);
                break;
            case 0:
                exit(0);
            default:
                printf("INVALID CHOICE\n");
        }
    }
}

void enQueue(int count){
    if (top1 == MAXSIZE){
        printf("QUEUE OVERFLOW\n");
        return;
    }

    int ele;
    printf("Enter element to be enqueued: ");
    scanf("%d", &ele);

    if (count == 0)
        stack1[++top1] = ele;

    else{
        for (int i=0; i<count; i++)
            push2(pop1());
        top1 = 0;
        stack1[top1] = ele;
        for (int i=0; i<count; i++)
            push1(pop2());
    }
}

void deQueue(int count){
    if (top1 == -1){
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    printf("%d dequeued\n", pop1());
}

int pop1(){
    return stack1[top1--];
}

int pop2(){
    return stack2[top2--];
}

void push1(int ele){
    stack1[++top1] = ele;
}

void push2(int ele){
    stack2[++top2] = ele;
}

void display(int count){
    for (int i=top1; i>=0; i--)
        printf("%d ", stack1[i]);
    printf("\n");
}