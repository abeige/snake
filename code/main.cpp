#include "board.h"
#include "util.h"
using namespace std;

bool startMenu();
bool startGame();

int main() {
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, false);

	while (startMenu()) {
		continue;
	}

	endwin();
	curs_set(1);
	return 0;
}

bool startMenu() {
	bool start = true;
	erase();
	mvprintw(0, 0, "\n\n  Welcome to snake. ");
	printw("\n\r   [START]  EXIT    ");
	refresh();
	bool menu = true;

	while (menu) {
		switch (getch()) {
			case KEY_RIGHT:
				printw("\r    START  [EXIT]   ");
				start = false;
				break;
			case KEY_LEFT:
				printw("\r   [START]  EXIT    ");
				start = true;
				break;
			case KEY_RETURN:
				if (start) {
					startGame();
					return true;
				} else {
					menu = false;
				}
				break;
		}
	}
	return menu;
}

bool startGame() {
	Board b(20, 20);
	erase();
	b.initBoard();
	b.printBoard();
	nodelay(stdscr, false);
	printw("\n\r  Press an arrow key to start the game.");
	b.changeDirection();
	erase();
	b.play();
	return false;
}
