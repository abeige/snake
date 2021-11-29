#pragma once

#include <utility>
using namespace std;

class Snake {
 private:
	NODE* head;
	int length;
    char direction;

 public:
	Snake();
    Snake(int x, int y);
    ~Snake();
    // copy constructor
    // assignment operator

	int getLength();
    pair<int, int>& getHeadCoords();
    // add segment
};
