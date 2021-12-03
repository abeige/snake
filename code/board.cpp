#include "board.h"
#include "snake.h"
#include "util.h"
using namespace std;

// default constructor
Board::Board() {
	numRows = 10;
	numCols = 10;
	score = 0;
	// +2 for padding
	board = vector<vector<char>>(numRows + 2, vector<char>(numCols + 2, '*'));
	snake = Snake(5, 5, NORTH);
}

// parameterized constructor
Board::Board(int r, int c) {
	if (r < 2 || c < 2)  // too small
		r = c = 2;

	numRows = r;
	numCols = c;
	score = 0;
	// +2 for padding
	board = vector<vector<char>>(numRows + 2, vector<char>(numCols + 2, '*'));
	snake = Snake(numRows/2, numCols/2, SOUTH);
}

// setNumRows:
// sets numRows to r
void Board::setNumRows(int r) {
	numRows = r;
}

// getNumRows:
// returns numRows
int Board::getNumRows() {
	return numRows;
}

// setNumCols:
// sets numCols to c
void Board::setNumCols(int c) {
	numCols = c;
}

// getNumCols:
// returns numCols
int Board::getNumCols() {
	return numCols;
}

int Board::getScore() {
	return score;
}

// play:
// main driver for game to run
void Board::play() {
	nodelay(stdscr, true);
	bool hitWall = false;
	int r, c;
	int frames = 0;
	while (!hitWall) {
		if (frames % APPLERATE == 0)
			addApple();
		changeDirection();
		snake.getHeadCoords(r, c);
		board[r][c] = ' ';
		snake.moveForward(r, c);
		if (board[r][c] == '*') {
			hitWall = true;
		} else if (board[r][c] == 'o') {
			// snake.addSegment();
			score++;
		}
		printBoard();
		usleep(SPEED);
		frames++;
	}
}

void Board::changeDirection() {
	switch(getch()) {
		case KEY_UP:
			if (snake.getDirection() != SOUTH)
				snake.setDirection(NORTH);
			break;
		case KEY_DOWN:
			if (snake.getDirection() != NORTH)
				snake.setDirection(SOUTH);
			break;
		case KEY_RIGHT:
			if (snake.getDirection() != WEST)
				snake.setDirection(EAST);
			break;
		case KEY_LEFT:
			if (snake.getDirection() != EAST)
				snake.setDirection(WEST);
			break;
		default:
			break;
	}
}

// initBoard:
// resets board to char ' '
void Board::initBoard() {
	for (int r = 1; r < numRows + 1; r++) {
		for (int c = 1; c < numCols + 1; c++) {
			board[r][c] = ' ';
		}
	}
}

// placeSnake:
// gets coordinates of snake and its body and puts it on the board
void Board::placeSnake() {
	int r, c;
	snake.getHeadCoords(r, c);
	board[r][c] = snake.getDirection();
}

void Board::addApple() {
	int r = rand() % numRows + 1;
	int c = rand() % numCols + 1;
	while (board[r][c] != ' ') {
		r = rand() % numRows + 1;
		c = rand() % numCols + 1;
	}

	board[r][c] = 'o';
}

// printBoard:
// prints vector board
void Board::printBoard() {
	mvprintw(0, 0, "Snake Game   Score: %d\n\r", score);

	placeSnake();
	for (int r = 0; r < board.size(); r++) {
		for (int c = 0; c < board[0].size(); c++) {
			printw("%c ", board[r][c]);
		}
		printw("\n\r");
	}

	refresh();
}
