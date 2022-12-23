#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}cQueue;

cQueue *front, *rear;

int main(){
    void CQinsert();
    void CQdel();
    void CQtraverse();

    int userInput;
    char Continue = 'y';
    front = rear = NULL;
    
    do{
        printf("\nEnter 1 to enter data into queue ");
        printf("\nEnter 2 to remove data from queue ");
        printf("\nEnter 3 to display queue elements ");
        printf("\nEnter any other number to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1: 
                CQinsert();
                break;
            case 2:
                CQdel();
                break;
            case 3:
                CQtraverse();
                break;
            default:
                break;
        }
        printf("\n");
    }while (Continue == 'y');
    return 0;
}

void CQinsert(){ 
    int item;
    printf("Enter element to be inserted into queue: ");
    scanf("%d", &item);

    cQueue *new = (cQueue* ) malloc(sizeof(cQueue));

    if (front == NULL)
        front = rear = new;

    else{
        rear -> next = new;
        rear = new;
    }
    new -> val = item;
    new -> next = front;
    printf("Element inserted successfully");
}

void CQdel(){
    if (front == NULL)
        printf("QUEUE UNDERFLOW\n");
    
    else{
        printf("%d removed from queue\n", front -> val);
        cQueue *temp = front;

        if (front == rear)
            front = rear = NULL;
        else{
            front = front -> next;
            rear -> next = front;
        }
        free(temp);
    }
}

void CQtraverse(){
    if(front == NULL)
        printf("Queue is empty");
    else{
        cQueue *ptr = front;
        do{
            printf("%d ", ptr -> val);
            ptr = ptr -> next;
        } while(ptr != front);
    }
}