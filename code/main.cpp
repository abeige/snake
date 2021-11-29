#include <iostream>
#include <conio.h>
#include <windows.h>
#include "board.h"
#include "util.h"
using namespace std;

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define CTRL_C 3
#define ENTER 13

int main() {
	resize();
	hidecursor();
	clear();

	cout << "\n\n   Welcome to snake.\n";
	cout << "    [START]  EXIT   \r";

	int key;
	bool start = true;
	bool menu = true;
	bool game = false;
	while (menu) {
		key = getch();
		switch (key) {
			case RIGHT_ARROW:
				cout << "     START  [EXIT]  \r";
				start = false;
				break;
			case LEFT_ARROW:
				cout << "    [START]  EXIT   \r";
				start = true;
				break;
			case ENTER:
				if (start) {
					clear();
					menu = false;
					game = true;
				} else {
					cout << "\n\n";
					return 0;
				}
				break;
		}
	}

	Board b;
	while (game) {
		b.printBoard();
		cout << "\n  Press any key to start the game." << endl;
		key = getch();
		b.play();
		game = false;
	}

	showcursor();
	return 0;
}
