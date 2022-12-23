#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int row, col, val;
    struct Node *next;
}LL;

int main(){
    LL *insert(LL *, int, int, int);
    LL *row_col_val(LL *, int, int);
    LL *addSparse(LL*, LL*, LL*, int);
    void display(LL *);
    

    int size, temp, i, j, count = 0;
    LL *head1, *head2;
    head1 = head2 = NULL;

    printf("\nEnter size of sparse matrix: ");
    scanf("%d", &size);

    printf("\nFor first matrix\nEnter elements:\n");
    for(i=0; i<size; i++){
        printf("For row %d: ", i+1);
        for (j=0; j<size; j++){
            scanf("%d", &temp);
            if (temp != 0){
                head1 = insert(head1, i, j, temp);
                count ++;
            }
        }
    }
    head1 = row_col_val(head1, size, count);
    count = 0;

    printf("\nFor second matrix\nEnter elements:\n");
    for(i=0; i<size; i++){
        printf("For row %d: ", i+1);
        for (j=0; j<size; j++){
            scanf("%d", &temp);
            if (temp != 0){
                head2 = insert(head2, i, j, temp);
                count ++;
            }
        }
    }
    head2 = row_col_val(head2, size, count);

    printf("\nSparse matrix 1:\n");
    display(head1);
    printf("\nSparse matrix 2:\n");
    display(head2);
    LL *head3;
    head3 = addSparse(head1, head2, head3, size);
    printf("\nResultant Matrix:\n");
    display(head3);
    return 0;
}

LL* row_col_val(LL* head, int size, int count){
    LL *ptr = head;
    LL *new = (LL*) malloc(sizeof(LL));
    new -> row = new -> col = size;
    new -> val = count;
    new -> next = head;
    head = new;
    return head;
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
            ptr = ptr -> next;
        ptr -> next = new;
    }
    return head;
}

LL* addSparse(LL* head1, LL* head2, LL* head3, int size){
    int i, j, count=0;
    head1 = head1 -> next;
    head2 = head2 -> next;
    while(head1 != NULL && head2 != NULL){
        if (head1->row == head2->row){
            if(head1->col == head2->col){
                head3 = insert(head3, head1->row, head1->col, head1->val+head2->val);
                head1 = head1 -> next;
                head2 = head2 -> next;
                count++;
            }

            else if (head1->col > head2->col){
                head3 = insert(head3, head2->row, head2->col, head2->val);
                head2 = head2 -> next;
                count++;
            }

            else{
                head3 = insert(head3, head1->row, head1->col, head1->val);
                head1 = head1 -> next;
                count++;
            }
        }

        else if(head1->row > head2->row){
            head3 = insert(head3, head2->row, head2->col, head2->val);
            head2 = head2 -> next;
            count++;
        }

        else{
            head3 = insert(head3, head1->row, head1->col, head1->val);
            head1 = head1 -> next;
            count++;
        }
    }
    if (head1 == NULL){
        while(head2 != NULL){
            head3 = insert(head3, head2->row, head2->col, head2->val);
            head2 = head2->next;
            count++;
        }
    }
    else{
        while(head1 != NULL){
            head3 = insert(head3, head1->row, head1->col, head1->val);
            head1 = head1 -> next;
            count++;
        }
    }
    head3 = row_col_val(head3, size, count);
    head3 -> next = head3 -> next -> next;
    return head3;
}

void display(LL *head){
    LL *ptr = head;
    while (ptr != NULL){
        printf("%d %d %d\n", ptr->row, ptr->col, ptr->val);
        ptr = ptr->next;
    }
}