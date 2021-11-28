#include <stdio.h>
#include <string>
#include "driver.h"
#include "board.h"
#include "snake.h"
using namespace std;

void Driver::run() {
	int num_rows = 10;
	int num_cols = 10;
	char board[num_rows][num_cols + 1];

	// create board
	for (int c = 0; c < num_cols; c++) {
		board[0][c] = '*';
		board[num_rows - 1][c] = '*';
	}
	for (int r = 1; r < num_rows - 1; r++) {
		board[r][0] = '*';
		for (int c = 1; c < num_cols - 1; c++) {
			board[r][c] = ' ';
		}
		board[r][num_cols - 1] = '*';
	}

	// null-terminate
	for (int r = 0; r < num_rows; r++) {
		board[r][num_cols] = '\0';
	}

	// print board
	printf("Snake Game\n");
	for (int r = 0; r < num_rows; r++) {
		printf("%s\n", board[r]);
	}
}
