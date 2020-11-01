#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>


class Graph {  //undirected graph
    private:
        int V;  //Number of Vertices
        std::list<int> *adjMatrix;
    public:
        
        Graph(int V);
        ~Graph();

        void addEdge(int v, int w);

};


#endif /* GRAPH_HPP */