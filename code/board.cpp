#include "board.h"
#include "snake.h"
#include "util.h"
using namespace std;

Board::Board() {
	numRows = 10;
	numCols = 10;
	// + 2 for padding
	board = vector<vector<char>>(numRows + 2, vector<char>(numCols + 2, '*'));
	snake = Snake();
}

Board::Board(int r, int c) {
	if (r < 2 || c < 2)  // too small
		r = c = 2;

	numRows = r;
	numCols = c;
	// + 2 for padding
	board = vector<vector<char>>(numRows + 2, vector<char>(numCols + 2, '*'));
	snake = Snake(numRows/2, numCols/2, SOUTH);
}

void Board::setNumRows(int r) {
	numRows = r;
}

int Board::getNumRows() {
	return numRows;
}

void Board::setNumCols(int c) {
	numCols = c;
}

int Board::getNumCols() {
	return numCols;
}

void Board::initBoard() {
	// first row
	vector<char> rowFirstLast(numCols, '*');
	board.push_back(rowFirstLast);

	// middle rows
	vector<char> rowMid;
	rowMid.push_back('*');
	for (int c = 1; c < numCols - 1; c++) {
		rowMid.push_back(' ');
	}
	rowMid.push_back('*');

	for (int r = 1; r < numRows - 1; r++) {
		board.push_back(rowMid);
	}

	// last row
	board.push_back(rowFirstLast);

	// place snake
	// placeSnake();
	// pair<int, int> snakeStart = snake.getHeadCoords();
	// board[snakeStart.first][snakeStart.second] = 'v';
}

void Board::play() {
	printw("Playing...");
}

void Board::printBoard() {
	mvprintw(0, 0, "Snake Game\n\r");
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			printw("%c ", board[r][c]);
		}
		printw("\n\r");
	}
	refresh();
}
