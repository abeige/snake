#pragma once

struct NODE {
    int r, c;
    NODE* next;

    NODE(int r, int c) {
        this->r = r;
        this->c = c;
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
    Snake(int r, int c, char d);
    ~Snake();
    Snake(Snake& other);
    Snake& operator=(const Snake& other);

    int getLength();
    char getDirection();
    void getHeadCoords(int& r, int& c);

    void clear();
    void addSegment(int r, int c);
    void moveForward(int& r, int& c);
};
