#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex {

    private:
        int vertex;
        int degree;
        int satur;

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
};

#endif /* VERTEX_HPP */