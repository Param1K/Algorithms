#include<stdio.h>


typedef struct node{
	int entry;
	struct node *next;
}Node;

typedef struct stack{
	Node *top;
}Stack;

void createLinkedStack(Stack *s)
{
	s->top=NULL;	
	printf("Empty Stack Created\n");
}

Node *makeNode(int entry)
{
	Node *nPtr=(Node *)malloc(sizeof(Node));
	if(nPtr==NULL)
	{
		printf("Memory Exhausted");
		exit(1);
	}
	else{
		nPtr->entry=entry;
		nPtr->next=NULL;
		return nPtr;
	}
}

void push(Stack *s,int item)
{
	Node *np=makeNode(item);
	/*if(s->top==NULL)
	{
		s->top=np;
	}else{*/

		np->next=s->top;
		s->top=np;
	
	printf("\nEntry =%d Pushed",item);

}

void pop(Stack *s)
{
	Node *np;
	if(s->top==NULL)
		printf("empty stack");
	else{
		np=s->top;
		s->top=s->top->next;
		printf("\nEntry = %d--Popped",np->entry);
		free(np);
	}

}


int main()
{
/*	Stack *s;   //wrong implementation---SIGSEGV	
	createLinkedStack(s);
	push(s,1);
	push(s,2);
	push(s,3);
	 
	pop(s);
	pop(s);
	pop(s);
*/
// Correct Way using Pointer to Structure
	Stack *s=(Stack *)malloc(sizeof(Stack));
	createLinkedStack(s);
	push(s,1);
	push(s,2);
	push(s,3);
	 
	pop(s);
	pop(s);
	pop(s);

/*	
//Correct way using Structure
	Stack s;
	createLinkedStack(&s);
	push(&s,1);
	push(&s,2);
	push(&s,3);
	 
	pop(&s);
	pop(&s);
	pop(&s);

*/
}
