#include "Graph.hpp"

Graph::Graph(int V, std::string problemName) {
    this->V = V;
    this -> problemName = problemName;
    adjMatrix = new int[V * V];
}

Graph::~Graph() {
    delete[] adjMatrix;
}

void Graph::initializeAdjMatrix(std::vector<std::set<int>> examStudents) {
    std::cout << "Adjacency Matrix" << std::endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j){
                //graph -> addEdge(i, j, 0); Εφόσον αρχικοποιήσαμε τον πίνακα κατά τη δημιουργία της κλάσης με 0
                continue;
            }
            int c = commonElemets(examStudents[i + 1], examStudents[j + 1]);
            if (c > 0)
                std::cout << i + 1 << " " << j + 1 << " " << c << std::endl;
            addEdge(i, j, c);
        }
    }
}

void Graph::addEdge(int i, int j, int c) {
    adjMatrix[i * V + j] = c;
}

int Graph::commonElemets(std::set<int> s1, std::set<int> s2) {
    int c = 0;
    for (int x : s1) {
        for (int y : s2) {
            if (x == y) {
                c++;
                break;
            }
        }
    }
    return c;
}

void Graph::conflictDensity() {
    int c = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i * V + j] > 0) {
                c++;
            }
            
        }
    }
    this -> confDen = double(c) / double(V * V);
}

void Graph::degMinMedMax() {
    int c;
    this -> max = 0;
    this -> min = (2 ^ 31) - 1; //max του integer

    for (int i = 0; i < V; i++) {
        c = 0;
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i * V + j] > 0) {
                c++;
            }
        }
        this -> sequenceDegree.push_back(c);
        if (c > max)
            this -> max = c;

        if (c < min)
            this -> min = c;
    }

    sort(sequenceDegree.begin(), sequenceDegree.end());
    int indexMed;
    if (sequenceDegree.size() % 2 == 0) {
        indexMed = sequenceDegree.size() / 2;
    } else {
        indexMed = (sequenceDegree.size() + 1) / 2;
    }

    this -> med = sequenceDegree[indexMed];
}

void Graph::degMean() {
    int sum = 0;
    for (int i = 0; i < sequenceDegree.size(); i++) {
        sum += sequenceDegree[i];
    }
    this -> mean = double(sum) / double(sequenceDegree.size());
}

void Graph::coefVar() {
    int sum = 0;
    int a, b;
    for (int i = 0; i < sequenceDegree.size(); i++) {
        a = sequenceDegree[i] - mean;
        b = pow(a, 2);
        sum += b;
    }
    double S2 = double(sum) / double(sequenceDegree.size());
    double S = sqrt(S2);
    this -> CV = (S / mean) * 100.0;
}

int Graph::getVertices() {return V;}

int* Graph::getAdjMatrix() {return adjMatrix;}

std::string Graph::toString() {
    return "Name: " + this -> problemName.substr(12, 8) + " |V|: " + std::to_string(V) + " Conflict Density: "+ std::to_string(confDen) +
                                        " Min: " + std::to_string(min) + " Med: " + std::to_string(med) + " Max: " + std::to_string(max) +
                                        " Mean: " + std::to_string(mean) + " CV%: " + std::to_string(CV);
}