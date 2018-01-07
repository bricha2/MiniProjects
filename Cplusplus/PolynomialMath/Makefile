OBJS =  Polynomial.o mytest.o Node.o
CC = g++ 
#DEBUG = -g -gstabs+ -ansi
CFLAGS = $(DEBUG) -Wall -g -c
LFLAGS = $(DEBUG) -Wall -g 



proj3: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o proj3



mytest.o: mytest.cpp Polynomial.h
	$(CC) $(CFLAGS) mytest.cpp



Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp

Polynomial.o: Polynomial.cpp Node.h
	$(CC) $(CFLAGS) Polynomial.cpp

run:
	./proj3

clean: 
	rm -f *.o *~