// Yunus Tan Kerestecioglu

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "bus.h"

using namespace std;

void printMainMenu() {
	cout << endl;
	cout <<"I***********************************************I"<<endl
	<<"I 0 - EXIT PROGRAM I"<<endl
	<<"I 1 - PRINT LINES I"<<endl
	<<"I 2 - ADD BUS LINE I"<<endl
	<<"I 3 - ADD BUS STOP I"<<endl
	<<"I 4 - DELETE BUS LINE I"<<endl
	<<"I 5 - DELETE BUS STOP I"<<endl
	<<"I 6 - PATH FINDER I"<<endl
	<<"I***********************************************I"<<endl
	<<">>";
	cout << endl;
}

void processMainMenu(Bus bus) {
	char input;
	do{
		if(!(bus.consistencyCheck())){
			cout << "There are inconsistencies. Exit." << endl;
			return;
		}
		printMainMenu();
		cout << "Please enter your option " << endl;
		cin >> input;

		switch (input) {
			case '0':
				cout << "Thanks for using our program" << endl;
				bus.DelList();
				return;
			
			case '1':
				bus.printBusLines();
				break;
			
			case '2':
				bus.addBusLine();
				break;
							
			case '3':
				bus.addBusStop();
				break;
				
			case '4':
				bus.deleteBusLine();
				break;
				
			case '5':
				bus.deleteBusStop();
				break;
							
			case '6':
				bus.pathfinder();
				break;
				//return;
			default:
				cout << "Invalid option: please enter again" << endl;
		} //switch
	} while(true);
}//processMainMenu

int main(){
	string filename = "busLines.txt", line;

	Bus bus;

	string bus_line,bus_stop;

	ifstream input;
	input.open(filename.c_str());
	
	busStop * s = new busStop;
	if (s->right == NULL)
		cout << "nullmus" << endl;

	while(getline(input,line)){
		
		istringstream inp(line);
		inp >> bus_line;
		bus_line = bus_line.substr(0,bus_line.length()-1);
		
		busStop * head = NULL;
		busStop * temp = new busStop;
		while(inp >> bus_stop){
			busStop * ptr = new busStop;
			ptr->busStopName = bus_stop;
			if (head == NULL){
				ptr->left = NULL;
				head = ptr;
				temp = head;
			}
			else{
				ptr->left = temp;
				ptr->left->right = ptr;
				temp = temp->right;
			}

		}
		temp->right = NULL;	
		
		bus.AddToEnd(bus_line,head);

				
	}
	input.close();
	
	processMainMenu(bus);
	

	return 0;
}