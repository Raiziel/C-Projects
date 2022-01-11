/*
    Name: Nicholas Munoz, 2000781568, 1004, #9
    Description: Linked ListGame
    Input: EXPECTED_PROGRAM_INPUT
    Output: EXPECTED_PROGRAM_OUTPUT
*/
#include <iostream>
#include<list>
using namespace std;
// headerguard
#ifndef linkedListType_H
#define linkedListType_H
// create nodeType struct
template <class myType>
struct nodeType {
	myType info;
	nodeType<myType>* link;
};
// class template 
template<class myType>
class linkedListType 
{

protected:
	int count;
	nodeType<myType>* first; // head of list
	nodeType<myType>* last; // tail of list
public:
// all public functions
// for derived classes
// ordered and unordered
	linkedListType();
	linkedListType(const linkedListType<myType>&);
	~linkedListType();
	void initializeList() ;
	bool  isEmptyList() const;
	void print() const;
	void reversePrint() const;
	int length() const;
	void destroyList();
	myType front() const;
	myType back() const;
	nodeType<myType>* firstPtr() const;
	virtual bool search(const myType&) const = 0;
	virtual bool insert(const myType&) = 0;
	virtual void insertLast(const myType&) = 0;
	virtual void deleteNode(const myType&) = 0;
	void copyList(const linkedListType<myType> & );
private:
	void recursiveReversePrint(nodeType<myType>*) const;
};



template<class myType>
// intializes values
// the default constructor
linkedListType<myType>::linkedListType()
{
	first = NULL; // to null
	last = NULL; // to null 
	count = 0; // to zero
}

template<class myType>
// copy constructor 
// does a deep copy
linkedListType<myType>::linkedListType(const linkedListType<myType>& rhs)
{
count = rhs.length();
first = NULL; // set to null
last = NULL; // set to null
// if rhs is not empty then copy 
 if (rhs.isEmptyList() ==false)
	{
		copyList(rhs); // call copy
	}

}


template<class myType>
// destructor
// when out of scope and need
// to deallocate mem
linkedListType<myType>::~linkedListType()
{
	destroyList();
}

template<class myType>
// starts with an empty list
void linkedListType<myType>::initializeList() 
{	
	destroyList(); // call to destroy

}

template<class myType>
// this function
// checks if the list is empty
// and returns based on the boolean
bool  linkedListType<myType>::isEmptyList() const
{
	if (first == NULL)
	{
		return true;
	}
	
	return false;
	
	
}


template<class myType>
// this function prints out 
// the items in the list 
// with a space
void linkedListType<myType>::print() const
{
	for (nodeType<myType>*ptr = first; ptr != NULL; ptr = ptr->link)
	{
		cout << ptr->info << " ";
	}
	
}


template<class myType>
// this function prints in reverse
void linkedListType<myType>::reversePrint() const
{
	recursiveReversePrint(first);
}

template<class myType>
// returns count
int linkedListType<myType>::length() const
{
	return count;
}

template<class myType>
// this resets all
// default variables to
// null & 0
void linkedListType<myType>::destroyList()
{
	if (first == NULL)
	{
	  return;
	}
	nodeType<myType>* temp;
	while (first != last)
	{
		temp = first->link;
		delete first;
		first = temp;
		
	}
	delete first; //deallocate
	first = NULL; // to null
	last = NULL; // to null 
	count = 0; // to zero
}

template<class myType>
// returns the info of the front of the 
// list
myType linkedListType<myType>::front() const
{
	if (first != NULL)
	{
		return first->info;
	}
	
	
	return 0;
	
}

template<class myType>
// returns the info end of the list
myType linkedListType<myType>::back() const
{
	if (last != NULL) // conditional
	{
		return last->info;
	}
	
	return 0; // if null return 0
	
}
template<class myType>
// returns the front of the list 
nodeType<myType>* linkedListType<myType>::firstPtr() const
{
	return first;
}

template<class myType>
void linkedListType<myType>::recursiveReversePrint
(nodeType <myType>* list) const
{
	if (list == NULL) // conditional
	{
	  return; // if empty return
	}

	
	recursiveReversePrint(list->link);
	cout << list->info << " ";
}

template<class myType>
// this function 
void linkedListType<myType>::copyList(const linkedListType<myType>& list)
{	// set first to new type
	first = new nodeType<myType>;
	first->link = NULL;
	// create two pointers 
	// to hold values
	nodeType<myType>* original=list.first;
	nodeType<myType>* copy=first;
        // copy info and next link
	copy->info = original->info;
	original = original->link;
	while (original != NULL)
	{
		copy->link = new nodeType<myType>;
		copy = copy->link;
		copy->info = original->info;
		original = original->link;
	}
	copy->link = NULL;
	last = first;
	while (last->link != NULL)
	{
		last = last->link;
	}


}




#endif


