
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*

	list.c 
		Contains functions to manipulate a doubly-linked list.
 
*/


/* private methods */

static NodePtr reverse(NodePtr);
static void print(NodePtr node, char * (*toString)(void *));

ListPtr createList(unsigned long int(*getKey)(void *), 
                   char * (*toString)(void *),
				   void (*freeObject)(void *))
{
	ListPtr list;
	list = (ListPtr) malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->getKey = getKey;
	list->toString = toString;
	list->freeObject = freeObject;
	return list;
}

void freeList(ListPtr list)
{
}

int getSize(ListPtr list)
{
	return list->size;
}

Boolean isEmpty(ListPtr list)
{
	if (list->size == 0)
		return TRUE;
	else
		return FALSE;
}

void addAtFront(ListPtr list, NodePtr node)
{
	if (list == NULL) return;
	if (node == NULL) return;
	list->size++;
	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
}

void addAtRear(ListPtr list, NodePtr node)
{
}

NodePtr removeFront(ListPtr list)
{
	return NULL;
}

NodePtr removeRear(ListPtr list)
{
	return NULL;
}

NodePtr removeNode(ListPtr list, NodePtr node)
{
	return NULL;
}

NodePtr search(ListPtr list, int key)
{
	return NULL;
}

void reverseList(ListPtr list)
{
	list->tail = list->head;
	list->head  = reverse (list->head);
}

static NodePtr reverse(NodePtr L)
{
	NodePtr list = NULL;
	while (L != NULL) {
		NodePtr tmp = L;
		L = L->next;
		if (L != NULL) L->prev = tmp;
		tmp->next = list;
		tmp->prev = L;
		list = tmp;
	}
	return list;
}

void printList(ListPtr list)
{
	if (list) print(list->head, list->toString);
}

static void print(NodePtr node, char * (*toString)(void *))
{
	int count = 0;
	char *output;

	while (node) {
		output = (*toString)(node->obj);
		printf(" %s -->",output);
		free(output);
		node = node->next;
		count++;
		if ((count % 6) == 0)
			printf("\n");
	}
    printf(" NULL \n");
}
 

		

