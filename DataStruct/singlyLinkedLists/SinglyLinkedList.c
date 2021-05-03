
/* C-examples/singlyLinkedList/SinglyLinkedList.c */

/*

	SinglyLinkedList.c
		Contains functions to manipulate a linked list.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

NodePtr addAtFront(NodePtr L, NodePtr node)
{
	if (node == NULL) return L;
	if (L == NULL) {
		L = node;
		node->next = NULL;
	} else {
		node->next = L;
		L = node;
	}
	return L;
}


NodePtr reverseList(NodePtr L)
{
	NodePtr list = NULL;
	while (L != NULL) {
		NodePtr tmp = L;
		L = L->next;
		tmp->next = list;

		list = tmp;
	}
	return list;
}

void printList(NodePtr L)
{
	while (L) {
	/*while (L != NULL) {*/
		printf(" %d -->",L->item);
		L = L->next;
	}
    printf(" NULL \n");
}
 
		

