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
        std::string statisticArray[13] = {
            "Name: car-f-92 |V|: 543 Conflict Density: 0.137732 Min: 0 Med: 64 Max: 381 Mean: 74.788214 CV(%): 75.345322%",
            "Name: car-s-91 |V|: 682 Conflict Density: 0.128198 Min: 0 Med: 77 Max: 472 Mean: 87.431085 CV(%): 70.910035%",
            "Name: ear-f-83 |V|: 190 Conflict Density: 0.265540 Min: 4 Med: 45 Max: 134 Mean: 50.452632 CV(%): 56.113220%",
            "Name: hec-s-92 |V|: 81 Conflict Density: 0.415485 Min: 9 Med: 33 Max: 62 Mean: 33.654321 CV(%): 36.326433%",
            "Name: kfu-s-93 |V|: 461 Conflict Density: 0.055458 Min: 0 Med: 18 Max: 247 Mean: 25.566161 CV(%): 119.986786%",
            "Name: lse-f-91 |V|: 381 Conflict Density: 0.062427 Min: 0 Med: 16 Max: 134 Mean: 23.784777 CV(%): 93.155978%",
            "Name: pur-s-93 |V|: 2419 Conflict Density: 0.029483 Min: 0 Med: 47 Max: 857 Mean: 71.319554 CV(%): 129.479559%",
            "Name: rye-s-93 |V|: 486 Conflict Density: 0.075124 Min: 0 Med: 24 Max: 274 Mean: 36.510288 CV(%): 111.760954%",
            "Name: sta-f-83 |V|: 139 Conflict Density: 0.142953 Min: 7 Med: 16 Max: 61 Mean: 19.870504 CV(%): 67.364770%",
            "Name: tre-s-92 |V|: 261 Conflict Density: 0.180003 Min: 0 Med: 45 Max: 145 Mean: 46.980843 CV(%): 59.618694%",
            "Name: uta-s-92 |V|: 622 Conflict Density: 0.125355 Min: 1 Med: 65 Max: 303 Mean: 77.971061 CV(%): 73.671041%",
            "Name: ute-s-92 |V|: 184 Conflict Density: 0.084475 Min: 2 Med: 13 Max: 58 Mean: 15.543478 CV(%): 69.135061%",
            "Name: yor-f-83 |V|: 181 Conflict Density: 0.287293 Min: 7 Med: 51 Max: 117 Mean: 52.000000 CV(%): 35.226810%"
        };
    public:
        
        Graph();
        Graph(int V, std::string problemName);
        ~Graph();

        void initializeAdjMatrix(std::vector<std::set<int>> examStudents); //initialize adjMatrix with false

        void addEdge(int i, int j, int c); //Store to adjMatrix Edges

        int commonElemets(std::set<int> v1, std::set<int> v2);

        void conflictDensity();

        void degMinMedMax();

        void degMean();

        void coefVar(); // coefficient of variation (CV)

        void printStatisticArray();

        int getVertices(); // return number of Vertices

        int* getAdjMatrix(); // return adjacency matrix

        std::string toString();

};


#endif /* GRAPH_HPP */