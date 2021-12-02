#pragma once

#include <utility>
using namespace std;

struct NODE {
    int x, y;
    NODE* next;

    NODE(int x, int y) {
        this->x = x;
        this->y = y;
        next = nullptr;
    }
};

class Snake {
 private:
	NODE* head;
	int length;
    char direction;

 public:
	Snake();
    Snake(int x, int y, char d);
    ~Snake();
    Snake(Snake& other);
    Snake& operator=(const Snake& other);

    void clear();
	int getLength();
    void addSegment(int x, int y);
};
