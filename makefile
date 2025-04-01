c=gcc
op=-Wall -Wextra

all : es.o pile.o file.o tp9.c 	
	$(c) $(op)  es.o file.o pile.o tp9.c -o tp9
pile.o : pile.c pile.h
	$(c) $(op) -c pile.c	
file.o : file.c file.h
	$(c) $(op) -c file.c	
es.o : es.c es.h
	$(c) $(op) -c es.c	

clean : 
	rm -rf *.o tp9