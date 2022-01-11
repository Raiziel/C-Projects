/*
Name: Nicholas Munoz, NSHE, 1004, ASSIGNMENT#5
Description: Create a virtual aquarium
Input: Fish Position / Array into a list
Output: Animation frame by frame for the fish
*/
#include "Fish.h"
#include <iomanip> //For drawing the Tank
#include <cstdlib> //Used to flush the Tank
#include <iostream>
#include <vector>
using namespace std;

//Updates the Tank by updating all of the Fish in it in the order that they entered the Tank. This function is implemented for you already.

void Tank::update()
{
	//Update all the fish in the Tank (Make them swim)
	for (Fish* fish : fishList)
		fish->swim(this); //Let it swim
}

//Adds a fish to the Tank
void Tank::addFish(Fish* fish)
{

	//TODO: Add the fish to the tankArr using the fish's x and y positions: 
	// Complete, Check if Error
	//You can assume that the person using this function will not place any fish on top of each other, but error checking is fine
	tankArr[fish->getYPos()][fish->getXPos()] = fish;

	//Add the Fish to the fishList vector
	//Complete, Check if Error
	fishList.push_back(fish);

}

//Attempts to move the fish by the given amount in the x and y directions
void Tank::moveFish(Fish* fish, int xMove, int yMove)
{
	//Find the positions that the fish wants to move to and it's current positions
	int oldXPos = fish->getXPos(); //Previous x position of the fish
	int oldYPos = fish->getYPos(); //Previous y position of the fish
	int newXPos = oldXPos + xMove; //Desired x position to move the fish to
	int newYPos = oldYPos + yMove; //Desired y position to move the fish to
	//TankObject* checkFish = getTankObject(newYPos, newXPos);

	//TODO: Check if the object can move to the desired location (Order of the checks matters!!!)
	// Complete, check if error
	/*You will need to check a few things:
		Check if the fish would go out of bounds of the tank (left of 0, right of width, above 0, or below height)
			If so, don't move it at all, but do call the Fish's onWallCollision() function and return
	Complete: Check Conditions if error
		Else if the space is free (i.e. the space is null and has no fish)
			Set the Fish's old (x, y) position in the tankArr to null (In other words, make it empty)
			Move the fish to the new (x, y) position in the tankArr
			Update the Fish's position using setPosition to its new position
			#Remember that since arrays are row, column that the order of access is arr[y][x], not x, y
	Complete: Check Conditions if error
		Else if the space contains a WallFish, then also call onWallCollision() (Check if the object's char is a 'W')
			Also call onWallCollision*/
	if (newXPos < 0 || newXPos >= width || newYPos < 0 || newYPos >= height)
	{
		fish->onWallCollision();
	}
	else if (tankArr[newYPos][newXPos] == NULL)
	{
		tankArr[oldYPos][oldXPos] = NULL;
		tankArr[newYPos][newXPos] = fish;
		fish->setPosition(newXPos, newYPos);
	}
	else if (tankArr[newYPos][newXPos]->getDrawChar() == 'W')
	{
		fish->onWallCollision();
	}


}

//Draws the tank and all of the fish inside of it. This is a helper function implemented for you.
void Tank::drawTank()
{
	//Clear the screen
	cout << "\033[2J\033[1;1H";

	int i, j;
	cout << "|" << setfill('^') << setw(width + 1) << "|" << endl; //Draw the top of the tank
	for (i = 0; i < height; i++)
	{
		cout << "|"; //Draw the left wall of the tank
		for (j = 0; j < width; j++)
		{
			if (tankArr[i][j] != NULL) //If the space is not empty, draw the fish there
				cout << tankArr[i][j]->getDrawChar();
			else //Else if the space is empty, draw a blank space
				cout << " ";
		}
		cout << "|" << endl; //Draw the right wall of the tank
	}
	cout << "|" << setfill('_') << setw(width + 1) << "|" << endl; //Draw the bottom of the tank
}

//Constructor for the Tank
Tank::Tank(int width, int height)
{
	//Set the width and height members
	this->width = width;
	this->height = height;

	//Allocate the 2D array based on the width and height
	int i, j; //Iteration variables
		/*YOUR CODE HERE*/
	//TODO: Allocate all of the rows first
	//TODO: Allocate the columns in each row next and initialize all the pointers to NULL
	// Complete, Check if error

	int  rows = height;
	int  cols = width;
	// allocate 2-d array
	tankArr = new TankObject * *[rows];
	for (i = 0; i < rows; i++)
	{
		tankArr[i] = new TankObject * [cols];
	}
	// initialize 2-d array
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			tankArr[i][j] = NULL;
		}
	}


}

//Destructor for the Tank
Tank::~Tank()
{
	/* YOUR CODE HERE */

	//TODO: Go through and deallocate all of the fish in the fishList. Then deallocate the 2D tankArr array
	// complete, try put_back if error
		//Deallocate each fish from the fishList
		//Deallocate each of the rows
		//Deallocate the column that held all of the rows
	if (fishList.empty() != true)
	{//Sets all Fish to Null, Deletes
		for (Fish* fish : fishList)
			delete fish; //Let it swim
	}

	if (tankArr != nullptr)
	{
		for (int i = 0; i < height; i++)
			delete[] tankArr[i];
		delete[] tankArr;
		tankArr = nullptr;
	}


}