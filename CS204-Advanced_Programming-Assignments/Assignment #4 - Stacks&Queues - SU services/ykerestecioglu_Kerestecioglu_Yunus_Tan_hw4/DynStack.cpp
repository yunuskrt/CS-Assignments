/*
Codes borrowed from week 5 Lecture Materials - DynIntStack.cpp
However, codes are changed/added/deleted according to homework
*/

#include <iostream>
#include <vector>
#include "DynStack.h"
using namespace std;

//************************************************
// Constructor to generate an empty stack.       *
//************************************************
DynStack::DynStack()
{
	top = NULL; 
	size = 0;
}

//*************
// Destructor *
//*************
DynStack::~DynStack()
{
	string dummy;
	while(!isEmpty()){
		pop(dummy);
	}
	
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
void DynStack::push(string val)
{
	StackNode *newNode;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = val;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
	size++;
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************
void DynStack::pop(string &val)
{
	StackNode *temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else	// pop value off top of stack
	{
		val = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
	size--;
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
bool DynStack::isEmpty(void)
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}


//**************************************************
// Member funciton print, prints the dynamic stack *
//**************************************************
void DynStack::print()
{
	cout << "PRINTING THE STACK TRACE:" << endl;
	if (isEmpty())
		cout << "The stack is empty" << endl;
	else{
		vector<string> elements;
		string dummy;
		while (!isEmpty()){
			pop(dummy);
			elements.push_back(dummy);
		}
		for(int j=elements.size()-1; j >= 0; j--){
			push(elements[j]);
			cout << elements[j] << endl;
		}
	}
}