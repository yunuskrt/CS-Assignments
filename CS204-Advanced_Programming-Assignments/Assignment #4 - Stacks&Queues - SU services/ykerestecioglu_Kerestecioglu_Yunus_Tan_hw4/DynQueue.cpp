/*
Codes borrowed from week 5 Lecture Materials - DynIntQueue.cpp
However, codes are changed/added/deleted according to homework
*/

#include <iostream>
#include "DynQueue.h"
using namespace std;

//************************************************
// Constructor. Generates an empty queue         *
//************************************************
DynQueue::DynQueue()
{
	front = NULL;
	rear = NULL;   
}

//*************
// Destructor *
//*************
DynQueue::~DynQueue()
{
	member dummy;
	while (!isEmpty()){
		dequeue(dummy);
	}
	
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynQueue::enqueue(member mem)
{       
	if (isEmpty())   //if the queue is empty
	{	//make it the first element
		front = new QueueNode(mem);
		rear = front;
	}
	else  //if the queue is not empty
	{	//add it after rear
		rear->next = new QueueNode(mem);
		rear = rear->next;
	} 
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynQueue::dequeue(member &mem)
{
	QueueNode *temp;
	if (isEmpty())
	{
		cout << "Attempting to dequeue on empty queue, exiting program...\n";
		exit(1);
	}
	else //if the queue is not empty
	{	//return front's value, advance front and delete old front
		mem = front->data;
		temp = front;
		front = front->next;
		delete temp;      
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynQueue::isEmpty() const
{
	if (front == NULL)
		return true;
	else 
		return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
void DynQueue::clear()
{
	member value;   // Dummy variable for dequeue

	while(!isEmpty())
		dequeue(value); //delete all elements
}