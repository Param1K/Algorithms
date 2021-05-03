#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node {
	int     key;
	Node    *next;
};

Node *makeNode (int x)
{
    Node *p = malloc(sizeof(Node));
    if(!p)
    {
        printf("not enough memory\n");
        return 0;
    } else {
        p->key = x;
        p->next = NULL;	
    }
    return p;
}

void insertNodeRear (Node **head, Node *new)
{
    Node *temp = NULL;

    if (*head == NULL) {
        *head = new;
        printf("Head initialized to ->%d\n", new->key);
    } else {
        for(temp = *head; temp->next != NULL; temp = temp-> next);
        printf("Node inserted %d->%d\n", temp->key, new->key);
        temp->next = new;
    }
}
void insertNodeFront (Node **head, Node *new)
{
    Node *temp;

    if (*head == NULL) {
        *head = new;
        printf("Head initialized to ->%d\n", new->key);
    } else {
        temp = *head;
        new->next = temp;
        *head = new;
        printf("Node inserted %d->%d\n", new->key, temp->key);
    }
}

void freeList (Node *head)
{
    Node *p;
    while(head != NULL)
    {
        p = head;
        head = head->next;
        printf("Deleting node %d\n",  p->key);
        free(p);
    }
}

void clearList(Node **head) {
    Node *temp = NULL;

    if (*head != NULL) {
        do {
            temp = *head;
            *head = (*head)->next;
            printf("Deleting node %d\n",  temp->key);
            free(temp);
        } while (*head);
    }
}

int deleteNode(Node **head, int key)
{
    Node *temp = NULL;
    Node *prev = NULL;

    if(*head != NULL) {
        for(temp = *head; temp != NULL; temp = temp->next) {
            if (temp->key == key) {
                if(prev == NULL) {
                    *head = temp->next;
                    free(temp);
                } else {
                    prev->next = temp->next;
                    free(temp);
                }
                printf("Deleted node %d\n", key);
                return 0;
            }
            prev = temp;
        }
    }
    return -1;
}

Node *delNodeRecursive (Node *head, int key) 
{
    Node *currp;
    if (head == NULL) {
        return NULL;
    } else if (head->key != key) {
        head->next = delNodeRecursive(head->next, key);
    } else {
        currp = head;
        head = head->next;
        printf("Deleting node %d recursively\n", key);
        free(currp);
        return head;
    }
}
void reverseList(Node **head) {
    Node *currp = NULL;
    Node *newHead = NULL;

    while (*head) {
        currp = *head;
        *head = (*head)->next;
        currp->next = newHead;
        newHead = currp;
    }
    *head = newHead;
}

int main()
{
    Node *head = NULL, *p = NULL;
    int i;

    for(i = 0; i < 5; i++)
    {
        p = makeNode(i);
        insertNodeFront(&head, p);
    }

    for(i = 5; i < 10; i++)
    {
        p = makeNode(i);
        insertNodeRear(&head, p);
    }

    reverseList(&head);
    deleteNode(&head, 9);
    deleteNode(&head, 5);
    head = delNodeRecursive(head, 6); 
    /* Clear the List */
    //freeList(head);
    clearList(&head);
}
