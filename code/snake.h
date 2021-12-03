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

    void clear();
    void copySnake(const Snake& other);

    int getLength();
    char getDirection();
    void setDirection(char d);
    NODE* getHead() const;
    void getHeadCoords(int& r, int& c);

    void addSegment();
    bool moveForward(int& r, int& c);
};
