#include "Graph.hpp"

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = new int* [V];

    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new int [V];
    }

    initializeAdjMatrix(adjMatrix);    

}

Graph::~Graph() {
    for (int i = 0; i < V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::initializeAdjMatrix(int** adjMatrix) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; i < V; i++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int i, int j) {
    if (i != j) {
        adjMatrix[i][j]++;
        adjMatrix[j][i]++;
    } else {
        adjMatrix[i][j]++;
    }
}

int Graph::getVertices() {
    return V;
}