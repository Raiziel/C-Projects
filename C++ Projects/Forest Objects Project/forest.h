/*
	* Name:Nicholas Munoz, 2000781568, Section 1004
	* Description: Create Game
	* Input: Define in main
	* Output: Results to console
*/
#include <iostream>
#include "object.h"
using namespace std;


//Template class forest with two generic types t1 and t2
template <class t1, class t2>
class forest
{
private:
	int rows;//rows of the grid
	int cols;//columns of the grid
	string** grid;//pointer to pointer to point
	//the dynamic 2d array of string

	t1* obj1;//first object of the forest
	t2* obj2;//second object of the forest

	bool doTheyMeet(int);//private member function to 
	//determine whether two objects meet
	int displayForest(int, int);//private function 
	//to print the forest


public:
	forest(int, int, t1*, t2*);//constructor to initialize the forest.

	void simulate();//function that handles all the movement, 
	//print and other operations of the forest


	~forest();//destructor to deallocate 
	//the dynamic variables.


};

/*Implementation of constructors and member functions begins*/

/*Implement the constructor*/

template<class t1, class t2>
forest<t1, t2>::forest(int newRows, int newCols, t1* type1, t2* type2)
{

	rows = newRows;
	cols = newCols;


	// allocate 2-d array
	grid = new string * [rows];
	for (int i = 0; i < rows; i++)
		grid[i] = new string[cols];
	// initialize 2-d array
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			grid[i][j] = 'X';

	obj1 = type1;
	obj2 = type2;

}

template<class t1, class t2>
void forest<t1, t2>::simulate()
{
	cout << "***********************************" << endl;
	cout << "SIMULATION BEGINS FOR FOREST WITH " << 
		obj1->getName() << " and " << obj2->getName() << endl;
	obj1->move(grid, rows, cols, 0);
	obj2->move(grid, rows, cols, 0);

	obj1->setCurrentPosition(obj1->getStartingPosition().x, 
		obj1->getStartingPosition().y);
	obj2->setCurrentPosition(obj2->getStartingPosition().x, 
		obj2->getStartingPosition().y);
	//cout <<obj1->getCurrentPosition().x
	// <<obj1->getCurrentPosition().y<<endl;
	//cout <<obj2->getCurrentPosition().x
	//<<obj2->getCurrentPosition().y<<endl;

	displayForest(0, 0);
	if (doTheyMeet(0))
	{
		if (obj1->getSymbol() == 'T' && obj2->getSymbol() == 'G')
			cout << obj1->getName() << " FINDS " << 
			obj2->getName() << " but TIGER doesn't eat grass" << endl;
		else
			cout << obj1->getName() << " EATS " << 
			obj2->getName() << endl;
	}
	else
		cout << obj1->getName() << " COULDN'T FIND " << 
		obj2->getName() << endl;

	cout << "SIMULATION ENDS" << endl;
	cout << "***********************************" << endl;
}

/*Implement the displayForest function*/
template<class t1, class t2>
int forest<t1, t2>::displayForest(int row, int col)

{
	if (col == cols)
	{
		col = 0;

		row++;
		cout << endl;
		cout << endl;
	}
	if (row == rows)
	{
		return 0;
	}

	cout << grid[row][col] << "\t";

	return displayForest(row, col + 1);

}

/*Implement the doTheyMeet function*/
template<class t1, class t2>
bool forest<t1, t2>::doTheyMeet(int next)
{
	bool save;
	obj1->getCurrentPosition();
	obj2->getCurrentPosition();
	int x1 = obj1->getCurrentPosition().x;
	int x2 = obj2->getCurrentPosition().x;
	int y1 = obj1->getCurrentPosition().y;
	int y2 = obj2->getCurrentPosition().y;
	//char set_path1 = ob1.path().at(next);
	//char set_path1 = ob2.path().at(next);
	try {

		if (x1 == x2 && y1 == y2)
		{
			return true;
		}
		if (x1 > rows || x1 < 0 ||
			y1 > cols || y1 < 0 || x2 >rows ||
			x2 < 0 || y2 > cols ||
			y2 < 0)
		{
			return false;
		}

		// sets position for both objects

		obj1->setCurrentPosition(obj1->getPath().at(next));
		obj2->setCurrentPosition(obj2->getPath().at(next));
		save = doTheyMeet(next + 1);


	}
	catch (std::out_of_range const& e)
	{
		return false;
	}


	return save;
}



template<class t1, class t2>
forest<t1, t2>::~forest()
{
	delete obj1;
	delete obj2;

	for (int i = 0; i < rows; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
}
/*Implementation ends*/
