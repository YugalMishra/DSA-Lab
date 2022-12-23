#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff, expo;
    struct Node *next;
} Poly;

Poly *input(Poly *Head);
Poly *display(Poly *Head);
Poly *add(Poly *Head1, Poly *Head2, Poly *Head3);
Poly *insert(Poly *Head, int expo, int coeff);

int main(){
    Poly *Head1, *Head2, *Head3;
    Poly *new1, *new2;
    Head1 = NULL;
    Head2 = NULL;
    Head3 = NULL;

    printf("For first polynomial: \n");
    printf("Enter exponents and coeffiecients in descending order\n");
    Head1 = input(Head1);
    printf("\nPolynomial 1: ");
    display(Head1);

    printf("\nFor second polynomial: ");
    printf("Enter exponents and coeffiecients in descending order\n");
    Head2 = input(Head2);
    printf("\nPolynomial 2: ");
    display(Head2);

    Head3 = add(Head1, Head2, Head3);
    printf("\nRequired sum: ");
    display(Head3);
    return 0;
}

Poly *input(Poly* Head){
    Poly *new, *ptr;
    char userInput;
    new = (Poly *) malloc(sizeof(Poly));
    Head = new;
    new -> next = NULL;
    ptr = Head;

    printf("Enter highest exponent: ");
    scanf("%d", &new->expo);
    printf("Enter the coefficient of highest exponent term: ");
    scanf("%d", &new->coeff);

    printf("Do you want to continue entering terms (Y/N): ");
    scanf(" %c", &userInput);

    while ((userInput == 'y') || (userInput == 'Y')){
        new = (Poly *) malloc(sizeof(Poly));
        ptr -> next = new;
        new -> next = NULL;
        printf("Enter exponent of polynomial term: ");
        scanf("%d", &new->expo);
        printf("Enter coefficient of exponent term: ");
        scanf("%d", &new->coeff);
        ptr = ptr->next;

        printf("Do you want to continue entering terms (Y/N): ");
        scanf(" %c", &userInput);
    }
    return Head;
}

Poly *display(Poly *Head){
    Poly *ptr = Head;
    while (ptr != NULL){
        if (ptr != Head){
            if (ptr -> coeff >= 0)
                printf(" + %dx^%d", ptr->coeff, ptr->expo);
            else    
                printf(" - %dx^%d", -ptr->coeff, ptr->expo);
        }

        else{
            if (ptr -> coeff >= 0)
                printf("%dx^%d", ptr->coeff, ptr->expo);
            else    
                printf("- %dx^%d", -ptr->coeff, ptr->expo);           
        }

        ptr = ptr -> next;
    }
    printf("\n");
    return Head;
}

Poly *add(Poly *Head1, Poly *Head2, Poly *Head3){
    Poly *ptr1, *ptr2;
    ptr1 = Head1;
    ptr2 = Head2;

    while ((ptr1 != NULL) && (ptr2 != NULL)){
        if (ptr1 -> expo > ptr2 -> expo){
            Head3 = insert(Head3, ptr1->expo, ptr1->coeff);
            ptr1 = ptr1 -> next;
        }
        else if (ptr2 -> expo > ptr1 -> expo){
            Head3 = insert(Head3, ptr2->expo, ptr2->coeff);
            ptr2 = ptr2 -> next;

        }
        else{
            Head3 = insert(Head3, ptr2->expo, ptr2->coeff+ptr1->coeff);
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        if (ptr1 == NULL){
            while (ptr2 != NULL){
                Head3 = insert(Head3, ptr2->expo, ptr2->coeff);
                ptr2 = ptr2 -> next;
            } 
        }

        else if (ptr2 == NULL){
            while (ptr1 != NULL){
                Head3 = insert(Head3, ptr1->expo, ptr1->coeff);
                ptr1 = ptr1 -> next;
            }            
        }
    }

    return Head3;
}


Poly *insert(Poly *Head, int expo, int coeff){
    Poly *new, *ptr = Head;
    new = (Poly *) malloc(sizeof(Poly));
    new -> expo = expo;
    new -> coeff = coeff;
    new -> next = NULL;

    if ((Head != NULL) && (Head -> next != NULL)){
        while (ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = new;
    }

    else if (Head == NULL)
        Head = new;

    else if (Head -> next == NULL)
        Head -> next = new;
    return Head;
}