/*
Name: Nicholas Munoz, NSHE, 1004, ASSIGNMENT#4
Description: Create a NXN magic square grid
Input: board size, title
Output: magic number n(n**2 + 1/2) & grid
*/

#include <iostream>
#include<iomanip>
#include"magicSquareType.h"
using namespace std;
/* constructor should set the title and use the base class
constructor to allow the base class to create the grid.*/
magicSquareType::magicSquareType(int Size, 
	std::string boardTitle):boardType(Size)
{
	title = boardTitle;
}

void magicSquareType:: printMagicSquare() const
{
	const char* bold = "\033[1m";
	const char* unbold = "\033[0m";
	cout << bold << "CS 202 - Magic Squares" << endl;
	cout << " Title: " << title << endl;
	cout << " Magic Square, order: " << boardType::getOrder() << endl;
	cout << " Magic Number: " << magicNumber() << unbold << endl;
	printGrid();
	
}
/*function should prompt the user for a title 
(ensuring it is not empty). The title may be multiple words. 
Then read integers, one row at a time 
(based on the board size for the current object).*/
void magicSquareType::readMagicSquare()
{

	cout << "Enter " << size << "x" << size << " Magic Square."
		<< endl << endl;

	if (title == "")
	{
		getline(cin, title);
		cout << "Enter Title:";
		cin >> title;
		cout << title << endl;
	}
	if (board == nullptr)
	{
		return;
	}
	
	cout << endl << "Enter Magic Square Values (" << size << "x"
		<< size << ")" << endl;

	int value;
	cout << "Enter row values" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
				cin >> value;
				setCell(i, j, value);
		}

	}
}
	// ^finish this function need to figure out how to 
	// input value into area either directly or by function call
	// with setCell
	

/*function should validate a magic square 
by ensuring the sum of each column, each row, and 
each of the two main diagonals sum to the magic number*/
bool magicSquareType ::validateMagicSquare() const
{	// if board is empty do nothing
	if (board==nullptr)
	{
		return false;
	}
	
	int sum = 0; // sum = 0
	for (int i = 0; i < size; i++) // sum of rows
	{
		for (int j = 0; j < size; j++)// sum of rows
		{
			if (i == size - 1)			// sum of rows
				sum = sum + board[i][j];	// sum of rows
		}
	}
	if (sum != magicNumber())// not magic number sum
	{
		return false;// not magic number sum
	}
	
	sum = 0; // sum = 0
	for (int i = 0; i < size; i++) // sum of columns
	{
		for (int j = 0; j < size; j++) // sum of columns
		{
			if (i == size - 1)		// sum of columns
				sum = sum + board[j][i];// sum of columns
		}

	}
	if (sum != magicNumber()) // not magic number sum
	{
		return false; // not magic number sum
	}
	
	sum = 0; // sum = 0
	for (int i = 0; i < size; i++) // sum of left diagonal
	{
		for (int j = 0; j < size; j++)// sum of left diagonal
		{
			if (i == j)					// sum of left diagonal
				sum = sum + board[i][i];	// sum of left diagonal
		}

	}
	if (sum != magicNumber())// not magic number sum
	{
		return false;// not magic number sum
	}
	sum = 0;// sum = 0
	for (int i = 0; i < size; i++)// sum of right diagonal
	{
		for (int j = 0; j < size; j++)// sum of right diagonal
		{
			if (i + j == size - 1)		// sum of right diagonal
				sum = sum + board[i][j];	// sum of right diagonal
		}

	}
	if (sum != magicNumber())// not magic number sum
	{
		return false;// not magic number sum
	}
	cout <<  endl;
	return true; // is magic number sum
}
//  function should reset each cell entry to 0 
// and clear the title string.
void magicSquareType ::clearMagicSquare()
{	
	title = ""; // set an empty title
	if(board==nullptr)
	{	// do nothing
		return;
	}
	// set all entries to 0
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			setCell(i, j, 0);
		}
	}
}
//function should return the magic number 
// or sum based on the board size or order.
int magicSquareType ::magicNumber() const
{	
	int n = size;
	int magicNumber = n * ((n * n + 1) / 2);
	return magicNumber;
}
// function passes back the current title value
std::string magicSquareType::getTitle() const
{
	return title;
}
// function sets a new current title when called
void magicSquareType::setTitle(std::string boardTitle)
{
	title = boardTitle;
}

/*should create a magic square based on the current order using
one of the provided algorithms.*/
void magicSquareType::createMagicSquare()
{	// Creates Grid
	// odd order
	if (size % 2 == 1)
	{
		int row, row2, col, col2;
		row = 0;
		col = size / 2;

		for (int i = 1; i <= size * size; i++)
		{
			board[row][col] = i;
			if (i % size == 0)
			{
				row++;
			}
			else
			{

				if (row == 0)
				{
					row = size - 1;
				}

				else
				{
					row--;
				}

				if (col == (size - 1))
				{
					col = 0;
				}

				else
				{
					col++;
				}

			}

		}
	}
	if (size % 4 == 0)
	{	
		int counter = 1;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{

				if (i % 4 != j % 4 || i % 4 + j % 4 != 3)
				{
					board[i][j] = counter;
				}

				counter++;
			}

		}

		counter = 1;
		for (int i = size - 1; i >= 0; i--)
		{
			for (int j = size - 1; j >= 0; j--)
			{

				if (i % 4 == j % 4 || i % 4 + j % 4 == 3)
				{
					board[i][j] = counter;
				}

				counter++;
			}


		}
	}
	// single even grid
	if (size % 2 == 0) // mod 2 
	{
		int half = size / 2; // half of size
		int counter = 1; // counter to increment
		// A
		int row = 0;
		int col = size / 2;
		for (int i = 1; i <= size * size; i++)
		{
			board[row][col] = i;
			if (i % size == 0)
			{
				row++;
			}
			else
			{

				if (row == 0)
				{
					row = size - 1;
				}

				else
				{
					row--;
				}

				if (col == (size - 1))
				{
					col = 0;
				}

				else
				{
					col++;
				}

			}

		}
	//B Grid
	for (int i = 1; i <= size * size; i++)
	{
		board[row][col] = i;
		if (i % size == 0)
		{
			row++;
		}
		else
		{

			if (row == 0)
			{
				row = size - 1;
			}

			else
			{
				row--;
			}

			if (col == (size - 1))
			{
				col = 0;
			}

			else
			{
				col++;
			}

		}

	}

	//C Grid
	for (int i = 1; i <= size * size; i++)
	{
		board[row][col] = i;
		if (i % size == 0)
		{
			row++;
		}
		else
		{

			if (row == 0)
			{
				row = size - 1;
			}

			else
			{
				row--;
			}

			if (col == (size - 1))
			{
				col = 0;
			}

			else
			{
				col++;
			}

		}

	}

	for (int i = 1; i <= size * size; i++)
	{
		board[row][col] = i;
		if (i % size == 0)
		{
			row++;
		}
		else
		{

			if (row == 0)
			{
				row = size - 1;
			}

			else
			{
				row--;
			}

			if (col == (size - 1))
			{
				col = 0;
			}

			else
			{
				col++;
			}

		}

	}

		 
		int nCols = half / 2; // quarter of size
		int temp; // variable holds values
		// swap#1
		for (int i = 0; i < half - 1; i++)
		{
			for (int j = 0; j < nCols - 1; j++)
			{
				temp = board[i][j];
				board[i][j] = board[i + half][j];
				board[i + half][size - j] = temp;
			}
		}
		// swap#2
		for (int i = 0; i < half - 1; i++)
		{
			for (int j = 0; j < nCols - 1; j++)
			{
				temp = board[i][size - j];
				board[i][size-j] = board[i + half][size - j];
				board[i + half][size - j] = temp;
			}
		}

		//swap #3
		temp = board[0][nCols + 1];
		board[0][nCols + 1] = board[0][nCols + 1 + half];
		board[0][nCols + 1 + half] = temp;
		//swap#4
		temp = board[nCols + 1][nCols + 1];
		board[nCols + 1][nCols + 1] = board[nCols + 1][nCols + 1 + half];
		board[nCols + 1][nCols + 1 + half] = temp;

	}
}
