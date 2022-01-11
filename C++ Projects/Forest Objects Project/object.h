/*
	* Name:Nicholas Munoz, 2000781568, Section 1004
	* Description: Create Game
	* Input: Define in main
	* Output: Results to console
*/
#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

using namespace std;

//Struct position to hold x and 
//y position within the grid
struct position
{
	int x;
	int y;
};

//object class that will be the base 
//class of three objects. Tiger, deer and grass
class object
{
private:
	string name;//name of the object
	string path;//path of the object
	char symbol;//symbol of the object
	position currentPosition;//current position of the object
	position startingPosition;//starting position of the object
public:
	object(string, char, string, position);//constructor to 
	//initialize the object with name, 
	//symbol, path and starting position

	object(object&);//copy constructor

	void move(string**&, int, int, int);//move function 
	//that traces the movement of objects

	/*Getter functions*/
	string getName();
	char getSymbol();
	string getPath();
	position getCurrentPosition();
	position getStartingPosition();
	/*****************************/

	/*Mutator function to set the current position.*/
	void setCurrentPosition(int, int);

	void setCurrentPosition(char);
	/*********************************************/
};

//Tiger class
class tiger : public object
{
public:
	tiger(string n, char s, string p, position pos) : object(n, s, p, pos) {}
};

//Deer class
class deer : public object
{
public:
	deer(string n, char s, string p, position pos) : object(n, s, p, pos) {}

};

//Grass class
class grass : public object
{
public:
	grass(string n, char s, string p, position pos) :object(n, s, p, pos) {}

	//grass(grass& g): object(g){}
};


/*Implementation of constructors 
and member functions of object class*/
object::object(string n, char s, string p, position pos)
{
	name = n; // name
	path = p; // path
	symbol = s; // symbol

	currentPosition = pos; // position
	startingPosition = pos;// position
}

object::object(object& obj)
{
	name = obj.name;
	path = obj.path;
}

/*Implement the move function*/
// moves animal
void object::move(string**& frst, int rows, int cols, int start)
{




	getSymbol();
	getName();
	getCurrentPosition();
	int x2 = currentPosition.x;
	int y2 = currentPosition.y;


	try {
		if (x2 > rows || x2<0 || x2>cols)
		{
			throw name + " went out of the forest";
		}

		if (y2 > cols || y2<0 || y2>rows+1)
		{
			throw name + " went out of the forest";
		}


		if (frst[x2][y2] == "X")
		{
			frst[x2][y2] = symbol;
		}
		else
		{
			frst[x2][y2] = frst[x2][y2] + symbol;
		}

		setCurrentPosition(path.at(start));
		cout << name << " is moving" << endl;


		move(frst, rows, cols, start + 1);
		return;

	}

	catch (out_of_range const& e)
	{
		cout << name + " finished moving" << endl;
		return;
	}
	catch (string err)
	{
		cout << err << endl;
		return;
	}

}
// returns object name
string object::getName()
{
	return name;
}
// returns object sym
char object::getSymbol()
{
	return symbol;
}
// returns object path
string object::getPath()
{
	return path;
}
// returns object curr pos
position object::getCurrentPosition()
{
	return currentPosition;
}
// returns object curr pos
position object::getStartingPosition()
{
	return startingPosition;
}
// setsject curr pos
void object::setCurrentPosition(int x, int y)
{
	currentPosition.x = x;
	currentPosition.y = y;
}
// setsject  pos
void object::setCurrentPosition(char nextDirection)
{
	switch (nextDirection)
	{
	case 'U':
		--currentPosition.x;
		break;
	case 'D':
		++currentPosition.x;
		break;
	case 'L':
		--currentPosition.y;
		break;
	case 'R':
		++currentPosition.y;
	}
}

#endif
