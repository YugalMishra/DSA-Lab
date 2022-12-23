//Everything about Linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} LL;

void input(LL *);
void display(LL *);
LL* insertFirst(LL *);
LL* insertPos(LL *, int);
LL* insertLast(LL *);
LL* delFirst(LL *);
LL* delLast(LL *);
LL* delPos(LL *, int);
void menu(LL *);

int main(){
    LL *Head, *new, *ptr;
    new = (LL *) malloc(sizeof(LL));
    Head = NULL;

    printf("Enter first element into linked list: ");
    scanf("%d", &new->data);
    Head = new;
    ptr = Head;
    new -> next = NULL;

    menu(Head);

    return 0;
}

void menu(LL *Head){
    int userInput, pos, key, flag = 1;
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
                input(Head);
                break;
            case 2:
                display(Head);
                break;
            case 3:
                Head = insertFirst(Head);
                display(Head);
                break;
            case 4:
                Head = insertLast(Head);
                display(Head);
                break;
            case 5:
                printf("Enter position at which element is to be inserted: ");
                scanf("%d", &pos);
                Head = insertPos(Head, pos);
                display(Head);
                break;
            case 6:
                Head = delFirst(Head);
                display(Head);
                break;
            case 7:
                Head = delLast(Head);
                display(Head);
                break;
            case 8:
                printf("Enter position at which element is to be deleted: ");
                scanf("%d", &pos);
                Head = delPos(Head, pos);
                display(Head);
                break;
            default:
                flag = 0;
                break;
        }

    } while (flag);
    display(Head);
}

void input(LL *Head){
    LL *ptr, *new;
    char ch;
    ptr = Head;
    do{
        new = (LL *) malloc(sizeof(LL));
        ptr -> next = new;
        new -> next = NULL;

        printf("Enter elements into linked list: ");
        scanf("%d", &new->data);
        ptr = ptr->next;

        printf("Do you want to continue (Y/N): ");
        getchar();
        ch = getchar();
    }while ((ch == 'y') || (ch == 'Y'));
}

void display(LL *Head){
    if (Head == NULL){
        printf("Empty Linked list\n");
    }

    else{
        LL *ptr = Head;
        printf("\nData: ");
        while (ptr != NULL){
            printf("%d ", ptr -> data);
            ptr = ptr -> next;
        }
    }
    printf("\n");
}

LL* insertFirst(struct Node *head){
    struct Node *new;
    new = (LL *) malloc(sizeof(LL));
    new -> next = head;
    head = new;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return head;
}

LL* insertLast(LL *head){
    LL *new, *ptr;
    ptr = head;
    new = (LL *) malloc(sizeof(LL));
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new;
    new->next = NULL;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return head;
}

LL* insertPos(LL *head, int pos){
    LL *new, *ptr;
    int count = 0;
    ptr = head;
    new = (LL *) malloc(sizeof(LL));
    while((ptr != NULL) && (count<pos-2)){
        ptr = ptr->next;
        count++;
    }
    
    new -> next = ptr->next;
    ptr->next = new;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
    return head;
}

LL* delFirst(LL * Head){
    LL *temp;
    temp = Head;
    Head = Head->next;
    free(temp);
    return Head;
}

LL* delLast(LL *Head){
    LL *temp, *ptr;
    ptr = Head;
    while((ptr->next)->next != NULL)
        ptr = ptr->next;
    
    temp = ptr->next;
    ptr->next = NULL;
    free(temp);
    return Head;
}

LL* delPos(LL *Head, int pos){
    LL *temp, *ptr;
    int count = 0;
    ptr = Head;
    while((ptr->next != NULL) && (count < pos-2)){
        ptr = ptr->next;
        count++;
    }
    
    temp = ptr->next;
    ptr->next = (ptr->next)->next;
    free(temp);
    return Head;
}