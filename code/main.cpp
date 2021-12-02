#include "board.h"
#include "util.h"
using namespace std;

int main() {
	int key;
	bool start = true;
	bool menu = true;
	bool game = false;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, true);

	printw("\n\n  Welcome to snake. ");
	printw("\n\r   [START]  EXIT    ");
	refresh();

	while (menu) {
		key = getch();
		switch (key) {
			case KEY_RIGHT:
				printw("\r    START  [EXIT]   ");
				refresh();
				start = false;
				break;
			case KEY_LEFT:
				printw("\r   [START]  EXIT    ");
				refresh();
				start = true;
				break;
			case KEY_RETURN:
				if (start) {
					menu = false;
					game = true;
				} else {
					menu = false;
					game = false;
				}
				break;
		}
	}

	Board b;
	while (game) {
		erase();
		b.printBoard();
		printw("\n\r  Press return to start the game.");
		key = getch();
		while (key != KEY_RETURN) {
			key = getch();
		}
		// b.play();
		game = false;
	}

	endwin();
	curs_set(1);
	return 0;
}
