#include <iostream>
#include <sstream>
#include "Services.h"

using namespace std;

// default constructor
Services::Services()
{
	head = NULL;
}

// Destructor
Services::~Services()
{
	member dum;
	string dummy;

	funcNode *funcTemp = head;
	while (funcTemp != NULL){
		funcNode *funcPtr = funcTemp->right;
		
		commandNode *cmdTemp = funcTemp->down;
		while(cmdTemp != NULL){
			commandNode * cmdPtr = cmdTemp->next;
			delete cmdTemp;
			cmdTemp = cmdPtr;
		}
		delete funcTemp;
		funcTemp = funcPtr;
	}
	instructorsQueue.delArray();

	while (!studentsQueue.isEmpty())
		studentsQueue.dequeue(dum);

	while (!stack.isEmpty())
		stack.pop(dummy);
}

//****************************************
// Function add new funcNode to the List *
//****************************************
void Services::addFuncNode(funcNode *node){
	
	if (head == NULL)
		head = node;
	else{
		funcNode *temp = head;
		while (temp->right != NULL)
			temp = temp->right;
		temp->right = node;
	}
}


//*************************
// Displays the main List *
//*************************
void Services::printList() const
{
	cout << "-------------------------------------------------------------------" << endl;
	cout << "PRINTING AVAILABLE SERVICES <FUNCTIONS> TO BE CHOSEN FROM THE USERS" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl << endl;
	
	funcNode *funcTemp = head;
	while (funcTemp != NULL){
		cout << funcTemp->name << ":" << endl;
		commandNode *cmdTemp = funcTemp->down;
		while(cmdTemp->next != NULL){
			cout << cmdTemp->name << ", ";
			cmdTemp = cmdTemp->next;
		}
		cout << cmdTemp->name << "." << endl << endl;
		funcTemp = funcTemp->right;
	}
}


//**********************************************
// Returns true if function exists in the List *
//**********************************************
bool Services::funcExists(string fncName) const
{
	funcNode * temp = head;
	while(temp != NULL){
		if (temp->name == fncName)
			return true;
		temp = temp->right;
	}
	return false;
}

//************************************
// Adds request to instructors queue *
//************************************
void Services::AddInstructorRequest(member mem)
{
	instructorsQueue.enqueue(mem);
}

//*********************************
// Adds request to students queue *
//*********************************
void Services::AddStudentRequest(member mem)
{
	studentsQueue.enqueue(mem);
}

//***********************************************
// Splits commandNode into command and variable *
//***********************************************
void Services::getCommand(commandNode *node, string & cmd, string & var)
{
	string data = node->name;
	istringstream inp(data);
	inp >> cmd >> var;
}


//******************************************************
// Executes the function (commands: define,call,print) *
//******************************************************
void Services::processARequest(string functionName) { 
	//… 
	string command,var,dummy;
	int numItems = 0;
	funcNode *funcTemp = head;
	while(funcTemp->name != functionName)
		funcTemp = funcTemp->right;

	commandNode *cmdTemp = funcTemp->down;

	while (cmdTemp != NULL/* there are commands to process*/) 
	{ 
		getCommand(cmdTemp,command,var);
		//… 
		if( command == "define") 
		{ 
			string data = functionName + ": " + command + " " + var;
			stack.push(data);
			numItems++;
			//process the define command 
		} 
		else if (command == "call") 
		{ 
			// … 
			// the recursion goes here 
			cout << "Calling " << var << " from " << functionName << endl;
			processARequest(var); 
		} 
		else 
			stack.print(); 
		
		cmdTemp = cmdTemp->next;
	} //while 
	//… 
	// delete this function’s data from the top of the stack 
	for (int i = 0; i < numItems; i++)
		stack.pop(dummy);
	cout<<functionName<<" is finished. Clearing the stack from it's data... " <<endl; 
	system("pause"); 
}


//*******************************************
// Process request of instructor or student *
//*******************************************
void Services::processARequest() 
{ 
	member dummy;
	string functionName;
	if (!instructorsQueue.isEmpty()) 
	{ 
		//… 
		//if instructors queue is not empty, process the next request
		cout << "Processing instructors queue..." << endl;
		instructorsQueue.dequeue(dummy);
		functionName = dummy.funcName;
		cout << "Processing prof." << dummy.memberName << "'s request <with ID " << dummy.memberId << "> of service <function>:" << endl;
		cout << functionName << endl;

		processARequest(functionName); 
		cout<<"GOING BACK TO MAIN MENU"<<endl; 
	} 
	else if (!studentsQueue.isEmpty()) 
	{ 
		//… 
		//if instructors queue is empty and student’s not, 
		//then process the next student request 
		cout << "Instructors queue is empty. Proceeding  with students queue..." << endl;
		studentsQueue.dequeue(dummy);
		functionName = dummy.funcName;
		cout << "Processing " << dummy.memberName << "'s request <with ID " << dummy.memberId << "> of service <function>:" << endl;
		cout << functionName << endl;

		processARequest(functionName); 
		cout<<"GOING BACK TO MAIN MENU"<<endl;
	}
	else 
	{ 
		// otherwise… 
		cout<<"Both instructor's and student's queue is empty.\nNo request is processed."<<endl<<"GOING BACK TO MAIN MENU"<<endl; 
	} 
}

