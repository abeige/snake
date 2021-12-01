#pragma once

#include <utility>
using namespace std;

class Snake {
 private:
	NODE* head;
	int length;
    char direction;

    struct NODE {
        int x, y;
        NODE* next;

        NODE(int x, int y) {
            this->x = x;
            this->y = y;
            next = nullptr;
        }
    };

 public:
	Snake();
    Snake(int x, int y, char d);
    ~Snake();
    Snake(Snake& other);
    // TODO: assignment operator

	int getLength();
    void addSegment(int x, int y);
};
