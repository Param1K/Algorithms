// A simple and tail recursive C++ program to reverse 
// a linked list 
#include<stdio.h>
#include<stdlib.h>

typedef struct Node { 
	int data; 
	struct Node* next; 
}Node; 


void recReverse(Node *head, Node **newHead)
{
    Node *curr = head;
    Node *next = NULL;
    if(!head)
        return;

    next = curr->next;
    curr->next = *newHead;
    *newHead = curr;
    recReverse(next, newHead);
}

void reverse(Node **head)
{
    Node *curr = *head;
    Node *newHead = NULL;
    Node *next = NULL;

    while(curr)
    {
        next = curr->next;
        curr->next = newHead; 
        newHead = curr;
        curr = next;
    } 
    *head = newHead;
}


// A utility function to create a new node 
Node* newNode(int key) 
{ 
	Node* temp = (Node *)malloc(sizeof(Node));; 
	temp->data = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print a linked list 
void printlist(Node* head) 
{ 
	while (head != NULL) { 
		printf("%d ",head->data);
        head = head->next; 
	} 
    printf("\n"); 
} 

void clear(Node *head)
{
    Node *curr = NULL;
    while(head)
    {
        curr = head;
        head = head->next;
        printf("\nFreeing %d",curr->data);
        free(curr);
    }
}

// Driver program to test above functions 
int main() 
{ 
	Node* head1 = newNode(1); 
    Node* newHead = NULL;
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 
	head1->next->next->next = newNode(4); 
	head1->next->next->next->next = newNode(5); 
	head1->next->next->next->next->next = newNode(6); 
	head1->next->next->next->next->next->next = newNode(7); 
	head1->next->next->next->next->next->next->next = newNode(8); 
    printf("Given list\n");
	printlist(head1); 
	recReverse(head1, &newHead); 
	printf("\nReversed linked list\n"); 
	printlist(newHead); 

	reverse(&newHead); 
	printf("\nReversed linked list\n"); 
	printlist(newHead); 

    clear(newHead);
	return 0; 
} 
