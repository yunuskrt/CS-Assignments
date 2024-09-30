// Yunus Tan Kerestecioglu

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

/*
 Functions:
 
 getValues: reads line, parse the line into 3 part, course code, course name and student id  |||
 stVecToStr: converts vecor<int>(studentsAttendingIDs), into string, used in printing operation |||
 PrintList: prints the linked list, also function of option-3 |||
 courseExists: returns true if course exists in the linked list |||
 swap: swaps two integer values, used in inserting or deleting an element to/from a vector |||
 AddStudentToClass: appends student id to the vector in correct place if id is not already in the vector |||
 AddInOrder: adds new course node to linked list, determine it's place according to course name |||
 strStruct: returns string version of given course node, used in printing the linked list in the last part |||
 toInt: converts string to integer |||
 isID: returns true if given data represents a student ID(starts with a number 0-9) |||
 AddToList: function of option-1 |||
 stPosInVec: returns the position of a student id in a vector, -1 if student id not in the vector |||
 removeItem: removes an element in a given position from a vector |||
 DropFromList: function of option-2 |||
 Finish: function of option-4
 DisplayMenu: displays the menu of options |||
 */

using namespace std;

struct courseNode
{
  string courseCode, courseName;
  vector<int> studentsAttendingIDs;
  courseNode * next;
};

void getValues(const string & line, string & code, string & name, int & student){ 
	// get values from line
    istringstream inpLine(line);
    inpLine >> code >> name >> student;
}

string stVecToStr(const vector<int> & studentIDs){ 
	// will be used for printing studentsattendingIDs
	string st = "";
	for (int i = 0; i < studentIDs.size(); i++){ // iterating over vector
		st += to_string(studentIDs[i]) + " "; // converting elements of vector to string
		
	}
	st = st.substr(0,st.length()-1);
	return st;
}

void PrintList(courseNode * head){ 
	// displays the link list
    courseNode * temp = head->next;
    while ( temp != NULL)
    {
        cout << temp->courseCode << " " << temp->courseName << ": " << stVecToStr(temp->studentsAttendingIDs) << endl;
        temp = temp->next;
    }
}

bool CourseExists(courseNode * node, courseNode * & currentNode, string courseCode){ 
	// returns true if course exists in the link_list
    while ( node != NULL )
    {
        if (node->courseCode == courseCode){
			currentNode = node;
            return true;
        }
        node = node->next;
    }
    return false;
}

void AddInOrder(courseNode * & head, courseNode * node){ 
	// adds a new class to linked list in a sorted way
	
	courseNode * ptr = head;

	if (ptr->next == NULL){ // if there is no node in linked list rather than head
		ptr->next = node;
		node->next = NULL;
	}
	else{
		while (ptr->next != NULL && ptr->next->courseName < node->courseName)
		{
			ptr = ptr->next;
		}
		
		if (ptr->next == NULL){ // last element
			ptr->next = node;
			node->next = NULL;
		}
		else{ // element in middle
			node->next = ptr->next;
			ptr->next = node;
			
		}
	}
	
}

void swap(int & a, int & b){ 
	// will be used for insertion in the "AddStudentToClass" function or deletion from vector
    int temp = a;
    a = b;
    b = temp;
}

int stPosInVec(const vector<int> & stVec, int element){
	// returns index of element in vector if exists, -1 otherwise
	// search operation with binary search
	int min = 0, max = stVec.size()-1, middle;

	while (min <= max){
		middle = (min + max)/2;
		if (stVec[middle] == element){
			return middle;
		}
		else if (stVec[middle] > element){
			max = middle-1;
		}
		else{
			min = middle+1;
		}
	}
	return -1;  // solution not found
}

void AddStudentToClass(bool message, int student, string courseCode, vector<int> & stIDs){
    bool idxcheck = false; // will be true if correct index is found for studentId in the vector
    
	if (stPosInVec(stIDs, student) != -1){ // if student not in class
		if (message){
			cout << "Student with id " << student <<" already is enrolled to " << courseCode << ". No action taken." << endl;
		}
	}
	else{ // if student already in class
		if (message){
			cout << "Student with id " << student <<" is enrolled to " << courseCode << "." << endl;
		}

		if (stIDs.size() == 0){
			stIDs.push_back(student);
		}
	
		else if (stIDs.size() == 1){
        
			if (stIDs[0] > student){
				swap(stIDs[0],student);
				stIDs.push_back(student);
			}

			else{ // student > stIDs[0]
				stIDs.push_back(student);
			}
		}
		else{ // if vector has more than 1 element
			if (student > stIDs[stIDs.size()-1]){ // case that studentId is bigger than all elements in the vector
				stIDs.push_back(student);
			}
			else{
				int i = 0;
				while (i < stIDs.size() && idxcheck == false){

					if (student < stIDs[i]){
						stIDs.push_back(student);
                    
						for (int len = stIDs.size(); len > i+1; len--){
							swap(stIDs[len-1],stIDs[len-2]);
						}

						idxcheck = true; // no need to continue since correct place is found
					}
                
					i++;
				}
			}
		}
	}
}

void DisplayMenu(){
    cout << endl << "Please select one of the choices:" << endl
    << "1. Add to List" << endl << "2. Drop from List" << endl
    << "3. Display List" << endl << "4. Finish Add/Drop and Exit" << endl;
}

int toInt(string id){ 
	// this function converts string to integer
    stringstream intVal(id);
    int num;
    intVal >> num;
    
    return num;
}

bool isID(string data){ 
	// checks if given data represents a student id
    if ( int(data.at(0)) >= 48 && int(data.at(0)) <= 57 ){
        return true;
    }
    return false;
}

void AddToList(bool message, courseNode * head){  // function of option-1
    string line;
    string word;
    
	bool mes = false;
    cout << "Give the student ID and the course names and course codes that he/she wants to add:" << endl;
    
    cin.ignore();
    getline(cin, line);
    
    istringstream input(line);
    
    string code,name;
    int stID;
    
    int x = 0;
	courseNode * node;
    while (input >> word) {
        if (isID(word)) { // if value represents student ID
			stID = toInt(word);
            
			if (CourseExists(head,node,code)){
				AddStudentToClass(message, stID, code, node->studentsAttendingIDs);
			}
			else{
				courseNode * ptr = new courseNode;
				ptr->courseCode = code;
				ptr->courseName = name;
				AddStudentToClass(mes, stID, code, ptr->studentsAttendingIDs);

				AddInOrder(head,ptr);
				cout << code << " does not exist in the list of Courses. It is added up." << endl;
				cout << "Student with id " << stID << " is enrolled to " << code << "." << endl;

			}
            
        }
        
        else{ // if value represents courseCode or courseNAME
            if (x % 2 == 0){ // if value represents courseCode
                code = word;
            }
            else{ // if value represents courseName
                name = word;
            }
            x++;
        }
    }
    
}

void removeItem(vector<int> & stIDs, int pos){
   // removes element in pos from stIDs
    for (int i = pos; i < stIDs.size()-1; i++){
        stIDs[i] = stIDs[i+1]; // elements shifting left until pos
    }
    stIDs.pop_back();
}

void DropFromList(courseNode * head){ // function of option-2
    string line;
    string word;
    
    string courseCode, courseName;
    int stID;
    
    cout << "Give the student ID and the course names and course codes that he/she wants to drop:" << endl;
    
    cin.ignore();
    getline(cin, line);
    
    istringstream input(line);
    
    
    int count = 0;
	courseNode * node;
    while (input >> word){
        if (isID(word)){ // if value represents student id
            stID = toInt(word);
            
            if (CourseExists(head, node, courseCode)){ // case that course exist in the link list
                int position = stPosInVec(node->studentsAttendingIDs, stID);
                
				if (position == -1){ // if student not in class
                    cout << "Student with id " << stID << " is not enrolled to " << courseCode << ", thus he can't drop that course." << endl;
                }
                else{ // remove the student id
                    removeItem(node->studentsAttendingIDs, position);
                    cout << "Student with id " << stID << " has dropped " << courseCode << "." << endl;
                }
            }
            
            else{
                cout << "The " << courseCode << " course is not in the list, thus student with id " << stID << " can't be dropped" << endl;
            }
            
        }
        
        else{
            if (count % 2 == 0){ // if value represents course code
                courseCode = word;
            }
            else{ // if value represents course name
                courseName = word;
            }
            count++;
        }
    }
    
}
string strStruct(courseNode * node){
    string strc = "";
    strc += node->courseCode + " " + node->courseName;
    if (node->studentsAttendingIDs.size() >= 3){
        strc += ": " + stVecToStr(node->studentsAttendingIDs);
    }
    else{
        strc += " " + stVecToStr(node->studentsAttendingIDs) + " -> This course will be closed";
    }
    
    
    return strc;
}

void Finish(courseNode * head){ // function of option-4
    int count = 0;
    courseNode * ptr;
    while(head != NULL){
        ptr = head->next;
        if (count > 0){
            cout << strStruct(head) << endl;
        }
        delete head;
        head = ptr;
        
        count++;
    }
}

int main()
{
	ifstream input;
	string fname,line;
	cout << "Please enter file Name: ";
	cin >> fname;

	string code, name;
	int id;

	courseNode * head;
	head = new courseNode;
	head->next = NULL;

	courseNode * ptr;

	bool message = false;
	input.open(fname.c_str());
	cout << "Successfully opened file " << fname << endl;

	while (getline(input,line)){
		getValues(line,code,name,id);

		if (CourseExists(head,ptr,code)){
			AddStudentToClass(message, id, code, ptr->studentsAttendingIDs);
		}
		else{
			courseNode * node = new courseNode;
			node->courseCode = code;
			node->courseName = name;
			AddStudentToClass(message, id, code, node->studentsAttendingIDs);

			AddInOrder(head,node);
		}
	}
	input.close();

	cout << "The linked list is created." << endl << "The initial list is:" << endl;
	PrintList(head);

	message = true;

	int option;
    do{
        DisplayMenu();
		cin >> option;

		if (option == 1){
			AddToList(message,head);
		}
		else if (option == 2){
			DropFromList(head);
		}
		else if (option == 3){
			cout << "The current list of course and the students attending them:" << endl;
			PrintList(head);
		}
		else{
			cout << "The add/drop period is finished. Printing the final list of courses and students attending them."
			<< endl << "NOTE: Courses with less than 3 students will be closed this semester." << endl;

			Finish(head);
		}
    }while(option != 4);
	
	system("pause");
	return 0;
}
