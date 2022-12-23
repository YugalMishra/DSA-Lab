#include <stdio.h>

int front, rear;

int main(){
    void CQinsert(int queue[], int);
    void CQdel(int queue[], int);
    void CQtraverse(int queue[], int);

    int cQueue[100];
    int userInput, size;

    char Continue = 'y';
    front = rear = -1;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    do{
        printf("\nEnter 1 to enter data into queue ");
        printf("\nEnter 2 to remove data from queue ");
        printf("\nEnter 3 to display queue elements ");
        printf("\nEnter any other number to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1: 
                CQinsert(cQueue, size);
                break;
            case 2:
                CQdel(cQueue, size);
                break;
            case 3:
                CQtraverse(cQueue, size);
                break;
            default:
                break;
        }
        printf("\n");
    }while (Continue == 'y');
    return 0;
}

void CQinsert(int queue[], int size){
    if (front == (rear+1)%size)
        printf("QUEUE OVERFLOW\n"); 

    else{
        int item;
        printf("Enter element to be inserted into queue: ");
        scanf("%d", &item);
        if (front == -1){
            front = rear = 0;
            queue[rear] = item;
        }

        else{
            rear = (rear + 1) % size;
            queue[rear] = item;
        }
        printf("Element inserted successfully");
    }
}

void CQdel(int queue[], int size){
    if (front == -1 && rear == -1)
        printf("QUEUE UNDERFLOW\n");
    
    else{
        printf("%d removed from queue\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void CQtraverse(int queue[], int size){
    if(front == -1 && rear == -1)
        printf("Queue is empty\n");
    else{
        int i;
        for(i=front; i!=rear; i=(i+1)%size)
            printf("%d ", queue[i]);
        printf("%d", queue[i]);
    }
}