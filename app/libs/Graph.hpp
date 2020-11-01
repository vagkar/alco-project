#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>


class Graph {
    private:
        int V;
        std::list<int> *adj;
    public:
        
        Graph(int V);
        ~Graph();

        void addEdge(int v, int w);

};


#endif /* GRAPH_HPP */