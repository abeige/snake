#include "board.h"
#include "util.h"
using namespace std;

bool startMenu(int& highScore);
int startGame();

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
	b.initBoard();
	b.printBoard();
	nodelay(stdscr, false);
	printw("\n\r  Press an arrow key to start the game.");
	b.changeDirection();
	erase();
	b.play();
	return b.getScore();
}
