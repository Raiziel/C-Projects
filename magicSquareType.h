/*
Name: Nicholas Munoz, NSHE, 1004, ASSIGNMENT#4
Description: Create a NXN magic square grid
Input: board size, title
Output: magic number n(n**2 + 1/2) & grid
*/

#ifndef H_magicSquareType
#define H_magicSquareType
#include <string>
#include <iostream>
#include"boardType.h"

class magicSquareType: public boardType{

public:
		/* constructor should set the title and use the base class
		constructor to allow the base class to create the grid.*/
	    magicSquareType(int, std::string);

		void createMagicSquare();

		/*should create a magic square based on the current order using
		one of the provided algorithms.*/
		void printMagicSquare() const;

		/*function should prompt the user for a title
		(ensuring it is not empty). The title may be multiple words.
		Then read integers, one row at a time
		(based on the board size for the current object).*/
		void readMagicSquare();

		/*function should validate a magic square
		by ensuring the sum of each column, each row, and
		each of the two main diagonals sum to the magic number*/
		bool validateMagicSquare() const;

		//  function should reset each cell entry to 0 
		// and clear the title string.
		void clearMagicSquare();

		//function should return the magic number 
		// or sum based on the board size or order.
		int magicNumber() const;

		// function passes back the current title value
		std::string getTitle() const;

		// function sets a new current title when called
		void setTitle(std::string);


private:
	std::string title;




};
#endif // !H_magicSquareType