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
				start = false;
				break;
			case KEY_LEFT:
				printw("\r   [START]  EXIT    ");
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
		b.initBoard();
		b.printBoard();
		printw("\n\r  Press return to start the game.");
		int key = getch();
		while (key != KEY_RETURN) {
			key = getch();
		}
		b.play();
		game = false;
	}
	
	curs_set(1);
	endwin();
	return 0;
}
