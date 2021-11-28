#pragma once

#include <vector>
#include "snake.h"
using namespace std;

class Board {
 private:
	vector<vector<char>> board;
	Snake snake;
	int numRows;
	int numCols;

 public:
	Board();
	Board(int r, int c);
	// TO DO: operator[]

	void setNumRows(int r);
	int getNumRows();
	void setNumCols(int c);
	int getNumCols();

	void initBoard();
	void play();
	void printBoard();
};
