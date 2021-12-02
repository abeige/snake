#include <string>
#include <curses.h>
#include "board.h"
// #include "util.h"
using namespace std;

#define KEY_RETURN 10

int main() {
	// resize();

	int key;
	bool start = true;
	bool menu = true;
	bool game = false;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, true);

	// for (int i = 0; i < 10; i++) {
	// 	key = getch();
	// 	cout << key << "\r\n";
	// }

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
					erase();
					menu = false;
					game = true;
				} else {
					return 0;
				}
				break;
		}
	}

	Board b;
	while (game) {
		b.printBoard();
		printw("\n\r  Press return to start the game.");
		key = getch();
		while (key != KEY_RETURN) {
			key = getch();
		}
		b.play();
		game = false;
	}

	endwin();
	curs_set(1);
	return 0;
}
