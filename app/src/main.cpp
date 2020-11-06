#include <iostream>

#include "Graph.cpp"

using namespace std;

int main() {
    Graph* graph = new Graph(5);
    delete graph;
    return 0;
}