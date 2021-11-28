#pragma once

#include <utility>
using namespace std;

class Snake {
 private:
	pair<int, int> headCoords;
	int length;

 public:
	Snake();
	int getLength();
};
