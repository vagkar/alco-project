#include "../libs/Graph.hpp"

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = new std::list<int>[V];
}

Graph::~Graph() {
    delete[] adjMatrix;
}

void Graph::addEdge(int v, int w) {
    adjMatrix[v].push_back(w);
    adjMatrix[w].push_back(v);
}