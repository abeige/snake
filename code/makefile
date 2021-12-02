build: main.o board.o snake.o
	g++ -Wall -g -std=c++11 main.o board.o snake.o -o snake -lncurses

test: test.o board.o snake.o
	g++ -Wall -g -std=c++11 test.o board.o snake.o -o snake -lncurses

run:
	./snake

main.o: main.cpp
	g++ -c main.cpp

test.o: test.cpp
	g++ -c test.cpp

board.o: board.cpp
	g++ -c board.cpp

snake.o: snake.cpp
	g++ -c snake.cpp

valgrind:
	valgrind --tool=memcheck --leak-check=full ./snake
