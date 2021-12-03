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
	initBoard();
	snake = Snake(5, 5, SOUTH);
	board[5][5] = SOUTH;
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
	initBoard();
	snake = Snake(numRows/2, numCols/2, SOUTH);
	board[numRows/2][numCols/2] = SOUTH;
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
void Board::play(char startDir) {
	nodelay(stdscr, true);
	snake.setDirection(startDir);
	bool collision = false;
	int r, c;
	int frames = 0;
	while (!collision) {
		// add apple every APPLERATE frames
		if (frames % APPLERATE == 0)
			addApple();

		// check for a change in direction from user
		changeDirection();

		// remove the snake from the board
		removeSnake();

		// move the whole snake forward
		collision = snake.moveForward(r, c);

		// check to see if a wall or apple was hit
		if (board[r][c] == '*') {
			collision = true;
		} else if (board[r][c] == APPLE) {
			snake.addSegment();
			score++;
		}

		// put the snake back on the board
		placeSnake();

		// print the new frame
		printBoard();
		usleep(SPEED);
		frames++;
	}
}

// changeDirection:
// grab key input and change direction of snake
// snake is not allowed to turn 180 degrees
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
// set board to all char ' '
void Board::initBoard() {
	for (int r = 1; r < numRows + 1; r++) {
		for (int c = 1; c < numCols + 1; c++) {
			board[r][c] = ' ';
		}
	}
}

// placeSnake:
// gets coordinates of snake and puts it on the board
void Board::placeSnake() {
	int prevR, prevC;

	// place head
	NODE* cur = snake.getHead();
	board[cur->r][cur->c] = snake.getDirection();
	prevR = cur->r;
	prevC = cur->c;
	cur = cur->next;

	// place segments
	while (cur != nullptr) {
		if (cur->r == prevR && cur->c == prevC)
			break;
		board[cur->r][cur->c] = BODY;
		cur = cur->next;
	}
}

// removeSnake:
// takes the snake off the board
void Board::removeSnake() {
	NODE* cur = snake.getHead();
	while (cur != nullptr) {
		board[cur->r][cur->c] = ' ';
		cur = cur->next;
	}
}

// addApple:
// add an apple in a random empty location
void Board::addApple() {
	int r = rand() % numRows + 1;
	int c = rand() % numCols + 1;
	while (board[r][c] != ' ') {
		r = rand() % numRows + 1;
		c = rand() % numCols + 1;
	}

	board[r][c] = APPLE;
}

// printBoard:
// prints vector board
void Board::printBoard() {
	mvprintw(0, 0, "Snake Game   Score: %d\n\r", score);

	for (int r = 0; r < board.size(); r++) {
		for (int c = 0; c < board[0].size(); c++) {
			printw("%c ", board[r][c]);
		}
		printw("\n\r");
	}

	refresh();
}
