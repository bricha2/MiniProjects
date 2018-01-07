all: driver.o TicTacNode.o TicTacToe.o TicTacTrie.o
	g++ -ansi -Wall driver.o TicTacNode.o TicTacToe.o TicTacTrie.o -o output

driver.o: driver.cpp
	g++ -ansi -Wall -c driver.cpp

TicTacNode.o: TicTacNode.cpp
	g++ -ansi -Wall -c TicTacNode.cpp

TicTacToe.o: TicTacToe.cpp
	g++ -ansi -Wall -c TicTacToe.cpp

TicTacTrie.o: TicTacTrie.cpp
	g++ -ansi -Wall -c TicTacTrie.cpp

clean:
	rm -f *.o output *~ *.gch

val:
	valgrind ./output $(FILE)

run:
	./output $(FILE)