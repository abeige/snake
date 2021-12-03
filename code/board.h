#pragma once

#include "snake.h"
#include "util.h"
using namespace std;

class Board {
 private:
	vector<vector<char>> board;  // numRows+2 x numCols+2 for padding
	Snake snake;
	int numRows;
	int numCols;
    int score;

	void placeSnake();
    void addApple();

 public:
	Board();
	Board(int r, int c);

	void setNumRows(int r);
	int getNumRows();
	void setNumCols(int c);
	int getNumCols();
    int getScore();

    void play(char startDir);
	void initBoard();
    void changeDirection();
	void printBoard();
};
