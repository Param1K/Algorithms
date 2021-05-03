
/*
	List.h: Defines the interface for a doubly-linked list.
*/

#ifndef  __SINGLLYLINKEDLIST_H
#define __SINGLLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "Node.h"

typedef struct list SinglyLinkedList;
typedef struct list * SinglyLinkedListPtr;

struct singlylinkedlist {
	int size;
	NodePtr head;
	unsigned long int (*getKey)(void *);
	char *  (*toString)(void *);
	void (*freeObject)(void *);
};

/* prototypes of public methods */

/* constructor */
ListPtr createList(unsigned long int(*getKey)(void *), 
                   char * (*toString)(void *),
				   void (*freeObject)(void *));

void freeList(ListPtr L); /* destructor */

int getSize(ListPtr L);

Boolean isEmpty(ListPtr L);

void addAtFront(ListPtr list, NodePtr node);
NodePtr removeFront(ListPtr list);
NodePtr search(ListPtr list, int key);
void reverseList(ListPtr  L);
void printList(ListPtr L);


#endif /* __SINGLLYLINKEDLIST_H */
