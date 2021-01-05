#include "Graph.hpp"

Graph::Graph() {}

Graph::Graph(int V, std::string problemName) {
    this->V = V;
    this -> problemName = problemName;
    adjList = new std::list<Vertex>[V];
    colors.insert(1);
}

Graph::~Graph() {
    delete[] adjList;
}

void Graph::initializeAdjList(std::vector<std::set<int>> examStudents) {

    std::cout << "Adjacency List" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < V; j++) {
            if (i == j) 
                continue;

            int c = commonElemets(examStudents[i + 1], examStudents[j + 1]);
            if (c > 0) {
                if (j > i)
                    addEdge(i, j);
                std::cout << j + 1 << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Graph::addEdge(int i, int j) {
    Vertex v1(j);
    adjList[i].push_back(v1);
    Vertex v2(i);
    adjList[j].push_back(v2);
}

int Graph::commonElemets(std::set<int> s1, std::set<int> s2) {
    int c = 0;
    for (int x : s1) {
        for (int y : s2) {
            if (x == y) {
                c++;
                break;
            }
        }
    }
    return c;
}

void Graph::conflictDensity() {
    int c = 0;
    for (int i = 0; i < V; i++) {
        for (auto j = adjList[i].begin(); j != adjList[i].end(); ++j) {
            c++;
        }
    }
    this -> confDen = double(c) / double(V * V);
}

void Graph::degMinMedMax() {
    this -> max = INT_MIN;
    this -> min = INT_MAX; //max του integer

    for (int i = 0; i < V; i++) {
        int degree = adjList[i].size();
        Vertex v(i, degree);
        this -> vertices.push_back(v);

        this -> sequenceDegree.push_back(degree);
        if (degree > max)
            this -> max = degree;

        if (degree < min)
            this -> min = degree;
    }

    std::sort(sequenceDegree.begin(), sequenceDegree.end());
    int indexMed;
    if (sequenceDegree.size() % 2 == 0) {
        indexMed = sequenceDegree.size() / 2;
    } else {
        indexMed = (sequenceDegree.size() + 1) / 2;
    }

    this -> med = sequenceDegree[indexMed];
}

void Graph::degMean() {
    int sum = 0;
    for (int i = 0; i < int(sequenceDegree.size()); i++) {
        sum += sequenceDegree[i];
    }
    this -> mean = double(sum) / double(sequenceDegree.size());
}

void Graph::coefVar() {
    double sum = 0.0;
    double a, b;
    for (int i = 0; i < int(sequenceDegree.size()); i++) {
        a = double(sequenceDegree[i]) - mean;
        b = pow(a, 2.0);
        sum += b;
    }
    double S2 = sum / double(sequenceDegree.size());
    double S = sqrt(S2);
    this -> CV = (S / mean) * 100;
}

void Graph::FirstFit()
{
    sortVerticesByDegree(vertices);
    int colorOfVertex[V];

    for (int u = 1; u < V; u++)
        colorOfVertex[vertices[u].getVertex()] = -1; 

    bool availableColors[V];
    for (int cr = 0; cr < V; cr++)
        availableColors[cr] = true;

    colorOfVertex[vertices[0].getVertex()] = 0;

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        for (auto i = adjList[vertices[u].getVertex()].begin(); i != adjList[vertices[u].getVertex()].end(); ++i) {
            if (colorOfVertex[i->getVertex()] != -1)
                availableColors[colorOfVertex[i->getVertex()]] = false;
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (availableColors[cr])
                break;

        colorOfVertex[vertices[u].getVertex()] = cr; // Assign the found color

        // Reset the values back to true for the next iteration
        for (int i = 0; i < V; i++) {
            if (colorOfVertex[i] != -1)
                availableColors[colorOfVertex[i]] = true;
        }
    }

    // print the coloredVertex
    for (int u = 0; u < V; u++)
        std::cout << "Vertex " << u << " --->  Color "
             << colorOfVertex[u] << std::endl;
}

void Graph::DSatur() {

    int colorOfVertex[V];

    int mvd = maximumVertexDegree();

    for (int v = 0; v < V; v++) 
        colorOfVertex[v] = -1;

    colorOfVertex[mvd] = *colors.end();
    vertices[mvd].setSatur(-1);
    vertices[mvd].setVertexColored(true);

    for (auto it = adjList[mvd].begin(); it != adjList[mvd].end(); ++it) {
        if (!(vertices[it->getVertex()].checkNeighborColor(colorOfVertex[it->getVertex()], mvd, adjList[it->getVertex()], colorOfVertex, vertices)))
           vertices[it->getVertex()].raiseSatur();

    }

    while (!graphIsColored()) {
        int maxSaturDegree = 0;
        for (auto it = vertices.begin(); it != vertices.end(); ++it)
            if ((it->getSatur() > maxSaturDegree) && !(it->isVertexColored()))
                maxSaturDegree = it->getSatur();

        int maxSaturVertex;
        int degree = 0;
        for (auto it : vertices) {
            if ((it.getSatur() == maxSaturDegree) && !(it.isVertexColored())) {
                if (it.getDegree() > degree) {
                    degree = it.getDegree();
                    maxSaturVertex = it.getVertex();
                }
            }
        }

        //color vertex
        std::set< int, std::greater<int> > aux;
        std::set< int, std::greater<int> > diff;
        for (auto it = adjList[maxSaturVertex].begin(); it != adjList[maxSaturVertex].end(); ++it)
            if (vertices[it->getVertex()].isVertexColored())
                aux.insert(colorOfVertex[it->getVertex()]);

        std::set_difference(
            colors.begin(), colors.end(),
            aux.begin(), aux.end(),
            std::inserter(diff, diff.end())
        );

        if (diff.size() > 0) {
            colorOfVertex[maxSaturVertex] = *diff.end();
        } else {
            int newColor = *colors.end() + 1;
            colors.insert(newColor);
            colorOfVertex[maxSaturVertex] = *colors.end();
        }

        vertices[maxSaturVertex].setVertexColored(true);

        //update Neighbors
        for (auto it = adjList[maxSaturVertex].begin(); it != adjList[maxSaturVertex].end(); ++it)
            if (!(vertices[it->getVertex()].checkNeighborColor(colorOfVertex[maxSaturVertex], maxSaturVertex, adjList[it->getVertex()], colorOfVertex, vertices)))
                vertices[it->getVertex()].raiseSatur();
    }

    //print colored graph
    for (int u = 0; u < V; u++)
        std::cout << "Vertex " << u << " --->  Color "
             << colorOfVertex[u] - 1 << std::endl;
}

void Graph::sortVerticesByDegree(std::vector<Vertex> &v) {
    std::sort(v.rbegin(), v.rend());
}

int Graph::maximumVertexDegree() {
    int max = getDegree(0);
    int vertex = 0;
  
    for (int i = 1; i < V; i++) {
        if (getDegree(i) > max) {
            max = getDegree(i);
            vertex = i;
        }
    }
    return vertex;
}

bool Graph::graphIsColored() {
    for (auto it : vertices)
        if (!it.isVertexColored())
            return false;
    return true;
}

void Graph::printStatisticArray() {
    for (int i = 0; i < 13; i++) {
        std::cout << statisticArray[i] << std::endl;
    }
}

int Graph::getDegree(int vertex) {
    return adjList[vertex].size();
}

int Graph::getVertices() {return V;}

std::list<Vertex>* Graph::getAdjList() {return adjList;}

std::string Graph::toString() {
    return "Name: " + this -> problemName.substr(12, 8) + " |V|: " + std::to_string(V) + " Conflict Density: "+ std::to_string(confDen) +
                                        " Min: " + std::to_string(min) + " Med: " + std::to_string(med) + " Max: " + std::to_string(max) +
                                        " Mean: " + std::to_string(mean) + " CV(%): " + std::to_string(CV) + "%";
}