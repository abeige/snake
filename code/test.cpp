#include <string>
#include <curses.h>
#include <unistd.h>
#include "board.h"
using namespace std;

int main() {
	Board b1;
	Board b2(20, 20);

	initscr();
	noecho();
	cbreak();

	b1.printBoard();
	usleep(500000);
	b2.printBoard();
	usleep(500000);

	b2 = b1;;

	erase();
	b2.printBoard();
	usleep(500000);

	endwin();
	return 0;
}
