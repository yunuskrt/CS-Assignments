// Yunus Tan Kerestecioglu

#include <iostream>
#include "bus.h"
using namespace std;

// ********************
// *   Constructor    *
// ********************
Bus::Bus()
{
	head = NULL;
	size = 0;
}

// *************************
// * Adds bus line to end  *
// *************************
void Bus::AddToEnd(string name, busStop *stop)
{
	busLine * newStop = new busLine(name,stop,NULL);

	if (head == NULL){
		head = newStop;
	}
	else{
		busLine * temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newStop;
	}
}

// ******************************
// * Adds bus line to beginning *
// ******************************
void Bus::AddToBeginning(string name, busStop *stop)
{
	busLine * line = new busLine(name,stop,head);
	head = line;

	size++;
}

// ********************
// * Prints Bus Line  *
// ********************
void Bus::printLine(string name,busStop * stopHead)
{
	busStop * x = stopHead;
	cout << name << ": ";
	while (x->right != NULL){
		cout << x->busStopName << " <-> "; 
		x = x->right;
	}
	cout << x->busStopName;
	cout << endl;
}

// ************************
// *     Prints List      *
// * Function of option-1 *
// ************************
void Bus::printBusLines()
{
	busLine * line = head;
	cout << endl;
	while (line != NULL){
		cout << line->busLineName << ": "; 
		busStop * x = line->busStops;
		while (x->right != NULL){
			cout << x->busStopName << " <-> "; 
			x = x->right;
		}
		cout << x->busStopName;
		cout << endl;
		line = line->next;
	}
}

// ************************
// * Returns True if      *
// * System is Consistent *
// ************************
bool Bus::consistencyCheck() 
{
	busLine* currBL = head; //a global variable
	while(currBL) {
		busStop* currBS = currBL->busStops;
		while(currBS) {
			busStop* rightBS = currBS->right;
			if(rightBS && rightBS->left != currBS) {
				cout << "Inconsistency for " << currBL->busLineName
				<< " " << currBS->busStopName << endl;
				return false;
			}
			currBS = currBS->right;
		}
		currBL = currBL->next;
	}
	return true;
}


// ***********************************
// * Returns true if bus line exists *
// ***********************************
bool Bus::busLineExists(string name)
{
	busLine * temp = head;
	while(temp!=NULL){
		if (temp->busLineName == name)
			return true;

		temp = temp->next;
	}
	return false;
}

// ***********************************
// * Returns true if bus stop exists *
// ***********************************
bool Bus::busStopExists(busStop * stop_head, string stop_name)
{
	busStop * temp = stop_head;
	while(temp!=NULL){
		if (temp->busStopName == stop_name)
			return true;
		temp = temp->right;
	}
	return false;
}

// ***********************************
// *    Get input from user and      *
// *    Adds Bus Line to the List    *
// *    Function of option-2         * 
// ***********************************
void Bus::addBusLine()
{
	busStop * stopHead = NULL;
	busStop * temp = NULL;

	string busLineName, bus_stop_name;
	cout << "Enter the name of the new bus line (0 for exit to main menu):" << endl;
	cin >> busLineName;

	if (busLineName == "0")
		return;

	while(busLineExists(busLineName)){
		cout << "Bus line already exists: enter a new one (0 for exit)" << endl;
		cin >> busLineName;

		if (busLineName == "0")
			return;
	}

	do{
		cout << "Enter the name of the next bus stop (enter 0 to complete)" << endl;
		cin >> bus_stop_name;
		
		if (bus_stop_name != "0" && !(busStopExists(stopHead, bus_stop_name))){
			
			busStop * ptr = new busStop;
			ptr->busStopName = bus_stop_name;
			
			if (stopHead == NULL){
				ptr->left = NULL;
				stopHead = ptr;
				temp = stopHead;
				temp->right = NULL;
			}
			else{
				ptr->left = temp;
				ptr->left->right = ptr;
				temp = ptr;
				temp->right = NULL;
			}
			
		}
		else if (busStopExists(stopHead,bus_stop_name)){
			cout << "Bus stop already exists in the line" << endl;
		}
	}while(bus_stop_name != "0");
	
	if (stopHead!=NULL){
		char ans;
		cout << "The bus information is shown below" << endl;
		printLine(busLineName, stopHead);
		
		cout << "Are you sure? Enter (y/Y) for yes (n/N) for no?" << endl;
		cin >> ans;

		if (ans == 'y' || ans == 'Y'){
			AddToBeginning(busLineName, stopHead);
			printBusLines();
		}
	}
	else{
		cout << "You are not allowed to add an empty bus line" << endl;
	}
}

// ***********************************
// *    Adds Bus Stop to Beginning   *
// *********************************** 
void Bus::AddStopToBeginning(busStop * & stopHead, string name)
{
	busStop * ptr = new busStop;
	ptr->busStopName = name;
	ptr->left = NULL; //NULL
	ptr->right = stopHead;
	
	stopHead->left  = ptr;
	stopHead = ptr;
}

// ****************************************
// * Adds Bus Stop next to a given stop   *
// ****************************************
void Bus::AddStop(busStop * stop_head,string prevStop, string name)
{
	busStop * temp = stop_head;
	bool check = true;
	while(temp != NULL && check){
		if (temp->busStopName == prevStop){
			busStop * ptr = new busStop;
			ptr->right = temp->right;
			ptr->left = temp;
			ptr->busStopName = name;
			temp->right = ptr;
			if (ptr->right != NULL) // if not last element
				ptr->right->left = ptr;
			check = false;
		}
		temp = temp->right;
	}
}

// ***********************************
// *    Get input from user and      *
// *    Adds Bus Stop to the Line    *
// *    Function of option-3         *
// ***********************************
void Bus::addBusStop()
{
	string bus_line;
	bool lineCheck = false, stopCheck = false;
	busLine * temp = head;

	cout << "Enter the name of the bus line to insert a new bus stop (0 for main menu)" << endl;
	cin >> bus_line;
	
	while(temp != NULL && !(lineCheck)){
		if (temp->busLineName == bus_line){
			busStop * stopTemp = temp->busStops;

			cout << "The bus line information is shown below" << endl;
			printLine(bus_line,stopTemp);
			
			string bus_stop_name;
			cout << "Enter the name of the new bus stop" << endl; // user's input (stop)
			cin >> bus_stop_name;

			while (stopTemp != NULL && !(stopCheck)){
				
				if (stopTemp->busStopName == bus_stop_name){ // stop exists in the line
					cout << "Bus stop already exists. Going back to previous menu." << endl;
					stopCheck = true;
				}
				stopTemp = stopTemp->right;
			}

			if (!(stopCheck)){ // if user's stop not exists in the line

				busStop * stopHead = temp->busStops;
				string prevStop;
				cout << "Enter the name of the previous bus stop to put the new one ofter it (0 to put the new one as the first bus stop)"
					<< endl;
				cin >> prevStop;
				if (prevStop == "0"){
					AddStopToBeginning(temp->busStops,bus_stop_name);
				}
				else{
					while (!(busStopExists(stopHead,prevStop)) && prevStop != "0"){
						cout << "Bus stop does not exist. Typo? Enter again (0 for main menu)" << endl;
						cin >> prevStop;
					}
					AddStop(stopHead,prevStop,bus_stop_name);
				}
				printBusLines();
			
			}
			lineCheck = true;
		}
		temp = temp->next;
	}
	if (!(lineCheck))
		cout << "Bus line cannot be found. Going back to previous menu." << endl;
}


// ******************************************
// * Deletes doubly linked list (bus stops) *
// ******************************************
void Bus::DelBusStops(busStop * stopHead)
{
	busStop * ptr = stopHead;
	
	while (ptr != NULL){
		busStop*temp = ptr->right;
		delete ptr;
		ptr = temp;
	}
}

// ***********************************
// *    Get input from user and      *
// *    Deletes a bus line           *
// *    Function of option-4         *
// ***********************************
void Bus::deleteBusLine()
{
	string line_name;
	bool check = true;
	cout << "Enter the name of the bus line to delete" << endl;
	cin >> line_name;

	busLine * temp = head;
	busLine * temp2 = temp->next;
	if (temp->busLineName == line_name){ // case that deleted element is head
		if (temp2 != NULL){ // if there is not single bus line
			head = temp2;
		}
		DelBusStops(temp->busStops);
		delete temp;
		check = false;
	}
	else{
		while(temp2 != NULL && check){
			if (temp2->busLineName == line_name){
				temp->next = temp2->next;
				DelBusStops(temp2->busStops);
				delete temp2;
				check = false;
			}
			temp = temp2;
			temp2 = temp->next;
		}
	}
	
	if (check)
		cout << "Bus line cannot be found. Going back to previous (main) menu." << endl;
	else
		printBusLines();
	
}

// **************************
// *   Deletes a bus stop   *
// **************************
void Bus::DelStop(busStop * stop, busStop * & stopHead)
{
	if (stop->left == NULL){ // if stop is first element of the list
		if (stop->right != NULL){ // case that there is not single element in the list
			stop->right->left = NULL;
			stopHead = stop->right; // making head second element
		}
		delete stop;
	}
	else if (stop->right == NULL){ // if stop is last element of the list
		stop->left->right = NULL;
		delete stop;
	}
	else{ // element is in the middle
		stop->left->right = stop->right;
		stop->right->left = stop->left;
		delete stop;
	}
}

// ***********************************
// *    Get input from user and      *
// *    Deletes a bus stop           *
// *    Function of option-5         *
// ***********************************
void Bus::deleteBusStop()
{
	bool check = true, stopCheck = true;
	busLine * temp = head;
	string line_name, bus_stop_name;
	
	cout << "Enter the name of the bus line to delete a new bus stop (0 for main menu)" << endl;
	cin >> line_name;

	while (temp != NULL && check){ // iterating over bus lines
		
		if (temp->busLineName == line_name){ // if bus_line is found
			busStop * stopTemp = temp->busStops;

			cout << "The bus line information is shown below" << endl;
			printLine(line_name,stopTemp);

			cout << "Enter the name of the bus stop to delete" << endl; // user's input (stop)
			cin >> bus_stop_name;
			
			//busStop * sTemp = temp->busStops;
	
			while(!(busStopExists(stopTemp,bus_stop_name)) && bus_stop_name != "0"){ // get input until stop is found
				cout << "Bus stop cannot be found. Enter the name of the bus stop to delete (0 for main menu)" << endl;
				cin >> bus_stop_name;
			}

			if (bus_stop_name != "0"){ // if user not enter 0
				busStop * sTemp = temp->busStops;
				while (sTemp != NULL && stopCheck){
					if (sTemp->busStopName == bus_stop_name){
						DelStop(sTemp,temp->busStops);
						stopCheck = false; // stop is found

						printBusLines();
					}
					sTemp = sTemp->right;
				}
			}
			check = false;
		}
		temp = temp->next;
	}

	if (check)
		cout << "Bus line cannot be found. Going back to previous (main) menu." << endl;
}

// ******************************************
// * Forms a path if stops in the same line *
// ******************************************
string Bus::FormPath(busLine * lineHead, string stop1, string stop2, int pos1, int pos2)
{
	string path;
	busStop * temp = lineHead->busStops;
	while(temp->busStopName != stop1)
		temp = temp->right; // going right until start stop is reached

	//cout << lineHead->busLineName << ": ";
	path += lineHead->busLineName + ": ";
	if (pos1 < pos2){ // start stop is before end stop
		while (temp->busStopName != stop2){
			path += temp->busStopName + "->";
			//cout << temp->busStopName << "->";
			temp = temp->right;
		}
		//cout << temp->busStopName << endl;
		path += temp->busStopName;
	}
	else{ // start stop is after end stop
		while (temp->busStopName != stop2){
			//cout << temp->busStopName << "->";
			path += temp->busStopName + "->";
			temp = temp->left;
		}
		//cout << temp->busStopName << endl;
		path += temp->busStopName;
	}
	return path;
}

// **********************************************
// * Returns true if two stops in the same line *
// **********************************************
bool Bus::InTheSameLine(busLine * lineHead, string stop1, string stop2, string & path)
{
	bool check1 = false, check2 = false;
	int i = 0;
	int pos1,pos2;
	busStop * temp = lineHead->busStops;

	while(temp != NULL){
		if (temp->busStopName == stop1){
			pos1 = i;
			check1 = true;
		}
		else if (temp->busStopName == stop2){
			pos2 = i;
			check2 = true;
		}
		i++;
		temp = temp->right;
	}

	if (check1 && check2){
		path = FormPath(lineHead,stop1,stop2,pos1,pos2);
		return true;
	}
	return false;
}

// **********************************
// * Analyse table and Returns true *
// * if two stops in the same line  *
// * Used for transition analysis   *
// **********************************
bool Bus::BelongSameLine(string stop1, string stop2, string & path)
{
	busLine * temp = head;
	while(temp!= NULL){
		if (InTheSameLine(temp,stop1,stop2,path))
			return true;
		temp = temp->next;
	}
	return false;
}
// ************************************************
// * Returns stops which occurs in multiple lines *
// ************************************************
vector<string> Bus::TransitionStops()
{
	vector<string> trStops;
	vector<string> stops;
	vector<int> counts;
	busLine * linePtr = head;
	while(linePtr!=NULL){
		
		busStop * stopPtr = linePtr->busStops;
		while(stopPtr!=NULL){
			bool check = true;
			for (int i = 0; i < stops.size() && check;i++){
				if (stops[i] == stopPtr->busStopName){
					check = false;
					counts[i] += 1;
				}
			}
			if (check){
				stops.push_back(stopPtr->busStopName);
				counts.push_back(1);
			}
			stopPtr = stopPtr->right;
		}
		linePtr = linePtr->next;
	}

	for (int i = 0; i < counts.size();i++){
		if (counts[i] > 1){
			trStops.push_back(stops[i]);
		}
	}

	return trStops;
	
}

// *********************************************
// * Returns true if both stops in linked list *
// *********************************************
bool Bus::StopsInTable(string stop1, string stop2)
{
	bool check1 = false, check2 = false;
	busLine * temp = head;
	while (temp != NULL){
		busStop * stopTemp = temp->busStops;
		while(stopTemp != NULL){
			if (stopTemp->busStopName == stop1)
				check1 = true;
			else if (stopTemp->busStopName == stop2)
				check2 = true;
			stopTemp = stopTemp->right;
		}
		temp = temp->next;
	}
	return (check1 && check2);
}

// ******************************************
// *        Get input from user and         *
// * Constructs a road from start to finish *
// *         Function of option-5           *
// ******************************************
void Bus::pathfinder()
{
	string start_stop, end_stop,path;

	cout << "Where are you now?" << endl;
	cin >> start_stop;
	cout << "Where do you want to go?" << endl;
	cin >> end_stop;

	busLine * tempLine = head;

	bool check = false;
	while (tempLine != NULL && !(check)){ // iterating over lines
		
		if (InTheSameLine(tempLine,start_stop,end_stop,path)){
			cout << "You can go there by " << path << endl;
			check = true;
		}
		tempLine = tempLine->next;
	}
	
	if (!check){ // two bus stops not in the same line
		
		if (StopsInTable(start_stop,end_stop)){ // transition
			string p1,p2;
			vector<string> transitions = TransitionStops();
			bool c = true;
			for(int i = 0; i < transitions.size() && c;i++){
				string trStop = transitions[i];
				if ((BelongSameLine(start_stop,trStop,p1)) && (BelongSameLine(trStop,end_stop,p2))){
					path = p1 + "\n" +"                    "+ p2;
					cout << "You can go there by " << path << endl;

					c = false;
				}
			}
			if (c)
				cout <<"Sorry no path from "<< start_stop << " to " << end_stop << " could be found." << endl;
		}
		
		else{ 
			cout << "Bus stop does not exist in the table. Going back to previous menu." << endl;
		}
	}
	
	
}

// ***************************
// *  Deletes entire list,   *
// * used after user enter 0 *
// ***************************
void Bus::DelList()
{
	busLine * ptrLine = head;
	while(ptrLine != NULL){
		busLine * tempLine = ptrLine->next;
		busStop * ptrStop = ptrLine->busStops;
		while (ptrStop != NULL){
			busStop * tempStop = ptrStop->right;
			delete ptrStop;
			ptrStop = tempStop;
		}
		delete ptrLine;
		ptrLine = tempLine;
	}
}
