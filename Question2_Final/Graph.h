#include <string>
#include <vector>
#include <list>
#include<queue>
#include<climits>
#include "Planet.h"
#include <graphviz/gvc.h>
#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

// first one is destination, second one is distance
typedef pair<int, double> iPair;
  
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
    vector<Edge> path;
  
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, double> > *adj;
  
public:
    Graph(int V);  // Constructor
    Graph(vector<Edge> edgeVector, int V);
  
    void addEdge(int u, int v, double w);
    void dijkstra(int s);
    bool saveImageGV(string file_path);
    void createGraphGV();
};





#endif
