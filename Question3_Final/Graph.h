#include <string>
#include <vector>
#include "Planet.h"
#include <graphviz/gvc.h>
#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

#define edge pair<int, int>
class Graph{
    private:
        vector<pair<double, edge> > G;  // graph
        vector<pair<double, edge> > T;  // mst
        vector<Edge> edgeVector;
        vector<Edge> mst;
        int *parent;//parant is an array 
        int V = 10;  // number of vertices/nodes in graph, fixed to 10
    
    public:
        Graph(int V);
        Graph(vector<Edge> edgeVector);
        void AddWeightedEdge(Edge e);
        int find_set(int i);
        void union_set(int u, int v);
        void kruskal();
        void print();
        void printEdgeVector();
        void printMST();
        bool saveImageGV(std::string file_path);
        void createGraphGV();
        void createMSTGV();
        double mstDistance;
        
};



#endif