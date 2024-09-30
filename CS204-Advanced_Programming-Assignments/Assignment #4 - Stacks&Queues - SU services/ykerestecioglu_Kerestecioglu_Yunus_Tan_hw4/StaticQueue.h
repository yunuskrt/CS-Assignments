/*
Codes borrowed from week 5 Lecture Materials - IntQueue.h
However, codes are changed/added/deleted according to homework
*/

#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include <string>
using namespace std;

struct member {
	string funcName;
	string memberName;
	int memberId;


	//default constructor
	
	member::member()
		{
			funcName = "";
			memberName = "";
			memberId = 0;
		}
	
	//constructor
	member::member(string func, string mem, int id)
		: funcName (func),
		memberName (mem),
		memberId (id)
	{
	}
	
};

class StaticQueue
{
private:
	member *queueArray;
	int queueSize;  //capacity of queue
	int front;
	int rear;
	int numItems;  //# of elements currently in the queue
public:
	StaticQueue(); // default constructor
	~StaticQueue(); // destructor
	StaticQueue(int);  //constructor, parameter is capacity
  	void delArray();
	void enqueue(member);
  	void dequeue(member &);
  	bool isEmpty() const; 
  	bool isFull() const;
  	void clear();  //removes all elements
};
#endif