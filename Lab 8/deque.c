/*
2) WAP to implement double ended queue or deque and perform the following operations: 
insertion, deletion and display (Input restricted Deque and Deletion restricted Deque)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}deQue;

int main(){
    void insert_at_first(deQue **);
    void insert_at_last(deQue **);
    void delete_from_first(deQue **);
    void delete_from_last(deQue **);
    void display(deQue *);

    int userInput;
    deQue *headIR, *headDR;
    headIR = headDR = NULL;
    
    while (1){
        printf("\n------------------------------------------------\n");
        printf("Insertion Restricted Queue:\n");
        printf("1: To insert into Queue\n");
        printf("2: To remove from Queue\n");
        printf("3: To display elements of Queue\n");

        printf("\nDeletion Restricted Queue:\n");
        printf("4: To insert into Queue\n");
        printf("5: To remove from Queue\n");
        printf("6: To display elements of Queue\n");
        
        printf("\n7: To exit\n");
        printf("Your choice: ");
        scanf("%d", &userInput);
        
        switch(userInput){
            case 1:
                insert_at_last(&headIR);
                break;

            case 2:
                printf("1: To delete from beginning\n");
                printf("2: To delete from end\n");
                printf("Enter your choice: ");
                scanf("%d", &userInput);
                if (userInput == 1)
                    delete_from_first(&headIR);
                else if (userInput == 2)
                    delete_from_last(&headIR);
                else
                    printf("INVALID INPUT\n");
                break;

            case 3:
                display(headIR);
                break;

            case 4:
                printf("1: To insert at beginning\n");
                printf("2: To insert at end\n");
                printf("Enter your choice: ");
                scanf("%d", &userInput);
                if (userInput == 1)
                    insert_at_first(&headDR);
                else if (userInput == 2)
                    insert_at_last(&headDR);
                else
                    printf("INVALID INPUT\n");
                break;

            case 5:
                delete_from_first(&headDR);
                break;

            case 6:
                display(headDR);
                break;
                
            case 0:
                exit(0);

            default:
                printf("INVALID INPUT\n");
        }
    }
    return 0;
}

void insert_at_first(deQue **head){
    deQue *new = (deQue*) malloc(sizeof(deQue));
    if (*head == NULL)
        new -> next = NULL;
    else   
        new -> next = *head;
    *head = new;

    printf("Enter element to be inserted: ");
    scanf("%d", &new -> val);
}

void insert_at_last(deQue **head){
    deQue *new = (deQue*) malloc(sizeof(deQue));
    new -> next = NULL;
    if (*head == NULL)
        *head = new;

    else{
        deQue *ptr = *head;
        while (ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = new;
    }

    printf("Enter element to be inserted: ");
    scanf("%d", &new -> val);
}

void delete_from_first(deQue **head){
    if (*head == NULL){
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    deQue *temp = *head;
    *head = (*head) -> next;
    free(temp);
}

void delete_from_last(deQue **head){
    if (*head == NULL){
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    deQue *temp = *head;
    if ((*head) -> next == NULL)
        *head = NULL;

    else{
        deQue *ptr = *head;
        while(ptr -> next -> next != NULL)
            ptr = ptr -> next;
        temp = ptr -> next;
        ptr -> next = NULL;
    }

    free(temp);
}

void display(deQue *head){
    if (head == NULL){
        printf("QUEUE is EMPTY");
        return;
    }

    deQue *ptr = head;
    printf("QUEUE: ");
    while (ptr != NULL){
        printf("%d ", ptr -> val);
        ptr = ptr -> next;
    }
    printf("\n");
}