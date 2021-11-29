build: main.o board.o snake.o
	g++ -Wall -g -std=c++11 main.o board.o snake.o -o snake.exe

run:
	./snake.exe

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp
	g++ -c board.cpp

snake.o: snake.cpp
	g++ -c snake.cpp
