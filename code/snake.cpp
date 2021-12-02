#include "snake.h"
#include "util.h"
using namespace std;

// default constructor
Snake::Snake() {
	head = new NODE(1, 1);
	length = 0;
	direction = SOUTH;
}

// parameterized constructor
Snake::Snake(int x, int y, char d) {
	head = new NODE(x, y);
	length = 1;
	switch(d) {
		case NORTH:
		case SOUTH:
		case EAST:
		case WEST:
			direction = d;
			break;
		default:
			direction = NORTH;
	}
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

// getDirection:
// return direction of snake head
char Snake::getDirection() {
	return direction;
}

// getLength:
// return length of snake (head + number of segments)
int Snake::getLength() {
	return length;
}

void Snake::getHeadCoords(int& x, int& y) {
	if (head == nullptr)
		return;
	x = head->x;
	y = head->y;
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
