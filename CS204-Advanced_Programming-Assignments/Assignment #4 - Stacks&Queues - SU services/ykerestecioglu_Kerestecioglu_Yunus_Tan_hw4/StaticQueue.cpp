/*
Codes borrowed from week 5 Lecture Materials - IntQueue.cpp
However, codes are changed/added/deleted according to homework
*/

#include <iostream>
#include "StaticQueue.h"
using namespace std;

//***************************
// Default Constructor -    *
// creates an empty queue   *
// with 5 elements          *
//***************************
StaticQueue::StaticQueue()
{
	queueArray = new member[5];
	queueSize = 5;
	front = -1;
	rear = -1;
	numItems = 0;

}

//*************
// Destructor *
//*************
StaticQueue::~StaticQueue ()
{
	delArray();	
}


//*****************************************
// Constructor - creates an empty queue   *
// with given number of elements          *
//*****************************************
StaticQueue::StaticQueue(int s)
{
	queueArray = new member[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;

}
void StaticQueue::delArray()
{
	delete[] queueArray;
}
//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void StaticQueue::enqueue(member mem)
{
	if (isFull())
    { 
         cout << "The queue is full. " << mem.memberName << " not enqueued\n";
    }
	else
	{
		// Calculate the new rear position circularly.
		rear = (rear + 1) % queueSize;
		// Insert new item.
		queueArray[rear] = mem;
		// Update item count.
		numItems++;

	}
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void StaticQueue::dequeue(member &mem)
{
	if (isEmpty())
	{
       cout << "Attempting to dequeue on empty queue, exiting program...\n";
       exit(1);
    }
	else
	{
		// Move front.
		front = (front + 1) % queueSize;
		// Retrieve the front item.
		mem = queueArray[front];
		// Update item count.
		numItems--;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool StaticQueue::isEmpty() const
{
	if (numItems > 0)
		return false;
	else
		return true;	
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise.             *
//********************************************
bool StaticQueue::isFull() const
{
	if (numItems < queueSize)
		return false;
	else
		return true;
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0.         *
//*******************************************
void StaticQueue::clear()
{
	front =  - 1;
	rear =  - 1;
	numItems = 0;

}