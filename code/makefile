build: main.o board.o snake.o
	g++ -Wall -g -std=c++11 main.o board.o snake.o -o snakegame.exe -lncurses

test: test.o board.o snake.o
	g++ -Wall -g -std=c++11 test.o board.o snake.o -o snakegame.exe -lncurses

run:
	./snakegame.exe

main.o: main.cpp board.h util.h
	g++ -c main.cpp

test.o: test.cpp board.h util.h
	g++ -c test.cpp

board.o: board.cpp board.h snake.h util.h
	g++ -c board.cpp

snake.o: snake.cpp snake.h util.h
	g++ -c snake.cpp

valgrind:
	valgrind --tool=memcheck --leak-check=full ./snake
