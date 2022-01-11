/*
Name: Nicholas Munoz, NSHE, 1004, ASSIGNMENT#5
Description: Create a virtual aquarium
Input: Fish Position / Array into a list
Output: Animation frame by frame for the fish
*/
#ifndef TANK_H
#define TANK_H

#include <vector>

using namespace std;

class Fish; //Forward declaration of Fish class

//Abstract class for all objects that will be in the Tank
class TankObject
{
	int xPos, yPos; //X,Y coordinates in Tank
protected:
	TankObject(int x, int y, char drawChar)
	{
		this->xPos = x; this->yPos = y; this->drawChar = drawChar;
	}
	char drawChar; //Character used to draw the object in the tank
public:
	TankObject() //Default constructor is needed for allocation of Tank array
	{
		drawChar = ' ';
	}
	void setPosition(int newX, int newY)
	{
		xPos = newX; yPos = newY;
	}
	int getXPos()
	{
		return xPos;
	}
	int getYPos()
	{
		return yPos;
	}
	char getDrawChar() { return drawChar; }
};

//Tank class which will hold all the Fish and water.
class Tank
{
	int width, height;
	//2D-Array representing the Tank. 
	//This is a 2D array of TankObject pointers (Hence the ***). The first two ** are for the dimensions of the 2D array and the 
	//third * is for the actual TankObject itself
	TankObject*** tankArr;
	vector<Fish*> fishList; //List of references to all the fish in the tank

	//Helper functions if the x and y being reversed seems annoying
	void setTankSpace(int x, int y, TankObject* obj) { tankArr[y][x] = obj; }
	TankObject* getTankObject(int x, int y) { return tankArr[y][x]; }

public:
	void update();
	void addFish(Fish* fish);
	void moveFish(Fish* fish, int xMove, int yMove);
	void drawTank();

	//Constructor / Destructor
	Tank(int width, int height);
	~Tank();
};

#endif