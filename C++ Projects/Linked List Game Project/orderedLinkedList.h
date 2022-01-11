/*
    Name: Nicholas Munoz, 2000781568, 1004, #9
    Description: Linked ListGame
    Input: EXPECTED_PROGRAM_INPUT
    Output: EXPECTED_PROGRAM_OUTPUT
*/
#ifndef orderedLinkedList_H
#define orderedLinkedList_H
#include <iostream>
#include<list>
#include "linkedListType.h"
using namespace std;


template<class myType>
class orderedLinkedList : public linkedListType <myType> 
{

protected:
using linkedListType<myType>::count;
  // from linkedlist
using linkedListType<myType>::first;
  // from linkedlist
using linkedListType<myType>::last;
  // from linkedlist
public:
	// defined virtual functions 
	bool search(const myType&) const;
	bool insert(const myType&);
	void insertLast(const myType&);
	void deleteNode(const myType&);


};

template <class myType>
// function searches for 
// the values in the ordered list
// if not found 
// return false
bool orderedLinkedList<myType>::search(const myType& value) const
{	
	nodeType<myType>* currentNode = first;//set to head
	while (currentNode != NULL && currentNode->info<=value)
	{
		if (currentNode->info == value) // conditional
		{
			return true; // if found return true
		}
			currentNode = currentNode->link;
		
	}
	return false; // return if cant find
}


template <class myType>
// function inserts value into
// the ordered list
// then returns true when done 
bool orderedLinkedList<myType>::insert(const myType& value)
{
	nodeType<myType>* temp;
	temp = new nodeType<myType>;
	temp->info = value;
	temp->link = NULL;
	if (first == NULL) // conditional
	{
		first = temp; // first to temp
		last = temp; // last to temp 
		count++; // increment 
	}
	else if (value < first->info) // conditional
	{
		temp->link = first; // link to first
		first = temp; // first to temp 
		count++; // increment 
	}
	else if (value > last->info) // conditional
	{
		last->link = temp; // link to temp
		last = temp; // last to temp 
		count++; // increment 
	}
	else
	{
		nodeType<myType>* iter;
		for (iter = first;  value > iter->link->info; iter=iter->link)
		  {}
			temp->link = iter->link;
			iter->link = temp;
			count++;
		
	}

	return true; // when done return
}

template <class myType>
// inserts the last part of the linkedList
void orderedLinkedList<myType>::insertLast(const myType& value)
{
  insert(value);
}

template<class myType>
// function deletes the node
// from the linked list
// if the list is empty
// a statement will be printed
void orderedLinkedList<myType>::deleteNode(const myType& value)
{
	if (first == NULL) // conditional
	{
		cout << "Cannot delete from an empty list." << endl;
		return;
	}
	nodeType<myType>* temp = first;
	if (first->info == value)// conditional
	{
		if (first == last)// conditional
		{
			first = NULL; // set both to null
			last = NULL;
		}
		else { // conditional
			first = first->link;
		}
		delete temp; // delete temp
		count--; // decrement count
	}
	else if (last->info == value)// conditional
	{
		while (temp->link != last) // loop while not last
		{
			temp = temp->link;
			
		}
		        delete last;
			last = temp;
			last->link = NULL;
			count--;
		
	}
	else
	{
		nodeType<myType>* del;
		while (temp != last&& value>temp->info)
		{
			if (temp->link->info == value)
			{
				del = temp->link;
				temp->link = del->link; // temp link to del link
				delete del; // deallocate
				count--; // decrement 
				return;
			}
			temp = temp->link;
		}
		// if not found print statement
		cout << "The item to be deleted is not in the list." << endl;
	}
}



























#endif
