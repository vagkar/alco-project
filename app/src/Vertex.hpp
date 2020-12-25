#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

class Vertex {

    private:
        int vertex;
        int degree;
        int satur;

        std::vector<int> colors;

    public:
        Vertex();
        Vertex(int vertex, int degree);

        bool operator < (const Vertex& v);

        void setVertex(int vertex);
        int getVertex();

        void setDegree(int degree);
        int getDegree();

        void setSatur(int satur);
        int getSatur();

        void addColor(int color);
        int getSizeOfColors();
        std::vector<int> getColors();
};

#endif /* VERTEX_HPP */