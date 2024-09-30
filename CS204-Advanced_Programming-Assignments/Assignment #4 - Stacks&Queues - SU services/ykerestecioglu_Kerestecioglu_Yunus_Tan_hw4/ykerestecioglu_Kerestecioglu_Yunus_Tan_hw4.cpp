// Yunus Tan Kerestecioglu

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Services.h"

using namespace std;

string Str(string word){
	return word.substr(0,word.length()-1);
}

funcNode * processFile(string filename){	
	ifstream input;
	string line;
	input.open(filename.c_str());
			
	getline(input,line);

	funcNode *node = new funcNode(Str(line));

	while (getline(input,line)){
		commandNode *cmdPtr = new commandNode(Str(line));
		
		commandNode *ptr = node->down;
		
		if (node->down == NULL)
			node->down = cmdPtr;
		
		else{
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = cmdPtr;
		}
	}
	return node;
}

void readInputFiles(Services & cur){
	char inp;
	bool check = true;
	cout << "If you want to open a service <function> defining file," << endl; 
	cout << "then press <Y/y> for 'yes', otherwise press any single key" << endl;
	cin >> inp;

	string filename;

	if (inp == 'Y' || inp == 'y'){
		do{
			ifstream input;
			cout << "Enter the input file name: ";
			cin >> filename;
			
			input.open(filename.c_str());
			
			if (!(input.fail()))
			{
				input.close();
				funcNode * Node = processFile(filename);
				cur.addFuncNode(Node);
			}
			else{
				input.close();
				cout << "File can not be found or does not exist." << endl;
				check = false;
			}
			cout << "Do you want to open another service defining file?" << endl;
			cout << "Press <Y/y> for 'yes', otherwise press anykey" << endl;
			cin >> inp;
		}while((inp == 'Y' || inp == 'y') && check);
	}
}

void addInstructorRequest(Services & cur){
	string funcName,insName;
	int insId;
	
	cout << "Add a service <function> that the instructor wants to use:" << endl;
	cin >> funcName;
	if (cur.funcExists(funcName)){
		cout << "Give instructor's name: ";
		cin >> insName;
		cout << "Give instructor's ID <an int>: ";
		cin >> insId;

		member m(funcName,insName,insId);
		cur.AddInstructorRequest(m);
		cout << "Prof. " << insName << "'s service request of " << funcName << endl << "has been put in the instructor's queue." << endl;
		cout << "Waiting to be served..." << endl;
			
	}
	else{
		cout << "The requested service <function> does not exist." << endl;
		cout << "GOING BACK TO MAIN MENU" << endl;
		
	}
}

void addStudentRequest(Services & cur){
	string funcName,stName;
	int stId;
	
	cout << "Add a service <function> that the student wants to use:" << endl;
	cin >> funcName;
	if (cur.funcExists(funcName)){
		cout << "Give student's name: ";
		cin >> stName;
		cout << "Give student's ID <an int>: ";
		cin >> stId;

		member m(funcName,stName,stId);
		cur.AddStudentRequest(m);
		
		cout <<  stName << "'s service request of " << funcName << " has been put in the student's queue." << endl;
		cout << "Waiting to be served..." << endl;
		
	}
	else{
		cout << "The requested service <function> does not exist." << endl;
		cout << "GOING BACK TO MAIN MENU" << endl;
	}
}

int main()
{

	Services ser;
	
	readInputFiles(ser);
	ser.printList();

	while (true){ 
		cout << endl; 
		cout<<"**********************************************************************"<<endl 
			<<"**************** 0 - EXIT PROGRAM *************"<<endl 
			<<"**************** 1 - ADD AN INSTRUCTOR SERVICE REQUEST *************"<<endl 
			<<"**************** 2 - ADD A STUDENT SERVICE REQUEST *************"<<endl 
			<<"**************** 3 - SERVE (PROCESS) A REQUEST *************"<<endl 
			<<"**********************************************************************"<<endl; 
		cout << endl; 
		int option; 
		cout << "Pick an option from above (int number from 0 to 3): "; 
		cin>>option; 
		switch (option) 
		{ 
			case 0: 
				cout<<"PROGRAM EXITING ... "<<endl; 
				system("pause"); 
				exit(0); 
			case 1:
				addInstructorRequest(ser); 
				break; 
			case 2: 
				addStudentRequest(ser); 
				break; 
			case 3: 
				ser.processARequest(); 
				break; 
			default: 
				cout<<"INVALID OPTION!!! Try again"<<endl;
			
		}//switch 
	}//while (true)
	return 0;
}