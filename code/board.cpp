#include "board.h"
#include "snake.h"
#include "util.h"
using namespace std;

Board::Board() {
	numRows = 10;
	numCols = 10;
	// + 2 for padding
	board = vector<vector<char>>(numRows + 2, vector<char>(numCols + 2, '*'));
	snake = Snake(5, 5, NORTH);
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

void Board::play() {
	erase();
	initBoard();
	printBoard();
	printw("\n\r  Press return to start the game.");
	int key = getch();
	while (key != KEY_RETURN) {
		key = getch();
	}
}

void Board::initBoard() {
	for (int r = 1; r < numRows + 1; r++) {
		for (int c = 1; c < numCols + 1; c++) {
			board[r][c] = ' ';
		}
	}
}

void Board::placeSnake() {
	int x, y;
	snake.getHeadCoords(x, y);
	board[x][y] = snake.getDirection();
}

void Board::printBoard() {
	mvprintw(0, 0, "Snake Game\n\r");

	placeSnake();
	for (int r = 0; r < board.size(); r++) {
		for (int c = 0; c < board[0].size(); c++) {
			printw("%c ", board[r][c]);
		}
		printw("\n\r");
	}

	refresh();
}
