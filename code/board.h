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

 public:
	Board();
	Board(int r, int c);

	void setNumRows(int r);
	int getNumRows();
	void setNumCols(int c);
	int getNumCols();

    void play();
    void changeDirection();
	void initBoard();
	void placeSnake();
	void printBoard();
};
