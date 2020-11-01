#include "../libs/Graph.hpp"

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}