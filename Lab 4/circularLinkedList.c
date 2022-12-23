//Everything about Circular Linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} LL;

void input(LL *);
void display(LL *);
LL* insertFirst(LL *);
LL* insertPos(LL *);
void insertLast(LL *);
LL* delFirst(LL *);
void delLast(LL *);
LL* delPos(LL *);
void menu(LL *);

int main(){
    LL *Head, *new, *ptr;
    new = (LL *) malloc(sizeof(LL));
    Head = NULL;

    printf("Enter first element into linked list: ");
    scanf("%d", &new->data);
    Head = new;
    ptr = Head;
    new -> next = Head;

    menu(Head);
    return 0;
}

void menu(LL *Head){
    int userInput, flag = 1;
    char ch;
    do{
        printf("\nEnter 1 to input data\n");
        printf("Enter 2 to display data\n");
        printf("Enter 3 to insert element\n");
        printf("Enter 4 to delete element\n");
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
                Head = insertPos(Head);
                display(Head);
                break;
            case 4:
                Head = delPos(Head);
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
        new -> next = Head;

        printf("Enter elements into linked list: ");
        scanf("%d", &new->data);
        ptr = ptr->next;

        printf("Do you want to continue (Y/N): ");
        getchar();
        ch = getchar();
    }while ((ch == 'y') || (ch == 'Y'));
}

void display(LL *Head){
    LL *ptr = Head;
    printf("\nData: ");
    do{
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != Head);

    printf("%d\n", ptr->data);
}

LL* insertFirst(struct Node *head){
    struct Node *new, *ptr, *temp = head;
    new = (LL *) malloc(sizeof(LL));
    new -> next = head;
    head = new;
    ptr = head;

    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);

    do{
        ptr = ptr->next;
    }while(ptr->next != temp);
    ptr->next = head;
    return head;
}

void insertLast(LL *head){
    LL *new, *ptr;
    ptr = head;
    new = (LL *) malloc(sizeof(LL));
    while(ptr->next != head)
        ptr = ptr->next;

    ptr->next = new;
    new->next = head;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
}

LL* insertPos(LL *head){
    LL *new, *ptr;
    int pos, count = 0;
    printf("Enter 1 to insert at beginning,\n-1 to enter at end,\nand any other integer to insert at position\n");
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
        head = insertFirst(head);

    else if (pos == -1)
        insertLast(head);

    else{
        ptr = head;
        pos--;
        new = (LL *) malloc(sizeof(LL));
        do{
            ptr = ptr->next;
            count++;
        }while((ptr != head) && (count<pos-2));
        
        new -> next = ptr->next;
        ptr->next = new;
        printf("Enter data to be inserted: ");
        scanf("%d", &new->data);
    }
    return head;
}

LL* delFirst(LL * Head){
    LL *temp, *ptr;
    temp = Head;
    Head = Head->next;
    ptr = Head;
    do{
        ptr = ptr->next;
    }while(ptr->next != temp);
    ptr->next = Head;
    
    free(temp);
    return Head;
}

void delLast(LL *Head){
    LL *temp, *ptr;
    ptr = Head;
    do{
        ptr = ptr->next;
    }while((ptr->next)->next != Head);
    
    temp = ptr->next;
    ptr->next = Head;
    free(temp);
}

LL* delPos(LL *Head){
    LL *temp, *ptr;
    int pos, count = 0;
    printf("Enter 1 to delete first element,\n-1 to delete last element,\nand any other integer to delete at pos\n");
    printf("Enter position at which element is to be deleted: ");
    scanf("%d", &pos);
    if(pos == 1)
        Head = delFirst(Head);

    else if (pos == -1)
        delLast(Head);

    else{
        ptr = Head;
        pos--;
        do{
            ptr = ptr->next;
            count++;
        }while((ptr->next != Head) && (count < pos-2));
        
        temp = ptr->next;
        ptr->next = (ptr->next)->next;
        free(temp);
    }
    return Head;
}