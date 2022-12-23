#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftChild, *rightChild;
}binaryTree;

binaryTree* createBinaryTree(binaryTree *, int);
void displayBinaryTree(binaryTree *);

int main(){
    binaryTree *Root = NULL;
    int ele;
    char userInput;
    printf("Enter Root Element: ");
    scanf("%d", &ele);
    createBinaryTree(Root, ele); 

    do{
        printf("Enter element: ");
        scanf("%d", &ele);
        Root = createBinaryTree(Root, ele);
        printf("Do you want to enter another element (Y/N): ");
        scanf(" %c", &userInput);
    }while(userInput == 'Y' || userInput == 'y');

    printf("\nBinary Search Tree: ");
    displayBinaryTree(Root);
    printf("\n");

    return 0;
}

binaryTree *createBinaryTree(binaryTree *Root, int ele){
    binaryTree *new = (binaryTree *) malloc(sizeof(binaryTree));
    binaryTree *ptr = Root;
    new -> data = ele;
    new -> leftChild = new -> rightChild = NULL;

    if (Root){
        while(ptr != NULL){
            if (ele > ptr->data){
                if (ptr -> rightChild)
                    ptr = ptr -> rightChild;
                else{
                    ptr -> rightChild = new;
                    break;
                }
            }

            else if (ele){
                if (ptr -> leftChild)
                    ptr = ptr -> leftChild;
                else{
                    ptr -> leftChild = new;
                    break;
                }
            }
        }
    }

    else
        Root = new;
    return Root;
}

void displayBinaryTree(binaryTree *ptr){
    if (ptr -> leftChild)
        displayBinaryTree(ptr->leftChild);

    printf("%d ", ptr -> data);

    if (ptr -> rightChild)
        displayBinaryTree(ptr->rightChild);
}