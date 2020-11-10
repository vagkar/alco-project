#ifndef GRAPH_HPP
#define GRAPH_HPP


class Graph {  //undirected graph
    private:
        int V;  //Number of Vertices
        int** adjMatrix; //adjacency matrix VxV for Edges
    public:
        
        Graph(int V);
        ~Graph();

        void initializeAdjMatrix(int** adjMatrix); //initialize adjMatrix with false

        void addEdge(int v, int w); //Store to adjMatrix Edges

        int getVertices(); 

};


#endif /* GRAPH_HPP */