#include <stdio.h>
#define MAXSIZE 20

int main(){
    void buildTree(int[] , int , int);
    void inOrderTraversal(int [], int);
    int tree[MAXSIZE] , data;

    for(int i=0; i<MAXSIZE; i++)
        tree[i] = -1 ;

    printf("Enter the Root Node : ");
    scanf("%d",&data);
    buildTree(tree , 0 , data);

    printf("Tree: ");
    for (int i=0; i<MAXSIZE; i++){
        if (tree[i] == -1)
            printf("_ ");
        else
            printf("%d ", tree[i]);
    }
    printf("\n");
    return 0;
}

void buildTree(int tree[] , int index , int item){
    int data;
    char choice;
    tree[index] = item ;

    printf("Do you want to enter a Left Child of %d (Y/N) : " , item);
    scanf(" %c" , &choice);
    if(choice == 'y' || choice == 'Y'){
        printf("Enter the Left Child : ");
        scanf("%d", &data);
        buildTree(tree, ((index*2)+1), data);
    }

    printf("Do you want to enter the Right Child of %d (Y/N) : " , item);
    scanf(" %c" , &choice);
    if(choice == 'y' || choice == 'Y'){
        printf("Enter the Right Child : ");
        scanf("%d" , &data);
        buildTree(tree , ((index*2)+2) , data);
    }
}