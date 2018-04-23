
///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************  
 * PROJECT 4-1; CIS263-PRJ "Backtracking" (Sudoku)
 * CIS 263 MWF 1200-1250, Winter 2017
 * Professor Woodring, Ira
 * @author Krueger, Cody & Van Dyke, Tim
 * @version v1.0 22APR2017 18:45
 *
 * Description: This is the main file for our our sudoku solver.  It acts
 *  as a driver program to begin the backtracking.  It also holds an 
 *  instance of the 2D array we begin with, representing the board. When 
 *  the solution is finished it prints this to the terminal.   
 *
 * References: TODO (update ref-v)
 *  David Baas and Santiago Quiroga- helped me figure out the 
 *   backtracking portion
*  learncpp.com - for ascii values
*  note - my previous cpp class text was learncpp.com
*  http://www.cplusplus.com/reference/stack/stack/stack/ - stack member functions
*  DataStructuresAndAlgorithmAnalysisInCpp_2014.pdf page (103 to 108)
*  Solutions Manual (page 21 to 23)
*  note: Both of these posted on your GitHub
*
***********************************************************************/

//Includes
#include "sudoku.hpp"

//Main Start
int main(int argc, char** argv) {

	//Instance of sudoku board to solve
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

  //Board Prior to Solution
  std::cout << "-------Board Prior to Solution-------" << std::endl;
  printBoard(board);
  
	//Begin Solution Call
	bool solved = false;
	
	solved = solve(board);
	
	//Indicate Preliminary Success
	if (solved) {
	  std::cout << "Preliminary Success" << std::endl;
	}
	
	//test further here?
	printBoard(board);
	//while (solved == 0) {
	//		solved = solve(board);
	//}

	//Tests
	int test = blockAvailable(board, 1, 1, 3);
	std::cout << "This better be 0: " << test << std::endl;
	test = blockAvailable(board, 1, 4, 3);
	std::cout << "This better be 1: " << test << std::endl;
	test = blockAvailable(board, 8, 8, 9);
	std::cout << "This better be 0: " << test << std::endl;
	test = blockAvailable(board, 6, 4, 1);
	std::cout << "This better be 1: " << test << std::endl;

	return true;
}//EoM
