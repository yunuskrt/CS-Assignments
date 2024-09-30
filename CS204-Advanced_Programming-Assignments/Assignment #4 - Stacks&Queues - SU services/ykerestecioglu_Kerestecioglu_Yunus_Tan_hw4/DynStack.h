/*
Codes borrowed from week 5 Lecture Materials - DynIntStack.h
However, codes are changed/added/deleted according to homework
*/

#include <string>
using namespace std;

struct StackNode
{
	string value;
	StackNode *next;
};

class DynStack
{
private:
	StackNode *top;
	int size;
public:
	DynStack(void);
	~DynStack(); // destructor
	void push(string);
	void pop(string &);
	bool isEmpty(void);
	void print();
};
