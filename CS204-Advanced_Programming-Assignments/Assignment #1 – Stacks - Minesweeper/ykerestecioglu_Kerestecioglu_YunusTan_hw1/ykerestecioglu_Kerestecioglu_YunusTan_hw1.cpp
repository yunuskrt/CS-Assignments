// Yunus Kerestecioglu

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // for setw
#include "randgen.h" // for placing bombs randomly
using namespace std;

/*
    Functions:
 Print() --> prints a given char type matrix
 getInputs() --> gets number of rows, columns and bombs from user
 CountNeighborBombs() --> counts the bombs on the surrounding of a given cell and converts it to char
 PlaceBombs() --> place bombs randomly, to an empty matrix
 PlaceNumbers() --> place corresponding numbers to a matrix fill with only bombs
 FindOutSurrounding() --> displays the count of bombs in surrounding of a given cell
 OpenCell() --> open cell from user's matrix according to given coordinates
 Game() --> controls the flow of the program, prompts menu
 */

// prints given matrix
void Print(const vector<vector<char>> & mat){
    for (int i = 0; i < mat.size(); i++){
        
        for (int j = 0; j < mat[0].size(); j++){
            cout << setw(4) << mat[i][j];
        }
        
        cout << endl;
    }
}

// takes inputs about matrix from user
void getInputs(int & row, int & column, int & bombs){
    
    cout << "Give the dimensions of matrix: "; // getting number of rows and columns from user
    cin >> row >> column;
    
    cout << "How many bombs: "; // getting number of bombs
    cin >> bombs;
    
    while(bombs > (row*column - 1) || bombs < 1){ // input check for number of bombs
        
        if (bombs > (row*column - 1)){ // ask proper question in case of excess
            cout << "The number of bombs can not be greater than the whole number of cells minus one. Please give the number of bombs again: ";
        }
        else{ // lack of bombs
            cout << "The number of bombs could not e less than one. Please give the number of bombs again: ";
        }
        cin >> bombs;
    };
}

char CountNeighborBombs(int r, int c, const vector<vector<char>> & mat){
    
    // right
    int count = 0;
    if (c != mat[0].size()-1){
        if (mat[r][c+1] == 'B')
            count++;
    }
    // left
    if (c != 0){
        if (mat[r][c-1] == 'B')
            count++;

    }
    // top
    if (r != 0){
        if (mat[r-1][c] == 'B')
            count++;
    }
    // bottom
    if (r != mat.size()-1){
        if(mat[r+1][c] == 'B')
            count++;
    }
    // top right
    if (r != 0 && c != mat[0].size()-1){
        if (mat[r-1][c+1] == 'B')
            count++;
    }
    // top left
    if (r != 0 && c != 0){
        if (mat[r-1][c-1] == 'B')
            count++;
    }
    // bottom right
    if (r != mat.size()-1 && c != mat[0].size()-1){
        if (mat[r+1][c+1] == 'B')
            count++;
    }
    // bottom left
    if (r != mat.size()-1 && c != 0){
        if (mat[r+1][c-1] == 'B')
            count++;
    }
    char cnt = '0'+ count; // converting count of bombs to char
    return cnt;
}

/*
 Main Matrix:
 1) Place the bombs to matrix randomly,
 2) Fill the remaining cells with correct numbers
 */

vector<vector<char>> PlaceBombs(int row, int column, int bombs){
    // this function place bombs randomly, and return the matrix
    int bomb_counts = 0;
    
    
    vector<vector<char>> mat(row, vector<char>(column)); // the main matrix
   
    while (bomb_counts < bombs){ // controlling the settlement of bombs
        
        RandGen rand; // a variable from randgen class to replace the bomb randomly
        int r = rand.RandInt(row), c = rand.RandInt(column); // randomly row and column numbers of bomb
        
        if (mat[r][c] != 'B'){
            mat[r][c] = 'B';
            bomb_counts++;
            // increment the count if bomb replaced succesfully to an empty cell
        }

    }
    
    return mat;
}

void PlaceNumbers(vector<vector<char>> & mat){
    // place numbers of neighbor bombs to empty cells
    for (int r = 0; r < mat.size(); r++){
        
        for (int c = 0; c < mat[0].size(); c++){
            if (mat[r][c] != 'B'){
                mat[r][c] = CountNeighborBombs(r,c,mat);
                // count of bombs replaced if current cell is not a bomb
            }
            
        }
        
    }
}

void FindOutSurrounding(int row, int column, vector<vector<char>> & userMatrix, const vector<vector<char>> & mainMatrix){
    // function of option 1 - displays the count of bombs in surrounding of a given cell
    int r,c;
    cout << "Give the coordinates: ";
    cin >> r >> c; // user input of coordinates
    while (r < 0 || r > row-1 || c < 0 || c > column-1){ // input validatioon
        cout << "It is out of range. Please give a valid coordinates: ";
        cin >> r >> c;
    }
    cout << "\n\n" << "Displaying the surrounding of (" << r << "," << c << "):" << "\n\n" << endl;
    
    char neighborBombs = CountNeighborBombs(r,c, mainMatrix); // counting bombs in the neighbor cells
    
    userMatrix[r][c] = neighborBombs; // changing the value of given cell to count of neighbor bombs
    Print(userMatrix);
    
    cout << "Around (" << r << "," << c << ") you have " << neighborBombs << " bomb(s)" << "\n\n" << endl;
    userMatrix[r][c] = 'X'; // changing back to origial value
}

void OpenCell(bool & victory, bool & defeat, int row, int column, int bombs, int & count, vector<vector<char>> & userMatrix, const vector<vector<char>> & mainMatrix){
    // function of the option 2 - open the cell from user's matrix and control the victory or defeat situation
    int r,c;
    cout << "Give the coordinates: ";
    cin >> r >> c; // user input of coordinates
    while (r < 0 || r > row-1 || c < 0 || c > column-1){ // input validatioon
        cout << "It is out of range. Please give a valid coordinates: ";
        cin >> r >> c;
    }
    
    cout << "\n\n";
    cout << "Opening cell (" << r << "," << c << "):" << endl;
    userMatrix[r][c] = mainMatrix[r][c]; // change the value of cell
    Print(userMatrix);

    
    if (mainMatrix[r][c] == 'B'){ // if selected cell is a mine
        cout << "\n\n";
        cout << "Unfortunately, you stepped on a mine" << endl << "Arrangement of mines:" << endl;
        Print(mainMatrix);
        cout << "\n\n" <<">>>>> Game Over! <<<<<" << endl;
        defeat = true;
    }
    else{ // if selected cell is not a mine
        count++; // number of opened cells non-mined cells incremented
        if (count == (row*column)-bombs){ // if all non-mined cells opened
            cout << "Congratulations! All the non-mined cells opened successfully" << endl << "You won!" << endl;
            cout << "\n\n";
            cout << ">>>>> Game Over! <<<<<" << endl;
            victory = true;
        }
    }
}

// Main Game
void Game(int row, int column, int bombs,vector<vector<char>> & userMatrix, const vector<vector<char>> & mainMatrix){
    bool victory = false, defeat = false, exit = false; // boolean variables control if the game is finished
    string option;
    int count = 0;
    while (victory == false && defeat == false && exit == false){ // while game is not finished
        // displaying menu
        cout << "Press:" << endl << "1. If you want to find out the surrounding of a cell" << endl
        << "2. If you want to open the cell" << endl << "3. If you want to exit." << endl;
        
        cin >> option; // user input to the menu
        
        while (option != "1" && option != "2" && option != "3"){ // validation of user input
            cout << "Your input is wrong. Please select one of the options: 1, 2 or 3." << endl;
            cin >> option;
        }
        
        if (option == "1"){
            FindOutSurrounding(row, column, userMatrix, mainMatrix); // displays count of surrounding bombs
        }
        else if (option == "2"){
            OpenCell(victory, defeat, row, column, bombs, count, userMatrix, mainMatrix); // open the cell, control if the game is finished
        }
        else{ // option == "3"
            cout << "Program exiting ..." << endl;
            exit = true;
        }
    }
}
 
int main() {
  
    int row,column,bombs;
    getInputs(row,column,bombs); // updating value of row, column and bombs to inputs of user
    
    /*
     1) Construct the matrix shown to the user
     2) Construct the main matrix
     */
    
    vector<vector<char>> userMatrix(row, vector<char>(column, 'X')); // matrix shown to the user.
    
    vector<vector<char>> mainMatrix = PlaceBombs(row,column,bombs);
    PlaceNumbers(mainMatrix); // main matrix
    
    Game(row,column,bombs,userMatrix,mainMatrix);
   
    return 0;
}
