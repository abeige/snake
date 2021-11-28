#include <iostream>
#include <conio.h>
#include <windows.h>
#include "board.h"
using namespace std;

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define CTRL_C 3

void hidecursor();
void showcursor();
void resize();
void clear();

int main() {
	resize();
	hidecursor();

	cout << "\n\n   Welcome to snake.\n";
	cout << "    [START]  EXIT   \r";

	int key;
	bool start = true;
	bool menu = true;
	bool game = false;
	while (menu){
		key = getch();
		if (key == RIGHT_ARROW) {
			cout << "     START  [EXIT]  \r";
			start = false;
		} else if (key == LEFT_ARROW) {
			cout << "    [START]  EXIT   \r";
			start = true;
		} else if (key == 13) {
			if (start) {
				clear();
				menu = false;
				game = true;
			} else {
				cout << "\n\n";
				return 0;
			}
		}
	}

	Board b;
	while (game) {
		b.play();
		game = false;
	}

	showcursor();
	return 0;
}

void hidecursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void resize() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 600, 600, TRUE);
}

void clear() {
    cout << "\x1B[2J\x1B[H";
}
