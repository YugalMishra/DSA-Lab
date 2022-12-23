#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Node{
    int data;
    struct Node *leftChild, *rightChild;
}Tree;

Tree* stack[MAXSIZE];
int top = -1;

void buildTree(Tree *);
void push(Tree *);
Tree* pop();

void recursive_preOrder(Tree *);
void recursive_inOrder(Tree *);
void recursive_postOrder(Tree *);

void nonRecursive_PreOrder(Tree*);
void nonRecursive_InOrder(Tree *);
void nonRecursive_PostOrder(Tree*);


int main(){
    Tree *Root = (Tree *) malloc(sizeof(Tree));
    buildTree(Root);

    printf("\n\nRecursive Pre Order Traversal: ");
    recursive_preOrder(Root);
    printf("\nNon-Recursive Pre Order Traversal: ");
    nonRecursive_PreOrder(Root);
    
    printf("\n\nRecursive In order Traversal: ");
    recursive_inOrder(Root);
    printf("\nNon-Recursive In order Traversal: ");
    nonRecursive_InOrder(Root);

    printf("\n\nRecursive Post Order Traversal: ");
    recursive_postOrder(Root);
    printf("\nNon-Recursive Post Order Traversal: ");
    nonRecursive_PostOrder(Root);
}

void buildTree(Tree *ptr){
    char userInput;
    printf("Enter data: ");
    scanf("%d", &ptr->data);

    printf("Do you want to enter left child of %d (Y/N): ", ptr->data);
    scanf(" %c", &userInput);
    if (userInput == 'y' || userInput == 'Y'){
        Tree *new = (Tree*) malloc(sizeof(Tree));
        ptr -> leftChild = new;
        new -> leftChild = new -> rightChild = NULL;
        buildTree(new);
    }

    printf("Do you want to enter right child of %d (Y/N): ", ptr->data);
    scanf(" %c", &userInput);
    if (userInput == 'y' || userInput == 'Y'){
        Tree *new = (Tree *) malloc(sizeof(Tree));
        ptr -> rightChild = new;
        new -> leftChild = new -> rightChild = NULL;
        buildTree(new);
    } 
}


void recursive_inOrder(Tree *ptr){
    if (ptr -> leftChild)
        recursive_inOrder(ptr -> leftChild);

    printf("%d ", ptr -> data);

    if (ptr -> rightChild)
        recursive_inOrder(ptr -> rightChild);
}


void recursive_preOrder(Tree *ptr){ 
    printf("%d ", ptr -> data);

    if (ptr -> leftChild)
        recursive_preOrder(ptr -> leftChild);

    if (ptr -> rightChild)
        recursive_preOrder(ptr -> rightChild);
}


void recursive_postOrder(Tree *ptr){
    if (ptr -> leftChild) 
        recursive_postOrder(ptr -> leftChild);

    if (ptr -> rightChild)
        recursive_postOrder(ptr -> rightChild);

    printf("%d ", ptr -> data);
}

void nonRecursive_InOrder(Tree *Root){
    top = -1;
    Tree *ptr = Root;
    while (1){
        if (ptr){
            push(ptr);
            ptr = ptr -> leftChild;
        }

        else{
            if (top != -1){
                ptr = pop();
                printf("%d ", ptr-> data);
                ptr = ptr -> rightChild;
            }

            else
                return;
        }
    }
}

void nonRecursive_PreOrder(Tree *Root){
    top = -1;
    Tree *ptr = Root;
    while (1){
        printf("%d ", ptr -> data);

        if (ptr -> rightChild)
            push(ptr -> rightChild);

        if (ptr -> leftChild)
            ptr = ptr->leftChild;

        else{
            ptr = pop();
            if (top==-1 && ptr->leftChild==NULL && ptr->rightChild==NULL){
                printf("%d", ptr -> data);
                return;
            }
        }
    }
}

void nonRecursive_PostOrder(Tree *Root){
    top = -1;
    Tree *ptr = Root;
    do{
        while(ptr){
            if (ptr -> rightChild)
                push(ptr -> rightChild);
            push(ptr);
            ptr = ptr -> leftChild;
        }

        ptr = pop();
        if (ptr->rightChild && stack[top] == ptr->rightChild){
            pop();
            push(ptr);
            ptr = ptr -> rightChild;
        }

        else{
            printf("%d ", ptr -> data);
            ptr = NULL;
        }
    }while(top != -1);
}


void push(Tree *ptr){
    stack[++top] = ptr;
}

Tree* pop(){
    return stack[top--];
}