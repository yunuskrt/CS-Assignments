/*
Codes borrowed from week 5 Lecture Materials - DynIntQueue.h
However, codes are changed/added/deleted according to homework
*/


#ifndef DYNQUEUE_H
#define DYNQUEUE_H
#include "StaticQueue.h"
#include <string>

struct QueueNode
{
	member data;
	QueueNode *next;
	QueueNode(member mem, QueueNode *ptr = NULL)
	{
		data = mem;
		next = ptr;
	}
};

class DynQueue
{
private:
	// These track the front and rear of the queue.
	QueueNode *front;
	QueueNode *rear;	
public:
	// Constructor.
	DynQueue();
	
	// Destructor.
	~DynQueue();

	// Member functions.
	void enqueue(member);
	void dequeue(member &);
	bool isEmpty() const;     
	void clear();
};
#endif