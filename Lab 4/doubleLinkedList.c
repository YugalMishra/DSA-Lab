//Everything about Double Linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
} LL;

LL* input(LL *Head);
void display(LL *, LL*);
LL* insertFirst(LL *);
void insertPos(LL *);
LL* insertLast(LL *);
LL* delFirst(LL *);
LL* delLast(LL *);
void delPos(LL *);
void menu(LL *Head);

int main(){
    LL *Head, *new, *ptr;
    new = (LL *) malloc(sizeof(LL));
    Head = NULL;

    printf("Enter first element into linked list: ");
    scanf("%d", &new->data);
    Head = new;
    ptr = Head;
    new -> next = NULL;
    new -> prev = NULL;

    menu(Head);
    return 0;
}

void menu(LL *Head){
    int userInput, flag = 1;
    LL *Tail;
    char ch;
    do{
        printf("\nEnter 1 to input data\n");
        printf("Enter 2 to display data\n");
        printf("Enter 3 to insert element at beginnning\n");
        printf("Enter 4 to insert element at end\n");
        printf("Enter 5 to insert element at position\n");
        printf("Enter 6 to delete first element\n");
        printf("Enter 7 to delete last element\n");
        printf("Enter 8 to delete element from position\n");

        printf("Enter any other integer to exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1:
                Tail = input(Head);
                break;
            case 2:
                display(Head, Tail);
                break;
            case 3:
                Head = insertFirst(Head);
                display(Head, Tail);
                break;
            case 4:
                Tail = insertLast(Tail);
                display(Head, Tail);
                break;
            case 5:
                insertPos(Head);
                display(Head, Tail);
                break;
            case 6:
                Head = delFirst(Head);
                display(Head, Tail);
                break;
            case 7:
                Tail = delLast(Tail);
                display(Head, Tail);
                break;
            case 8:
                delPos(Head);
                display(Head, Tail);
                break;
            default:
                flag = 0;
                break;
        }

    } while (flag);
    display(Head, Tail);
}

LL* input(LL *Head){
    LL *ptr, *new, *Tail;
    char ch;
    ptr = Head;
    do{
        new = (LL *) malloc(sizeof(LL));
        new -> prev = ptr;
        ptr -> next = new;
        new -> next = NULL;

        printf("Enter elements into linked list: ");
        scanf("%d", &new->data);
        ptr = ptr->next;

        printf("Do you want to continue (Y/N): ");
        getchar();
        ch = getchar();
    }while ((ch == 'y') || (ch == 'Y'));

    Tail = ptr;
    return Tail;
}

void display(LL *Head, LL* Tail){
    LL *ptr = Head;
    printf("\nData: ");
    while (ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }

    ptr = Tail;
    printf("\nReversed Data: ");
    while (ptr != Head){
        printf("%d ", ptr -> data);
        ptr = ptr -> prev;
    }
    printf("%d\n", Head -> data);
}


LL* insertFirst(LL *head){
    LL *new;
    new = (LL *) malloc(sizeof(LL));
    new -> prev = NULL;
    new -> next = head;
    head -> prev = new;
    head = new;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return head;
}

LL* insertLast(LL *Tail){
    LL *new;
    new = (LL *) malloc(sizeof(LL));
    Tail -> next = new;
    new -> prev = Tail;
    new -> next = NULL;
    Tail = new;

    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return Tail;
}

void insertPos(LL *head){
    LL *new, *ptr;
    int pos, count = 0;
    ptr = head;
    new = (LL *) malloc(sizeof(LL));

    printf("Enter position at which element is to be inserted: ");
    scanf("%d", &pos);    
    while((ptr != NULL) && (count<pos-2)){
        ptr = ptr->next;
        count++;
    }
    
    ptr -> next -> prev = new;
    new -> next = ptr -> next;
    new -> prev = ptr;
    ptr -> next = new;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
}

LL* delFirst(LL * Head){
    LL *temp;
    temp = Head;
    Head = Head -> next;
    Head -> prev = NULL;
    free(temp);
    return Head;
}

LL* delLast(LL *Tail){
    LL *temp;
    temp = Tail;
    Tail = Tail -> prev;
    Tail -> next = NULL;
    free(temp);
    return Tail;
}

void delPos(LL *Head){
    LL *temp, *ptr;
    int pos, count = 0;
    ptr = Head;

    printf("Enter position at which element is to be inserted: ");
    scanf("%d", &pos);
    while((ptr->next != NULL) && (count < pos-2)){
        ptr = ptr->next;
        count++;
    }
    
    temp = ptr->next;
    ptr -> next = ptr -> next -> next;
    free(temp);
}