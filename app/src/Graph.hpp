#ifndef GRAPH_HPP
#define GRAPH_HPP


class Graph {  //undirected graph
    private:
        int V;  //Number of Vertices
        bool** adjMatrix; //adjacency matrix VxV for Edges
    public:
        
        Graph(int V);
        ~Graph();

        void initializeAdjMatrix(bool** adjMatrix); //initialize adjMatrix with false

        void addEdge(int v, int w); //Store to adjMatrix Edges

};


#endif /* GRAPH_HPP */