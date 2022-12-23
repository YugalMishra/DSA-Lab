#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int row, col, val;
    struct Node *next;
}LL;

int main(){
    LL *insert(LL *, int, int, int);
    void display(LL *);

    int size, temp, i, j, count = 0;
    LL *head = NULL;
    printf("Enter size of sparce matrix: ");
    scanf("%d", &size);
    printf("Enter elements into sparce matrix:\n");
    for(i=0; i<size; i++){
        printf("For row %d\n", i+1);
        for (j=0; j<size; j++){
            scanf("%d", &temp);
            if (temp != 0){
                head = insert(head, i, j, temp);
                count ++;
            }
        }
    }

    LL *ptr = head;
    LL *new = (LL*) malloc(sizeof(LL));
    new -> row = new -> col = size;
    new -> val = count;
    new -> next = head;
    head = new;

    printf("Sparce matrix:\n");
    display(head);
    return 0;
}

LL* insert(LL *head, int row, int col, int value){
    LL *new = (LL* ) malloc(sizeof(LL));
    LL *ptr = head;
    new -> next = NULL;
    new -> row = row;
    new -> col = col;
    new -> val = value;

    if (head == NULL)
        head = new;

    else{
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr -> next = new;
    }
    return head;
}

void display(LL *head){
    LL *ptr = head;
    while (ptr != NULL){
        printf("%d %d %d\n", ptr->row, ptr->col, ptr->val);
        ptr = ptr->next;
    }
}