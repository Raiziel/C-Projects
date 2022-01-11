/*
    Name: Nicholas Munoz, 2000781568, 1004, #9
    Description: Linked ListGame
    Input: EXPECTED_PROGRAM_INPUT
    Output: EXPECTED_PROGRAM_OUTPUT
*/
#include <iostream>
#include<list>
using namespace std;
#ifndef unorderedLinkedList_H
#define unorderedLinkedList_H
#include "linkedListType.h"

template<class myType>
class  unorderedLinkedList: public linkedListType<myType>
{

protected:
	// from linkedList
	using linkedListType<myType>::count;
	// from linkedList
	using linkedListType<myType>::first;
	// from linkedList
	using linkedListType<myType>::last;
public:
	// Implemented virtual functions
	bool search(const myType&) const ;
	bool insert(const myType&) ;
	void insertLast(const myType&) ;
	void deleteNode(const myType&) ;


};

template <class myType>
// function searches
// for the passed in value
// to compare and see if it will
// succesfully search 
// else it returns false
bool unorderedLinkedList<myType>::search(const myType& value) const
{   
	nodeType<myType>* currentNode = first;
	while (currentNode != NULL) 
	{
		if (currentNode->info == value) 
		{
			return true;
		}
		
		currentNode = currentNode->link;
		
	}
	return false;
}


template <class myType>
// function inserts a value
// into the list
// to the front
bool unorderedLinkedList<myType>::insert(const myType& value)
{
	nodeType<myType>* temp;
	temp = new nodeType<myType>;
	temp->info = value;
	temp->link = first;
	first = temp;
	if (last == NULL)
	{
		last = first;
	}
	count++;
	return true;
}

template <class myType>
// function inserts the
// last value of 
// the list 

void unorderedLinkedList<myType>::insertLast(const myType& value)
{       nodeType<myType>*temp; // initialize temp
	temp = new nodeType<myType>; // set temp
	temp->info = value; // set info
	temp->link = NULL; // set link to null
	if (last == NULL) // conditional
	{
		first = temp;
		last = temp;
	}
	else // conditional
	{
		last->link = temp;
		last = temp;
	}
	count++;
}

template<class myType>
// this function
// will delete 
// a node and 
// this will be used to
// clear the list
void unorderedLinkedList<myType>::deleteNode(const myType& value)
{
	if (first == NULL)// conditional
	{
		cout << "Cannot delete from an empty list." << endl;
		return;
	}
	nodeType<myType>* temp = first;
	if (first->info == value)
	{
		if (first == last)// conditional
		{
			first = NULL;
			last = NULL;
		}
		else { // conditional
			first = first->link;
		}
		delete temp;
		count--;
	}
	else if (last->info == value)
	{
		while (temp->link != last)
		{
			temp = temp->link;
		}
		delete last; // deletes last
		last = temp; // last set to temp
		last->link = NULL; // last->link set to null
		count--; // decrement count
	}
	else
	{
		nodeType<myType>* del; 
		// variable used to delete
		while (temp != last)
		{
			if (temp->link->info == value)
			{
				del = temp->link;
				temp->link = del->link;
				delete del; // delete del
				count--; // decrement
				return; // return
			}
			temp = temp->link;
		}
		// print when nothing is found 
		cout << "The item to be deleted is not in the list." << endl;
	}
}












#endif