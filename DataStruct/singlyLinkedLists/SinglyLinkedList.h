
#ifndef __SINGLYLINKEDLIST_H
#define __SINGLYLINKEDLIST_H
/* C-examples/singlyLinkedList/SinglyLinkedList.h */
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct node * NodePtr;
typedef int ItemType;

struct node {
	ItemType  item;
	NodePtr next;
};

/* prototypes */

NodePtr addAtFront(NodePtr L, NodePtr node);
NodePtr reverseList(NodePtr L);
void printList(NodePtr L);


#endif /* __SINGLYLINKEDLIST_H */ 
