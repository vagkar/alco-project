#include "Graph.hpp"

Graph::Graph() {}

Graph::Graph(int V, std::string problemName) {
    this->V = V;
    this -> problemName = problemName;
    adjList = new std::list<Vertex>[V];
}

Graph::~Graph() {
    delete adjList;
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

    for (int i = 0; i < V; i++)
        vertices[i].setDegree(getDegree(i));
    
    int colorOfVertex[V];
    int saturation[V];
    bool availableColors[V];

    int mvd = maximumVertexDegree();

    for (int v = 0; v < V; v++) {
        availableColors[v] = true;
        colorOfVertex[v] = -1;
        vertices[v].setSatur(0);
        vertices[v].setVertexColored(false);
    }

    colorOfVertex[mvd] = 0;
    vertices[mvd].setSatur(-1);
    vertices[mvd].setVertexColored(true); //saturation[mvd] = INT_MIN;
    availableColors[colorOfVertex[mvd]] = false;

    for (auto& i : adjList[mvd])
        vertices[i.getVertex()].setSatur(1);
  
    int maxVertexSatur = 0;
    int vertex;
    std::list<Vertex> queue;

    for (int v = 1; v < V; v++) {
        maxVertexSatur = 0;
        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (vertices[i->getVertex()].isVertexColored()) {
                availableColors[colorOfVertex[vertices[i->getVertex()].getVertex()]] = false;
                continue;
            }
            
            if (vertices[i->getVertex()].getSatur() > maxVertexSatur){
                maxVertexSatur = vertices[i->getVertex()].getSatur();
            }
        }

        std::vector<Vertex> remainingVertices;
        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (vertices[i->getVertex()].getSatur() != maxVertexSatur)
                continue;

            Vertex vObject(i->getVertex(), getDegree(i->getVertex()), vertices[i->getVertex()].getSatur(), vertices[i->getVertex()].isVertexColored());
            remainingVertices.push_back(vObject);
        }

        if (remainingVertices.size() != 1)
            sortVerticesByDegree(remainingVertices);

        for (int i = 0; i < int(remainingVertices.size()); i++)
            queue.push_back(remainingVertices[i]);

        int cr;
        for (cr = 0; cr < V; cr++)
            if (availableColors[cr])
                break;
        
        while (!queue.empty()) {
            Vertex vObject;
            vObject = queue.front();
            
            
            availableColors[cr] = false;
            colorOfVertex[vObject.getVertex()] = cr;
            vertices[vObject.getVertex()].setVertexColored(true);
            queue.pop_front();
        }
        std::cout << std::endl;
        
        for (int i = 0; i < V; i++) {
            if (colorOfVertex[i] != -1)
                availableColors[colorOfVertex[i]] = true;
        }

    }
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