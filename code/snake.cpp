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
	this->copySnake(other);
}

// copy operator
Snake& Snake::operator=(const Snake& other) {
	if (this == &other)
		return *this;

	this->length = other.length;
	this->direction = other.direction;
	this->clear();

	// copy nodes
	this->copySnake(other);

	return *this;
}

// clear:
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

// copySnake:
// copy the snake NODE linked list
void Snake::copySnake(const Snake& other) {
	// copy head node
	NODE* otherCur = other.getHead();
	if (otherCur == nullptr) {
		return;
	} else {
		this->head = new NODE(otherCur->r, otherCur->c);
	}
	otherCur = otherCur->next;

	// copy segments
	NODE* thisCur = this->head;
	while (otherCur != nullptr) {
		thisCur->next = new NODE(otherCur->r, otherCur->c);
		thisCur = thisCur->next;
		otherCur = otherCur->next;
	}
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

// getHead:
// returns a pointer to snake head
NODE* Snake::getHead() const{
	return head;
}

// getHeadCoords:
// updates r and c with coordinates of Snake head
void Snake::getHeadCoords(int& r, int& c) {
	if (head == nullptr)
		return;
	r = head->r;
	c = head->c;
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
// r, c are updated and contain new head location for checking collisions
// returns true if the new head position is a wall or body segment
bool Snake::moveForward(int& r, int& c) {
	int prevR = head->r;
	int prevC = head->c;
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

	if (head->next == nullptr)
		return false;

	NODE* cur = head->next;
	int tempR, tempC;
	bool collide = false;
	while (cur != nullptr) {
		// swap cur->r, c with prevR, C
		tempR = cur->r;
		tempC = cur->c;
		cur->r = prevR;
		cur->c = prevC;
		prevR = tempR;
		prevC = tempC;


		// if new location of head with this segment
		if (head->r == cur->r && head->c == cur->c)
			collide = true;

		cur = cur->next;
	}

	return collide;
}
