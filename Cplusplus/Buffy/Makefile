OBJS =  character.o ghost.o zombie.o buffy.o redshirt.o vampire.o game.o node.o linked.o proj4.o human.o doctor.o
CC = g++ 
#DEBUG = -g -gstabs+
CFLAGS = -Wall -g -c $(DEBUG)
LFLAGS = -Wall -g $(DEBUG)

proj4: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o proj4

character.o: character.cpp
	$(CC) $(CFLAGS) character.cpp

buffy.o: buffy.cpp character.h
	$(CC) $(CFLAGS)  buffy.cpp

doctor.o: doctor.cpp character.h
	 $(CC) $(CFLAGS)  doctor.cpp

game.o: game.cpp character.h linked.h
	 $(CC) $(CFLAGS)  game.cpp

ghost.o: ghost.cpp character.h
	 $(CC) $(CFLAGS)  ghost.cpp

human.o: human.cpp character.h
	 $(CC) $(CFLAGS)  human.cpp

linked.o: linked.cpp node.h
	 $(CC) $(CFLAGS)  linked.cpp

node.o: node.cpp character.h
	 $(CC) $(CFLAGS)  node.cpp

redshirt.o: redshirt.cpp character.h
	 $(CC) $(CFLAGS)  redshirt.cpp

vampire.o: vampire.cpp character.h
	 $(CC) $(CFLAGS)  vampire.cpp

zombie.o: zombie.cpp zombie.h
	 $(CC) $(CFLAGS)  zombie.cpp

proj4.o: main.cpp character.h ghost.h human.h zombie.h doctor.h buffy.h redshirt.h vampire.h game.h
	 $(CC) $(CFLAGS)  proj4.cpp
run:
	./proj4

clean: 
	rm -f *.o *~