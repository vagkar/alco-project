#ifndef GRAPH_HPP
#define GRAPH_HPP


#include <set>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Graph {  //undirected graph
    private:
        int V;  //Number of Vertices
        int* adjMatrix; //adjacency matrix VxV for Edges
        double confDen;
        int min,med,max;
        double mean;
        double CV;
        std::string problemName;
        std::vector<int> sequenceDegree;
    public:
        
        Graph(int V, std::string problemName);
        ~Graph();

        void initializeAdjMatrix(std::vector<std::set<int>> examStudents); //initialize adjMatrix with false

        void addEdge(int i, int j, int c); //Store to adjMatrix Edges

        int commonElemets(std::set<int> v1, std::set<int> v2);

        void conflictDensity();

        void degMinMedMax();

        void degMean();

        void coefVar(); // coefficient of variation (CV)

        int getVertices(); // return number of Vertices

        int* getAdjMatrix(); // return adjacency matrix

        std::string toString();

};


#endif /* GRAPH_HPP */