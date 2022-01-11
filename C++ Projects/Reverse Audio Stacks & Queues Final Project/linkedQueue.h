/*
	Name: Nicholas Munoz, 2000781568, 1004, #10
	Description: Audio Reverse Queue
	Input: EXPECTED_PROGRAM_INPUT
	Output: EXPECTED_PROGRAM_OUTPUT
*/
#include <iostream>
#include<list>
using namespace std;
#ifndef linkedQueue_H
#define linkedQueue_H
// create nodeType struct
template<class myType>
struct queueNode
{
	myType* dataSet;
	unsigned int front, back;
	queueNode<myType>* link;
};
// class template 
template<class myType>
class linkedQueue
{
private:
	queueNode<myType>* queueFront;
	queueNode<myType>* queueRear;
	unsigned int size;
	unsigned int count;
	static constexpr unsigned int ARR_MIN = 5;
	static constexpr unsigned int ARR_MAX = 96000;
	static constexpr unsigned int ARR_DEFAULT = 22050;
public:
	linkedQueue(unsigned int = ARR_DEFAULT);
	~linkedQueue();
	bool isEmptyQueue() const;
	void initializeQueue();
	void addItem(const myType& newItem);
	myType front() const;
	myType back() const;
	void deleteItem();
	unsigned int queueCount();
	void printQueue();
};

/*constructor should initialize the queue 
to an empty state (queueFront = NULL 
and queueRear = NULL)*/

template<class myType>
linkedQueue<myType>::linkedQueue(unsigned int newSize)
{
	if (newSize < ARR_MIN || newSize> ARR_MAX)
	{
		size = ARR_DEFAULT;
	}
	else
	{
		size = newSize;
	}
	queueFront = nullptr;
	queueRear = nullptr;
	count = 0;
}

/*will create and initialize a new, empty queue. 
If the passed link array size is not valid, 
set the size to the default (ARR_DEFAULT).*/
template<class myType>
void linkedQueue<myType>::initializeQueue()
{
	queueNode<myType>* temp;
	while (queueFront != nullptr)
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete[] temp->dataSet;
		delete temp;
	}
	queueFront = new queueNode<myType>;
	queueRear = queueFront;
	queueFront->dataSet = new myType[size];
	queueFront->front = 0;
	queueFront->back = 0;
	queueFront->link = nullptr;
}

/*function should return the current 
count of elements in the queue across all links*/
template<class myType>
unsigned int linkedQueue<myType>::queueCount()
{
	return count;
}

/*destructor should delete the queue 
(including releasing all the allocated memory). 
This includes each node and the node array*/
template<class myType>
linkedQueue<myType>::~linkedQueue()
{
	queueNode<myType>* temp;
	while (queueFront != nullptr)
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete[] temp->dataSet;
		delete temp;
	}
}
/*function should determine whether 
the queue is empty, returning
true if the queue is empty and false if not.*/
template<class myType>
bool linkedQueue<myType>::isEmptyQueue() const
{
	if (queueFront == nullptr)
	{
		return true;
	}
	if (queueFront->front == queueFront->back)
	{
		return true;
	}
	return false;
}
/*) function will return the current front of 
the queue without removing it.
*/
template<class myType>
myType linkedQueue<myType>::front() const
{
	if (isEmptyQueue() == true)
	{
		return 0;
	}
	return queueFront->dataSet[queueFront->front];
}

/* function return the current back of the 
queue without removing it.*/
template<class myType>
myType linkedQueue<myType>::back() const
{
	if (queueRear == nullptr)
	{
		return 0;
	}
	return queueRear->dataSet[queueRear->back - 1];
}

/*function will add the passed item to the back of the
queue. The front and back variables should be used 
to track the front and back for th current node. If 
current node array is full, a new node with a 
new node array must be created to hold the new item*/
template<class myType>
void linkedQueue<myType>::addItem(const myType& newItem)
{
	if (queueFront == nullptr)
	{
		initializeQueue();
	}
	if (queueRear->back == size)
	{
		queueRear->link = new queueNode<myType>;
		queueRear = queueRear->link;
		queueRear->link = nullptr;
		queueRear->dataSet = new myType[size];
		queueRear->front = 0;
		queueRear->back = 0;
	}
	queueRear->dataSet[queueRear->back] = newItem;
	queueRear->back++;
	count++;
}
/*function will remove the front item 
from the queue (and return nothing). If the queue 
is empty, nothing should happen and no 
error message provided. If the item removed 
is the last item from the node array, the node 
link must be deleted along with the node array.*/
template<class myType>
void linkedQueue<myType>::deleteItem()
{
	if (isEmptyQueue() == true)
	{
		return;
	}
	queueFront->front++;
	if (queueFront->front == size)
	{
		queueNode<myType>* temp = queueFront;
		queueFront = queueFront->link;
		delete[]temp->dataSet;
		delete temp;
	}
	count--;
}
/*function should print the current elements of queue*/
//for each node starting at queueFront up to and including queueRear
//for each unsigned int starting at 
// current node-> front up to a current node-> back
//cout<<current node->dataSet[current i] << " " 
template<class myType>
void linkedQueue<myType>::printQueue()
{ 
for (queueNode<myType>* currentNode = queueFront; 
	currentNode != nullptr; currentNode = currentNode->link)
	{
		for(unsigned int i = currentNode->front;i<currentNode->back;i++)
		{
			cout << currentNode->dataSet[i] << " ";
		}
	}
}



#endif


