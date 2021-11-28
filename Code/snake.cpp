#include <utility>
#include "snake.h"
using namespace std;

Snake::Snake() {
	headCoords = {1, 1};
	int length = 1;
}

int Snake::getLength() {
	return length;
}
