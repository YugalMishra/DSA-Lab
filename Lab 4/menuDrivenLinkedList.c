#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}LL;

void menu(struct Node *);
void inputData(struct Node *);
void displayData(struct Node *);
void search(struct Node *);
void insertFirst(struct Node *);
void insertLast(struct Node *);
void insertPos(struct Node *, int);
void delFirst(struct Node *);
void delLast(struct Node *);
void delPos(struct Node *, int);

int main(){
    struct Node *head, *ptr, *new;
    head = NULL;
    new = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter data of first element: ");
    scanf("%d", &new->data);
    new -> next = NULL;
    head = new;
    ptr = head;
    menu(head);
    return 0;
}

void menu(struct Node *head){
    int userInput, pos, flag=1;
    do{
        printf("\nEnter 1 to input data\n");
        printf("Enter 2 to display data\n");
        printf("Enter 3 to search for an element\n");
        printf("Enter 4 to insert element at beginnning\n");
        printf("Enter 5 to insert element at end\n");
        printf("Enter 6 to insert element at position\n");
        printf("Enter 7 to delete first element\n");
        printf("Enter 8 to delete last element\n");
        printf("Enter 9 to delete element from position\n");

        printf("Enter any other integer to exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1:
                inputData(head);
                break;
            case 2:
                displayData(head);
                break;
            case 3:
                search(head);
                break;
            case 4:
                insertFirst(head);
                displayData(head);
                break;
            case 5:
                insertLast(head);
                displayData(head);
                break;
            case 6:
                printf("Enter position at which element is to be inserted: ");
                scanf("%d", &pos);
                insertPos(head, pos);
                displayData(head);
                break;
            // case 7:
            //     delFirst(head);
            //     displayData(head);
            //     break;
            // case 8:
            //     delLast(head);
            //     displayData(head);
            //     break;
            // case 9:
            //     printf("Enter position at which element is to be deleted: ");
            //     scanf("%d", &pos);
            //     delPos(head, pos);
            //     displayData(head);
            //     break;
            default:
                flag = 0;
                break;
        }

    } while (flag);
}

void inputData(struct Node *head){
    struct Node *new, *ptr;
    char ch;
    int userInput, flag = 0;

    do{
        new = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &new->data);
        new -> next = NULL;
        ptr -> next = new;
        ptr = ptr -> next;
        
        printf("Do you want to continue adding data (Y/N): ");
        getchar();
        ch = getchar();

    } while ((ch == 'Y') || (ch == 'y'));
    printf("\n");
}

void displayData(struct Node *head){
    struct Node *ptr;
    ptr = head;
    printf("\nData: ");
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void search(struct Node *head){
    struct Node *ptr;
    int key;
    printf("Enter key to be searched: ");
    scanf("%d", &key);
    ptr = head;
    while (ptr != NULL){
        if (key == ptr->data){
            printf("FOUND\n");
            break;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL)
        printf("NOT FOUND\n");
}

void insertFirst(struct Node *head){
    struct Node *new;
    new = (LL *) malloc(sizeof(LL));
    new -> next = head;
    head = new;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
}

void insertLast(LL *head){
    LL *new, *ptr;
    ptr = head;
    new = (LL *) malloc(sizeof(LL));
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new;
    new->next = NULL;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
}

void insertPos(LL *head, int pos){
    LL *new, *ptr;
    ptr = head;
    new = (LL *) malloc(sizeof(LL));
    while((ptr != NULL) && (pos--))
        ptr = ptr->next;
    
    new -> next = ptr->next;
    ptr->next = new;
    printf("Enter data to be inserted: ");
    scanf("%d", &new->data);
}