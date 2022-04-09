#include <string>
#include <vector>
#include <list>
#ifndef PLANET_H
#define PLANET_H

using namespace std;

// first one is destination, second one is distance
typedef pair<int, double> iPair;
class Planet{
    
    public:
       
        int p_name,x,y,z;
        int weight,profit;
        float value;
        Planet(int p_name, int x, int y, int z, int weight, int profit);   
};

struct profitComparator
{
    inline bool operator() (const Planet& planet1, const Planet& planet2){
        return(planet1.profit>planet2.profit);
    }
};

///for adjacency matrix//////////////////////////////////////
double** buildEmptyMatrix(int m, int n);
void buildAjacencyMatrix(double** adjacencyMatrix, vector<Planet> vectorPlanet);

//////////////for edges//////////////////////////////
class Edge{
    public:
    int planet1;
    int planet2;
    double distance;
    Edge(int planet1, int planet2, double distance);
};

vector<Edge> buildEdgeVector(double** adjacencyMatrix,vector<Planet> vectorPlanet);

struct distanceComparator
{
    inline bool operator() (const Edge& edge1, const Edge& edge2){
        return(edge1.distance<edge2.distance);
    }
};
////////////////for adjacency matrix/////////////////////////////
void buildAdjacencyList(double** adjacencyMatrix, list<iPair>*);
void printAdjacencyList(list<iPair>* adj);
///////////////////////////////////////////////////////////////
double calculateDistance(Planet planet1, Planet planet2);

void mergeEdge(vector<Edge>& v, int s, int m, int e);
void mergeSortEdge(vector<Edge>& v, int s, int e);
void mergePlanet(vector<Planet>& v, int s, int m, int e);
void mergeSortPlanet(vector<Planet>& v, int s, int e);

#endif