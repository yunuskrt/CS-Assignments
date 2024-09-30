#include <iostream>
#include "StaticQueue.h"
#include "DynQueue.h"
#include "DynStack.h"

using namespace std;

struct commandNode
{
	string name;
	commandNode *next;
	
	commandNode(string cmdName, commandNode *ptr = NULL)
	{
		name = cmdName;
		next = ptr;
	}
};

struct funcNode
{
	string name;
	funcNode *right;
	commandNode *down;

	funcNode(string funcName, funcNode *funcPtr = NULL, commandNode *cmdPtr = NULL)
	{
		name = funcName;
		right = funcPtr;
		down = cmdPtr;
	}
};

class Services
{
private:
	funcNode *head;
	StaticQueue instructorsQueue;
	DynQueue studentsQueue;
	DynStack stack;

public:
	Services();
	~Services(); // destructor
	void addFuncNode(funcNode * node);
	void printList() const;
	bool funcExists(string fncName) const;
	void AddInstructorRequest(member mem);
	void AddStudentRequest(member mem);
	
	void getCommand(commandNode *node, string & cmd, string & var);
	void processARequest(string functionName);
	void processARequest();

};
