#include "Graph.hpp"

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = new bool* [V];

    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new bool [V];
    }

    initializeAdjMatrix(adjMatrix);    

}

Graph::~Graph() {
    for (int i = 0; i < V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::initializeAdjMatrix(bool** adjMatrix) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; i < V; i++) {
            adjMatrix[i][j] = false;
        }
    }
}

void Graph::addEdge(int i, int j) {
    if (i != j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    } else {
        adjMatrix[i][j] = true;
    }
}