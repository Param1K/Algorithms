
INSTALL=../..
LIB=$(INSTALL)/lib
INCLUDE=$(INSTALL)/include
CC=gcc
CFLAGS=-Wall -g -O -fPIC -I$(INCLUDE)/
LFLAGS=-L$(LIB) -lmylib


LIBOBJS=List.o Node.o

all: libs 


libs: $(LIB)/libmylib.so  $(LIB)/libmylib.a

$(LIB)/libmylib.so: $(LIBOBJS)
	$(LD) -shared -o $@  $(LIBOBJS)

$(LIB)/libmylib.a: $(LIBOBJS)
	$(AR)  rcv $@ $(LIBOBJS)
	ranlib $@


install: libs
	install --mode=444 -C List.h $(INSTALL)/include
	install --mode=444 -C Node.h $(INSTALL)/include
	install --mode=444 -C common.h $(INSTALL)/include

installclean:  clean
	rm --force $(INSTALL)/lib/libmylib.so
	rm --force $(INSTALL)/lib/libmylib.a
	rm --force $(INSTALL)/include/List.h
	rm --force $(INSTALL)/include/Node.h
	rm --force $(INSTALL)/include/common.h
	
clean:
	rm --force list *.o a.out core
