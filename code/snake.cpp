#include <utility>
#include "snake.h"
using namespace std;

// default constructor
Snake::Snake() {
	head = nullptr;
	length = 0;
	direction = 'N';
}

// parameterized constructor
Snake::Snake(int x, int y, char d) {
	head = new NODE(x, y);
	length = 1;
	direction = d;
}

// destructor
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

// copy constructor
Snake::Snake(Snake& other) {
	this->length = other.length;
	this->direction = other.direction;
	this->head = nullptr;

	// copy nodes
	NODE* cur = other.head;
	while (cur != nullptr) {
		addSegment(cur->x, cur->y);
		cur = cur->next;
	}
}

// getLength:
// return length of snake (head + number of segments)
int Snake::getLength() {
	return length;
}

// addSegment:
void Snake::addSegment(int x, int y) {
	NODE* newNode = new NODE(x, y);

	// check to see if list is empty
	if (head == nullptr) {
		head = newNode;
		length++;
		return;
	}

	// traverse to end and add newNode there
	NODE* cur = head;
	while (cur != nullptr) {
		if (cur->next == nullptr) {
			cur->next = newNode;
			break;
		}

		cur = cur->next;
	}
}
