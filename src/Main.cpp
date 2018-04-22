#include "sudoku.hpp"

int board[9][9] = {
	{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
	{ 0, 9, 0, 0, 0, 0, 0, 8, 5 },
	{ 5, 0, 0, 0, 8, 0, 4, 0, 0 },
	{ 4, 0, 7, 2, 0, 6, 8, 9, 0 },
	{ 0, 1, 0, 8, 0, 9, 0, 4, 0 },
	{ 0, 8, 9, 5, 0, 1, 3, 0, 2 },
	{ 0, 0, 3, 0, 1, 0, 0, 0, 9 },
	{ 9, 4, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 7, 0, 0, 0, 0, 0, 3, 0 }
};
int main(int argc, char** argv) {
	int solved = 0; 
	while (solved == 0) {
			solved = solve(board);
	}
	int test = blockAvailable(board, 1, 1, 3);
	std::cout << "This better be 0: " << test << std::endl;
	test = blockAvailable(board, 1, 4, 3);
	std::cout << "This better be 1: " << test << std::endl;
	test = blockAvailable(board, 8, 8, 9);
	std::cout << "This better be 0: " << test << std::endl;
	test = blockAvailable(board, 6, 4, 1);
	std::cout << "This better be 1: " << test << std::endl;
}
