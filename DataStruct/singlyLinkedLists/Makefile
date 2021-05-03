
CC=gcc
CFLAGS=-Wall -g  


all: TestLists


TestLists: TestLists.o SinglyLinkedList.o SinglyLinkedList.h
	$(CC) $(CFLAGS)  TestLists.o SinglyLinkedList.o  -o $@

clean:
	rm --force *.o a.out TestLists
