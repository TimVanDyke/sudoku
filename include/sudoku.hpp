#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int solve (int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
		}
	}
	return 1;
}


//returns the lowest available number in a row
int checkRow (int board[9][9], int i) {
	int lowest = 1;
	int prev = 0; 
	while (lowest != prev) {
		prev = lowest;
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != 0 && board[i][j] == lowest) {
				lowest++;
			}
		}
	}
	return lowest;
}


//returns the lowest available number in a column
int checkCol (int board[9][9], int i) {
	int lowest = 1;
	int prev = 0; 
	while (lowest != prev) {
		prev = lowest;
		for (int j = 0; j < 9; j++) {
			if (board[j][i] != 0 && board[j][i] == lowest) {
				lowest++;
			}
		}
	}
	return lowest;
}

//makes sure the num is available for row
//returns 0 for false, 1 for true
int rowAvailable(int board[9][9], int row, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == num) {
			return 0;
		}
	}
	return 1;
}

//returns the lowest available number in a block
//use 0 through 8 to reference the blocks
//0, 1, 2,   this is the structure
//3, 4, 5,   for how to reference
//6, 7, 8    different blocks
int checkBlock (int board[9][9], int blockNum) {
	int lowest = 1;
	int prev = 0; 
	int j = 0;
	int i = 0;
	switch(blockNum) {
		case 0 : break; 
		case 1 : j += 3; break;
		case 2 : j += 6; break;
		case 3 : i += 3; break;
		case 4 : i += 3; j += 3; break;
		case 5 : i += 3; j += 6; break;
		case 6 : i += 6; break;
		case 7 : i += 6; j += 3; break;
		case 8 : i += 6; j += 6; break;
	}
	int prevI = i;
	int prevJ = j;
	int iEnd = i + 3;
	int jEnd = j + 3;
	while (lowest != prev) {
		prev = lowest;
		for ( i = prevI; i < iEnd; i++) {
			for (j = prevJ; j < jEnd; j++) {
				if (board[i][j] != 0 && board[i][j] == lowest) {
					lowest++;
				}
			}
		}
	}
	return lowest;
}

//makes sure the num is available for col
//returns 0 for false, 1 for true
int colAvailable(int board[9][9], int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == num) {
			return 0;
		}
	}
	return 1;
}
//makes sure the num is available for the square
//returns 0 for false, 1 for true;
int blockAvailable(int board[9][9], int col, int row, int num) {
	int blockNum = 0;
	if (row < 3) {
		if (col < 3) {
			blockNum = 0;
		}else if (col < 6) {
			blockNum = 1;
		}else {
			blockNum = 2; 
		}}
	else if (row < 6) {
		if (col < 3) {
			blockNum = 3; 
		}else if (col < 6) {
			blockNum = 4;
		}else {
			blockNum = 5;
		}}
	else {
		if (col < 3) {
			blockNum = 6;
		}else if (col < 6) {
			blockNum = 7;
		}else {
			blockNum = 8;
		}
	}

	int i = 0;
	int j = 0;
	switch(blockNum) {
		case 0 : break; 
		case 1 : j += 3; break;
		case 2 : j += 6; break;
		case 3 : i += 3; break;
		case 4 : i += 3; j += 3; break;
		case 5 : i += 3; j += 6; break;
		case 6 : i += 6; break;
		case 7 : i += 6; j += 3; break;
		case 8 : i += 6; j += 6; break;
	}
	int prevI = i;
	int prevJ = j;
	int iEnd = i + 3;
	int jEnd = j + 3;
	for ( i = prevI; i < iEnd; i++) {
		for (j = prevJ; j < jEnd; j++) {
			if (board[i][j] == num) {
				return 0;
			}
		}
	}
	return 1;
}

void printBoard (int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << "[" << board[i][j] << "]";
		}	
		std::cout << std::endl;
	}
}
