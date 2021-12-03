#include "board.h"
#include "util.h"
using namespace std;

int startGame();
void getStartDirection(char& startDir);

int main() {
	// initialize ncurses
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, true);

	int highScore = 0;
	bool exit = false;

	// start menu loop
	while (!exit) {
		nodelay(stdscr, false);
		erase();

		// print the menu
		mvprintw(0, 0, "Welcome to snake.");
		printw("\n\rHigh Score: %d", highScore);
		printw("\n\r [START]  EXIT    ");
		bool start = true;

		// wait for user to select an option
		int key = -1;
		while (key != KEY_RETURN) {
			key = getch();
			if (key == KEY_RIGHT) {
				printw("\r  START  [EXIT]   ");
				start = false;
			} else if (key == KEY_LEFT) {
				printw("\r [START]  EXIT    ");
				start = true;
			}
		}

		//  start or exit based on what user selected
		if (start) {
			int score = startGame();
			if (score > highScore)
				highScore = score;
		} else {
			exit = true;
		}
	}

	endwin();
	curs_set(1);
	return 0;
}

// startGame:
// show the board, starting position, and wait for user input
int startGame() {
	// create a board
	Board b(20, 20);

	// print board and instructions
	erase();
	b.printBoard();
	printw("\n\r  Press an arrow key to start the game.");

	// wait for starting input
	char startDir = 'x';
	while(startDir == 'x') {
		getStartDirection(startDir);
	}

	// play the game!
	erase();
	b.play(startDir);

	return b.getScore();
}

// getStartDirection:
// get the direction user chooses to start moving in
void getStartDirection(char& startDir) {
	int key = getch();
	switch(key) {
		case KEY_UP:
			startDir = NORTH;
			break;
		case KEY_DOWN:
			startDir = SOUTH;
			break;
		case KEY_RIGHT:
			startDir = EAST;
			break;
		case KEY_LEFT:
			startDir = WEST;
			break;
	}
}
