#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

int main() {

    string fileContent;
    vector<string> lines;
    ifstream inFile; //Input from file testFile.txt

    inFile.open("testFile.txt"); //Open testFile.txt

    if (!inFile.is_open()) { //check for errors
        cout << "Failed open the File." << endl; //error message
        exit(1);
    }
    

    while (getline (inFile, fileContent)) { //push_back every line of file 
        lines.push_back(fileContent); //until there is no more lines
    }
    
    for (string line : lines) { 
        cout << line << endl; //print every line
    }
    
    inFile.close();

}