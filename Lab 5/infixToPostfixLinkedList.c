#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>     
#include<string.h>

typedef struct Node{
    char data;
    struct Node *next;
} stack;

stack *top = NULL;

void push(char x){
	stack *new =(stack *) malloc(sizeof(stack));
    new -> next = NULL;
    new -> data = x;
    if (top == NULL)
        top = new;
    
    else{
        new -> next = top;
        top = new;
    }
}

char pop(){
	char x;
    stack *temp = top;
	if(top == NULL){
		printf("\nSTACK UNDERFLOW");
		exit(1);
	}

	else{
        x = top -> data;
		top = top -> next;
        free(temp);
		return x;
	}
}

int isOperator(char sym){
	if(sym == '^' || sym == '*' || sym == '/' || sym == '+' || sym =='-')
		return 1;
	return 0;
}

int precedence(char sym) {
	if(sym == '^')
		return 3;
	else if(sym == '*' || sym == '/')
		return 2;
	else if(sym == '+' || sym == '-')         
		return 1;
	else
		return 0;
	
}

void convert(char infix[], char postfix[]) { 
	int i, j;
	char x, rem;
	push('(');                               
	strcat(infix,")");                

	i = j = 0;
	x = infix[i];      

	while(x != '\0'){
		if(x == '(')
			push(x);

		else if(isdigit(x) || isalpha(x)) {
			postfix[j] = x;              
			j++;
		}

		else if(isOperator(x)){
		    rem = pop();
			while((isOperator(x)) && (precedence(rem) >= precedence(x))){
				postfix[j] = rem;                  
				j++;
				rem = pop();                    
			}
			push(rem);
			push(x);                 
        }

		else if(x == ')'){
			rem = pop();                
			while(rem != '('){
				postfix[j] = rem;
				j++;
				rem = pop();
			}
		}

		else{
			printf("Invalid infix Expression.\n");      
			exit(1);
		}
		i++;
		x = infix[i]; 
	}

	postfix[j] = '\0'; 
}

int main()
{
	char infix[100], postfix[100];        
	printf("\nEnter Infix expression : ");
	scanf("%s", infix);

	convert(infix, postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                   

	return 0;
}