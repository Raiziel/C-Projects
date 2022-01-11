/*
	Name: Nicholas Munoz, 2000781568, 1004, #10
	Description: Audio Reverser
	Input: EXPECTED_PROGRAM_INPUT
	Output: EXPECTED_PROGRAM_OUTPUT
*/
#include <iostream>
#include<list>
using namespace std;
#ifndef linkedStack_H
#define linkedStack_H
// create nodeType struct
template <class myType>
struct nodeType {
	myType* dataSet;
	unsigned int top;
	nodeType<myType>* link;
};

// class template 
template<class myType>
class linkedStack
{

private:
	nodeType<myType>* stackTop;
	unsigned int size;
	unsigned int count;
	static constexpr unsigned int ARR_MIN = 5;
	static constexpr unsigned int ARR_MAX = 96000;
	static constexpr unsigned int ARR_DEFAULT = 22050;

public:
	linkedStack(unsigned int = ARR_DEFAULT);
	~linkedStack();
	bool isEmptyStack() const;
	void initializeStack();
	unsigned int stackCount();
	void push(const myType& newItem);
	myType top() const;
	void pop();
};
/* The linkedStack() constructor should initialize the stack 
to an empty state(stackTop = nullptr).If the passed link array size 
is not valid, set the size to the default
(ARR_DEFAULT). */

template<class myType>
linkedStack<myType>::linkedStack(unsigned int newSize)
{
	if (newSize < ARR_MIN || newSize>ARR_MAX)
	{
		size = ARR_DEFAULT;
	}
	else
	{
		size = newSize;
	}
	stackTop = nullptr;
	count = 0;
}

/*The ~linkedStack() destructor should 
delete the stack (including releasing all the allocated
memory)*/
template<class myType>
linkedStack<myType>::~linkedStack()
{
	nodeType<myType>* temp;
	while (stackTop != nullptr)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete [] temp->dataSet;
		delete temp;
	}
}

// Function returns stack count
template<class myType>
unsigned int linkedStack<myType>::stackCount()
{
	return count;
}

/*The initializeStack() function will create 
and initialize a new, empty stack*/
template<class myType>
void linkedStack<myType>::initializeStack()
{
	nodeType<myType>* temp;
	while (stackTop != nullptr)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete[] temp->dataSet;
		delete temp;
	}
	stackTop = new nodeType<myType>;
	stackTop->dataSet = new myType[size];
	stackTop->top = 0;
	stackTop->link = nullptr;
}

/*The isEmptyStack() function should determine 
whether the stack is empty, returning true
if the stack is empty and false if no*/
template<class myType>
bool linkedStack<myType>::isEmptyStack() const
{
	if (stackTop == nullptr)
	{
		return true;
	}
	if (stackTop->link == nullptr && stackTop->top == 0)
	{
		return true;
	}
	return false;
}

// will return the current top of the stack without removing it.
template<class myType>
myType linkedStack<myType>::top() const
{
	if (isEmptyStack() == true)
	{
		return 0;
	}
	return stackTop->dataSet[stackTop->top - 1];
}
/* function will add the passed item to the top of the stack.
The top variable should be used to 
track the stack top for the current node. 
If current node array is full, a new node with a new node 
array must be created to hold the new item*/
template<class myType>
void linkedStack<myType>::push(const myType& newItem)
{
	if (stackTop == nullptr)
	{
		initializeStack();
	}
	if (stackTop->top == size)
	{
		nodeType<myType>* temp = new nodeType<myType>;
		temp->dataSet = new myType[size];
		temp->link = stackTop;
		stackTop = temp;
		stackTop->top = 0;
	}
	stackTop->dataSet[stackTop->top] = newItem;
	stackTop->top++;
	count++;
}
/*function will remove the top item from the stack 
(and return nothing). If the stack is empty, 
nothing should happen and no error message. 
If the item removed is the last item from the node array, 
the node link must be deleted along with the node array*/
template<class myType>
void linkedStack<myType>::pop()
{
	if (isEmptyStack() == true)
	{
		return;
	}
	stackTop->top--;
	if (stackTop->top == 0)
	{
		nodeType<myType>* temp = stackTop;
		stackTop = stackTop->link;
		delete[] temp->dataSet;
		delete temp;
	}
	count--;
}

#endif


