#include <utility>
#include "snake.h"
using namespace std;

Snake::Snake() {
	headCoords = {1, 1};
	length = 1;
	direction = 'S';
}

Snake::Snake(int x, int y) {
	headCoords = {x, y};
	length = 1;
	direction = 'S';
}

int Snake::getLength() {
	return length;
}

pair<int, int>& Snake::getHeadCoords() {
	return headCoords;
}
