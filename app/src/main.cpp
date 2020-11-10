#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

#include "Graph.hpp"

using namespace std;

void readData(string fn, int exams) {

    vector<set<int>> examStudents(exams + 1);
    fstream fs(fn);

    if (!fs.is_open()) {
        cerr << "Could not open file: " << fn << endl;
        exit(-1);
    }

    int studentId = 0;
    string line;

    while (getline(fs, line)) {
        if (line.empty())
            continue;
        studentId++;
        istringstream iss(line);
        int examId;
        while (iss >> examId) {
            examStudents[examId].insert(studentId);
            cout << "Student " << studentId << " is enrolled in exam " << examId << endl;
        }
    }
    fs.close();

    cout << "#################################" << endl;

    for (int i = 1; i <= exams; i++) {
        cout << "Exam " << i << " Enrolled students: ";
        for (int studentId : examStudents[i])
            cout << studentId << " ";
        cout << endl;        
    }
    cout << endl;
}

int main() {

    //readData("../datasets/car-f-92.stu", 543);
    readData("../datasets/toy_e5_s6.stu", 5); //debug working with full path file
    
    Graph* graph = new Graph(5);

    cout << "Graph Vertices: " << graph -> getVertices() << endl;

    delete graph;
    
    return 0;
}