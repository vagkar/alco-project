#include "Vertex.hpp"

Vertex::Vertex(){}

Vertex::Vertex(int vertex) {
    setVertex(vertex);
    setSatur(0);
}

Vertex::Vertex(int vertex, int degree) {
    setVertex(vertex);
    setDegree(degree);
    setSatur(0);
}

Vertex::Vertex(int vertex, int degree, int satur, bool isColored) {
    setVertex(vertex);
    setDegree(degree);
    setSatur(satur);
    setVertexColored(isColored);
}

// Vertex::Vertex(Vertex& obj) {
//     setVertex(obj.vertex);
//     setDegree(obj.degree);
//     setSatur(obj.satur);
//     setVertexColored(obj.isColored);
// }

bool Vertex::operator < (const Vertex& v) {
    return this->degree < v.degree;
}

void Vertex::setVertex(int vertex) {
    this -> vertex = vertex;
}

int Vertex::getVertex() {
    return this -> vertex;
}

void Vertex::setDegree(int degree) {
    this -> degree = degree;
}

int Vertex::getDegree() {
    return this -> degree;
}

void Vertex::setSatur(int satur) {
    this -> satur = satur;
}

int Vertex::getSatur() {
    return this -> satur;
}

void Vertex::setVertexColored(bool isColored) {
    this -> isColored = isColored;
}

bool Vertex::isVertexColored() {
    return this -> isColored;
}

void Vertex::addColor(int color) {
    this -> colors.push_back(color);
}

int Vertex::getSizeOfColors() {
    return this -> colors.size();
}

std::vector<int> Vertex::getColors() {
    return this -> colors;
}