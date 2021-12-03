#include "board.h"
#include "util.h"
using namespace std;

bool startMenu(int& highScore);
int startGame();
void getStartDirection(char& startDir);

int main() {
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, false);

	int highScore = 0;
	bool exit = false;
	while (!exit) {
		exit = startMenu(highScore);
	}

	endwin();
	curs_set(1);
	return 0;
}

bool startMenu(int& highScore) {
	bool menu = true;

	erase();
	mvprintw(0, 0, "Welcome to snake.");
	printw("\n\rHigh Score: %d", highScore);
	printw("\n\r [START]  EXIT    ");
	bool start = true;
	refresh();

	while (menu) {
		switch (getch()) {
			case KEY_RIGHT:
				printw("\r  START  [EXIT]   ");
				start = false;
				break;
			case KEY_LEFT:
				printw("\r [START]  EXIT    ");
				start = true;
				break;
			case KEY_RETURN:
				if (start) {
					int score = startGame();
					if (score > highScore)
						highScore = score;
					return false;
				} else {
					return true;
				}
				break;
		}
	}

	return true;
}

int startGame() {
	Board b(20, 20);

	erase();
	nodelay(stdscr, false);
	b.initBoard();
	b.printBoard();

	printw("\n\r  Press an arrow key to start the game.");
	char startDir = 'x';
	while(startDir == 'x') {
		getStartDirection(startDir);
	}

	// play the game!
	erase();
	b.play(startDir);

	return b.getScore();
}

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
