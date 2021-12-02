#include <utility>
#include <curses.h>
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
	clear();
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

Snake& Snake::operator=(const Snake& other) {
	if (this == &other)
		return *this;

	this->length = other.length;
	this->direction = other.direction;
	this->clear();

	// copy nodes
	NODE* cur = other.head;
	while (cur != nullptr) {
		addSegment(cur->x, cur->y);
		cur = cur->next;
	}

	return *this;
}

void Snake::clear() {
	if (head == nullptr)
		return;

	NODE* cur = head;
	NODE* next = nullptr;

	while (cur != nullptr) {
		next = cur->next;
		delete cur;
		cur = next;
	}

	head = nullptr;
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
			length++;
			break;
		}

		cur = cur->next;
	}
}
