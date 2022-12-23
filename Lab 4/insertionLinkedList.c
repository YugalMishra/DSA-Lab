#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void shiftEle(struct Node*, struct Node*);
void inputData(struct Node*, struct Node*);
void insertEle(struct Node*, int, int);

int main(){
    struct Node *new, *ptr, *head;
    int pos, ele;
    head = NULL;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter data of 1st element: ");
    scanf("%d", &new->data);
    new -> next = NULL;
    head = ptr = new;

    printf("Enter position to insert element into: ");
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &ele);

    inputData(head, ptr);
    insertEle(head, pos, ele);
    return 0;
}  

void inputData(struct Node *head, struct Node *ptr){
    struct Node *new;
    char ch;
    do{
        new = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &new->data);
        new -> next = NULL;
        ptr -> next = new;
        ptr = ptr -> next;

        printf("Do you want to continue entering data (Y/N): ");
        getchar();
        ch = getchar();
    } while((ch == 'y') || (ch == 'Y'));
}

void insertEle(struct Node *head, int pos, int ele){
    struct Node *ptr, *new;
    int count = 0;
    ptr = head;
    while (ptr != NULL){
        count ++;
        if (count == pos){
            new = (struct Node*) malloc (sizeof(struct Node));
            new -> data = ele;
            new -> next = NULL;
            ptr -> next = new;
        }
        ptr = ptr -> next;
    }
}