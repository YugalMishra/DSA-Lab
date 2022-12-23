#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftChild, *rightChild;
}binaryTree;

void createBinaryTree(binaryTree *, int);
void displayBinaryTree(binaryTree *);
binaryTree* findNode(binaryTree*, int);
void findHeight(binaryTree *, int);
void checkHeight(int);
int maxHeight = -1;

int main(){
    binaryTree *Root = (binaryTree*) malloc(sizeof(binaryTree));
    Root -> leftChild = Root -> rightChild = NULL;

    int ele;
    char userInput;

    printf("Enter Root Element: ");
    scanf("%d", &ele);
    Root -> data = ele;

    do{
        printf("Enter element: ");
        scanf("%d", &ele);
        createBinaryTree(Root, ele);
        printf("Do you want to enter another element (Y/N): ");
        scanf(" %c", &userInput);
    }while(userInput == 'Y' || userInput == 'y');

    printf("\nBinary Search Tree: ");
    displayBinaryTree(Root);
    printf("\n");

    int keyValue;
    printf("Enter node whose height is to be found: ");
    scanf("%d", &keyValue);
    binaryTree *node = findNode(Root, keyValue);

    if (node){
        findHeight(node, -1);
        printf("Height of %d is: %d\n", keyValue, maxHeight);
    }

    else
        printf("Node not present in Binary Tree\n");

    return 0;
}

void createBinaryTree(binaryTree *ptr, int ele){
    if (ele < ptr->data){
        if (ptr -> leftChild)
            createBinaryTree(ptr->leftChild, ele);
        else{
            binaryTree *new = (binaryTree*) malloc(sizeof(binaryTree));
            new -> data = ele;
            new -> leftChild = new -> rightChild = NULL;
            ptr -> leftChild = new;
        }
    }

    else if (ele > ptr->data){
        if (ptr -> rightChild)
            createBinaryTree(ptr->rightChild, ele);
        else{
            binaryTree *new = (binaryTree*) malloc(sizeof(binaryTree));
            new -> data = ele;
            new -> leftChild = new -> rightChild = NULL;
            ptr -> rightChild = new;
        }
    }
}

void displayBinaryTree(binaryTree *ptr){
    if (ptr -> leftChild)
        displayBinaryTree(ptr->leftChild);

    printf("%d ", ptr -> data);

    if (ptr -> rightChild)
        displayBinaryTree(ptr->rightChild);
}

binaryTree* findNode(binaryTree *ptr, int keyValue){
    if (keyValue > ptr->data)
        if (ptr -> rightChild)
            findNode(ptr->rightChild, keyValue);
        else
            return NULL;
    
    else if (keyValue < ptr->data)
        if (ptr -> leftChild)
            findNode(ptr->leftChild, keyValue);
        else
            return NULL;
    
    else
        return ptr;
}

void findHeight(binaryTree *ptr, int height){
    if (ptr == NULL)
        return;
    height++;
    checkHeight(height);
    findHeight(ptr->leftChild, height);
    findHeight(ptr->rightChild, height);
}

void checkHeight(int height){
    if (height > maxHeight)
        maxHeight = height;
}