#pragma once

#include <utility>
using namespace std;

class Snake {
 private:
	pair<int, int> headCoords;
	int length;
    char direction;

 public:
	Snake();
    Snake(int x, int y);

	int getLength();
    pair<int, int>& getHeadCoords();
};
