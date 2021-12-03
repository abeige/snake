#include "board.h"
#include "snake.h"
#include "util.h"
using namespace std;

Board::Board() {
	numRows = 10;
	numCols = 10;
	score = 0;
	// +2 for padding
	board = vector<vector<char>>(numRows + 2, vector<char>(numCols + 2, '*'));
	snake = Snake(5, 5, NORTH);
}

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

int Board::getScore() {
	return score;
}

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

void Board::initBoard() {
	for (int r = 1; r < numRows + 1; r++) {
		for (int c = 1; c < numCols + 1; c++) {
			board[r][c] = ' ';
		}
	}
}

void Board::placeSnake() {
	int r, c;
	snake.getHeadCoords(r, c);
	board[r][c] = snake.getDirection();
}

void Board::addApple() {
	int r = rand() % numRows + 1;
	int c = rand() % numCols + 1;
	board[r][c] = 'o';
}

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
