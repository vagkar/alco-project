#include "Vertex.hpp"

Vertex::Vertex(){}

Vertex::Vertex(int vertex, int degree) {
    setVertex(vertex);
    setDegree(degree);
}

bool Vertex::operator < (const Vertex& v) {
    return getDegree() < v.degree;
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