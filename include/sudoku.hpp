
///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************  
 * PROJECT 4-2; CIS263-PRJ "Backtracking" (Sudoku)
 * CIS 263 MWF 1200-1250, Winter 2017
 * Professor Woodring, Ira
 * @author Krueger, Cody & Van Dyke, Tim
 * @version v1.0 22APR2017 18:45
 *
 * Description: This is the header file containting the function 
 *  definitions for all helper functions needed for the sudoku solution 
 *  primary method. The primary method uses backtracking to solve the 
 *  puzzle.    
 *
 * References: 
 *  David Baas and Santiago Quiroga- helped me figure out the 
 *   backtracking portion
***********************************************************************/

//Includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//Function Declarations
bool solve(int board[9][9]);
bool solve(int board[9][9], int row, int col);
bool rowAvailable(int board[9][9], int row, int num);
bool colAvailable(int board[9][9], int col, int num);
bool blockAvailable(int board[9][9], int col, int row, int num);
void printBoard (int board[9][9]);

//These Methods were not used not used in the logic, so we did not comment them
int checkRow(int board[9][9], int i);
int checkCol(int board[9][9], int i);
int checkBlock(int board[9][9], int blockNum);

/***********************************************************************  
 * This method serves as the driver method for the program, giving main
 * a place to enter. 
 * 
 * @param int[9][9] - the board to solve 
 * @return bool - true if there was sucess, take from call to inner solve
 ***********************************************************************/
bool solve (int board[9][9]) {
	return solve(board, 0, 0);
}

/***********************************************************************  
 * This method is the actual recursive function, holding the true logic
 * of the problem.
 * 
 * @param int[9][9] - the board to solve 
 * @param int row - the row to examine
 * @return int col - the col to examine
 ***********************************************************************/
bool solve (int board[9][9], int row, int col) {
  //std::cout << "next step" << std::endl; //Testing**
  //printBoard(board);  //Testing**
  //Base Case: finished state achieved
  if (row == 8 && col == 9) {
    std::cout << "-------FINISHED STATE ACHIEVED-------" << std::endl;
    printBoard(board);
    return true;
  }
  
  //Row Return
  if (col == 9) {
    ++row;
    col = 0;
  }
  
  //-----Checking Phase Begins-----
  //If current position is "empty" search for add
  if (board[row][col] == 0) {
    //std::cout << "got here" << std::endl; //Testing**
    //int temp = checkRow(board, row);
    //int temp = 1;
    for(int temp = 1; temp < 10; temp++) {
      //std::cout << "Temp: " << temp << std::endl;
      //std::cout << "Row: " << row << std::endl;
      //std::cout << "Col: " << col << std::endl;
      //Check if the temp works for the row, col, and block
      if (rowAvailable(board, row, temp) && 
          colAvailable(board, col, temp) && 
          blockAvailable(board, row, col, temp)) 
        {
            //If true (meaning legal), change value
            board[row][col] = temp;
            if (solve (board, row, col + 1)) {
              return true;
            }
      }
      //else
      //  temp++;
    }//EoW
    
  }
  //If space is not "empty", continue past it, leaving the value.
  else {
    if (solve (board, row, col + 1)) {
      return true;
    }
    else
      return false;
  }
  
  //Finally if this failed, backtrack
  // note, how does this react to the numbers given? I imagine this could overwrite them
  board[row][col] = 0;
  return false;
}

//THIS METHOD IS UNUSED SO IT IS LEFT UNCOMMENTED
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

//THIS METHOD IS UNUSED SO IT IS LEFT UNCOMMENTED
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

/***********************************************************************  
 * This method makes sure that the number given 'num' is not already 
 * takin in the row 'row'
 * 
 * @param the board
 * @param int row
 * @param int num
 * @return bool
 ***********************************************************************/
bool rowAvailable(int board[9][9], int row, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == num) {
			return false;
		}
	}
	return true;
}

//THIS METHOD IS UNUSED SO IT IS LEFT UNCOMMENTED
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

/***********************************************************************  
 * This method makes sure that the number given 'num' is not already 
 * takin in the col 'col'
 * 
 * @param the board
 * @param int col
 * @param int num
 * @return bool
 ***********************************************************************/
bool colAvailable(int board[9][9], int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == num) {
			return false;
		}
	}
	return true;
}
/***********************************************************************  
 * This method makes sure that the number given 'num' is not already 
 * takin in the block based around 'row' and 'col'
 * 
 * @param the board
 * @param int row
 * @param int col
 * @param int num
 * @return bool
 ***********************************************************************/
bool blockAvailable(int board[9][9], int row, int col, int num) {
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
				return false;
			}
		}
	}
	return true;
}

/***********************************************************************  
 * This method prints out the board in a nice format to look at
 * 
 * @param the board
 ***********************************************************************/
void printBoard (int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << "[" << board[i][j] << "]";
		}	
		std::cout << std::endl;
	}
}
