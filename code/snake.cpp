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
Snake::Snake(int r, int c, char d) {
	head = new NODE(r, c);
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
		addSegment(cur->r, cur->c);
		cur = cur->next;
	}
}

// copy operator
Snake& Snake::operator=(const Snake& other) {
	if (this == &other)
		return *this;

	this->length = other.length;
	this->direction = other.direction;
	this->clear();

	// copy nodes
	NODE* cur = other.head;
	while (cur != nullptr) {
		addSegment(cur->r, cur->c);
		cur = cur->next;
	}

	return *this;
}

// getDirection:
// return direction of snake head
char Snake::getDirection() {
	return direction;
}

void Snake::setDirection(char d) {
	direction = d;
}

// getLength:
// return length of snake (head + number of segments)
int Snake::getLength() {
	return length;
}

// getHeadCoords:
// updates r and c with coordinates of Snake head
void Snake::getHeadCoords(int& r, int& c) {
	if (head == nullptr)
		return;
	r = head->r;
	c = head->c;
}

// deletes Snake linked list of NODEs
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
// adds NODE to linked list
void Snake::addSegment() {
	// this should not happen
	if (head == nullptr)
		throw;

	// traverse to end
	NODE* cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}

	// new segment has the same position as the last one
	cur->next = new NODE(cur->r, cur->c);
}

// moveForward:
// move snake (and all it's segments) forward in direction
void Snake::moveForward(int& r, int& c) {
	// first update head
	switch(direction) {
		case NORTH:
			head->r--;
			break;
		case SOUTH:
			head->r++;
			break;
		case EAST:
			head->c++;
			break;
		case WEST:
			head->c--;
			break;
	}
	r = head->r;
	c = head->c;
	// TODO: segments follow
}
