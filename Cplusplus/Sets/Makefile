OBJS =  sos.o mytest.o
CC = g++
CFLAGS = -Wall -g -c $(DEBUG)
LFLAGS = -Wall -g $(DEBUG)

proj2: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o proj2

mytest.o: mytest.cpp sos.h
	$(CC) $(CFLAGS)  mytest.cpp

sos.o: sos.cpp
	$(CC) $(CFLAGS)  sos.cpp
run:
	./proj2

