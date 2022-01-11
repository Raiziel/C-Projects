/*
Name: Nicholas Munoz, NSHE, 1004, ASSIGNMENT#4
Description: Create a NXN magic square grid
Input: board size, title
Output: magic number n(n**2 + 1/2) & grid
*/

#ifndef H_boardType
#define H_boardType
#include <string>
#include <iostream>
class boardType
{	//
	public:
	
		// default constructor that initializes board size
		// and checks for valid board sizing
		boardType(int);
		// destructor deallocates memory
		~boardType(); 

		// Function that checks if the location is a valid location
		// if not valid  then the function returns 0
		// if valid then the function returns the cell
		void setCell(int, int, int);
		// Function that checks if the location is a valid location
		// if not valid  then the function returns 0
		// if valid then the function returns the cell
		int getCell(int, int) const;
		int getOrder() const; // function returns the board size
		// Function should print the grid in a formatted manner 
		// With each value in a small text box.
		// An empty grid should not print anything.
		void printGrid() const;//
	//
	private:

		static constexpr int BRD_SIZE_MIN = 3; //
		static constexpr int BRD_SIZE_MAX = 30;//

	protected:
		int size;
		int** board;



}; 
#endif