#include <iostream>
#include <vector>
#include "board.h"
#include "snake.h"
using namespace std;

Board::Board() {
	numRows = 10;
	numCols = 10;

	initBoard();
}

Board::Board(int r, int c) {
	if (r < 2 || c < 2) {
		throw string("that's too small");
	}

	numRows = r;
	numCols = c;

	initBoard();
}

// TO DO: operator[]

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
	// first and last rows
	for (int c = 0; c < numCols; c++) {
		board[0][c] = '*';
		board[numRows - 1][c] = '*';
	}

	// middle rows
	for (int r = 1; r < numRows - 1; r++) {
		board[r][0] = '*';
		for (int c = 1; c < numCols - 1; c++) {
			board[r][c] = ' ';
		}
		board[r][numCols - 1] = '*';
	}
}

void Board::play() {
	cout << "Playing" << endl;
}

void Board::printBoard() {
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			cout << board[r][c] << ' ';
		}
		cout << endl;
	}

	// // print board
	// cout << "Snake Game\n";
	// for (int r = 0; r < num_rows; r++) {
	// 	cout << "%s\n", board[r]);
	// }
}
