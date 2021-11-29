#pragma once

class NODE {
	int x, y;
	NODE* next;

	NODE() {
		x = 1;
		y = 1;
		next = nullptr;
	}

	NODE(int x, int y) {
		this->x = x;
		this->y = y;
		next = nullptr;
	}
}
