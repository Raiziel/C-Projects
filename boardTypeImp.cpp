/*
Name: Nicholas Munoz, NSHE, 1004, ASSIGNMENT#4
Description: Create a NXN magic square grid
Input: board size, title
Output: magic number n(n**2 + 1/2) & grid
*/#include <iostream>#include "boardType.h"#include<iomanip>using namespace std;// default constructor that initializes board size
// and checks for valid board sizingboardType::boardType(int boardSize)
{
	// check board size
	if (boardSize < BRD_SIZE_MIN || BRD_SIZE_MAX < boardSize)
	{	
		cout << " Error, invalid board size." << endl;
		cout << "No board created." << endl;
		board = NULL;
		size = 0;

	}
	else
	{	// set size = boardSize
		size = boardSize;
		int    rows = boardSize;
		int    cols = boardSize;
		// allocate 2-d array
		board = new int* [rows];
		for (int i = 0; i < rows; i++)
			board[i] = new int[cols];
		// initialize 2-d array
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				board[i][j] = 0;
	}
}
// destructor deallocates memory
// sets the board = nullptr
// happens when go out of scope
// some extra comment lines since 
// so much is needed and
// i think my code explains enough
boardType::~boardType()
{
	
	if (board != nullptr) {
		for (int i = 0; i < size; i++)
			delete[] board[i];
		delete[] board;
		board = nullptr;
	}
}
// Function that checks if the location is a valid location
// if not valid  then the function prints 
// an error and doesn't alter the value
// if valid then the function sets the cell to the passed value
void boardType::setCell(int row, int column, int value)
{

	if (row < size && row >=0 && column <
		size && column >= 0 &&board!=nullptr)
	{
		board[row][column] = value; // set cell 

	}
	else
	{
		cout << "Error, invalid board location." << endl;
	}
	
	

}
// Function that checks if the location is a valid location
// if not valid  then the function returns 0
// if valid then the function returns the cell
// available throughout whole program
int boardType::getCell(int row, int column) const
{	
	if (row > size || row < 0 || column >size
		|| column < 0||board==nullptr )
	{
		cout << "Error, invalid board location." << endl; // output error
		return 0; // pass back zero
		
	}

	return board[row][column];
	
	
}
// function returns the board size
// available throughout the whole program
int boardType::getOrder() const
{
	return size; // returns board size
}
// Function should print the grid in a formatted manner 
// With each value in a small text box.
// An empty grid should not print anything.
// Function will be called later
void boardType::printGrid() const
{
	if (board == nullptr)
	{
		return;
	}
	
for (int i = 0; i < size; i++)
{
	if (i == 0)
	{
		cout << "   ";
	}
	
	cout << " _____";
}
cout << endl;
for (int i = 0; i < size; i++)
{	
	for (int j = 0; j < size; j++)
	{
		if (j == 0)
		{
			cout << "   ";
		}
		
		cout <<"|     ";
	}
	cout << "|" << endl; 
	for (int j = 0; j < size; j++)
	{
		if (j == 0)
		{
			cout << "   ";
		}
			
		cout <<"|"<< setw(4) << right << board[i][j] << " ";
	}
	cout << "|" << endl;
	for (int j = 0; j < size; j++)
	{
		if (j == 0)
		{
			cout << "   ";
		}
		cout <<"|_____";
	}
	cout << "|" << endl;
}
cout << endl;
return;
	
}


