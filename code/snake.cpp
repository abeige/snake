#include <utility>
#include "snake.h"
using namespace std;

Snake::Snake() {
	head = nullptr;
	length = 0;
	direction = 'x';
}

Snake::Snake(int x, int y) {
	head = new NODE(x, y);
	length = 1;
	direction = 'S';
}

Snake::~Snake() {
	if (head == nullptr)
		return;
	NODE* cur = head;
	NODE* prev = nullptr;

	while (cur != nullptr) {
		prev = cur;
		cur = cur->next;
		delete prev;
	}

	head = nullptr;
}

Snake::Snake(Snake& other) {

}

int Snake::getLength() {
	return length;
}
