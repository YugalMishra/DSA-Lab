/*
1) Implement double circular linked list. Add a new node at 
last without using any secondary or any temporary pointer.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
} LL;

void input(LL *);
void display(LL *);
void insertLast(LL *);
void menu(LL *);

int main(){
    LL *Head, *new;
    new = (LL *) malloc(sizeof(LL));
    Head = NULL;

    printf("Enter first element into linked list: ");
    scanf("%d", &new->data);
    Head = new;
    new -> next = Head;
    new -> prev = Head;

    menu(Head);
    return 0;
}

void menu(LL *Head){
    int userInput;
    do{
        printf("\nEnter 1 to input data\n");
        printf("Enter 2 to display data\n");
        printf("Enter 3 to insert element at end\n");

        printf("Enter any other integer to exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1:
                input(Head);
                break;
            case 2:
                display(Head);
                break;
            case 3:
                insertLast(Head);
                break;
            default:
                exit(0);
        }

    } while (1);
    display(Head);
}

void input(LL *Head){
    LL *ptr, *new;
    char ch;
    ptr = Head;
    do{
        new = (LL *) malloc(sizeof(LL));
        new -> prev = ptr;
        ptr -> next = new;
        new -> next = Head;

        printf("Enter element into linked list: ");
        scanf("%d", &new->data);
        ptr = ptr->next;

        printf("Do you want to continue (Y/N): ");
        getchar();
        ch = getchar();
    }while ((ch == 'y') || (ch == 'Y'));

    Head -> prev = ptr;
}

void display(LL *Head){
    LL *ptr = Head;
    printf("\nData: ");
    do{
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }while (ptr != Head);
    printf("%d\n", ptr->data);

    ptr = Head -> prev;
    printf("Reversed Data: ");
    while (ptr != Head){
        printf("%d ", ptr -> data);
        ptr = ptr -> prev;
    }
    printf("%d %d\n", ptr->data, ptr->prev->data);
}

void insertLast(LL* Head){
    LL *new = (LL *) malloc(sizeof(LL));
    new -> next = Head;
    new -> prev = Head -> prev;
    Head -> prev -> next = new;
    Head -> prev = new;

    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
}