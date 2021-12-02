#pragma once

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
	int length;
    char direction;
   	NODE* head;

 public:
	Snake();
    Snake(int x, int y, char d);
    ~Snake();
    Snake(Snake& other);
    Snake& operator=(const Snake& other);

    int getLength();
    char getDirection();
    void getHeadCoords(int& x, int& y);

    void clear();
    void addSegment(int x, int y);
};
