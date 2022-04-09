#include "Planet.h"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <list>
using namespace std;

//Constructor for planet
Planet::Planet(int p_name, int x, int y, int z, int weight, int profit){

    this->p_name = p_name;
    this->x = x;
    this->y = y;
    this->z = z;
    this->weight = weight;
    this->profit = profit;
}

///////////////////////////////Adjacency Matrix////////////////////////////////
double** buildEmptyMatrix(int m, int n){
     double** a = new double * [n];
    for ( size_t i = 0; i < n; i++ ) a[i] = new double [m];
    return a;
}

void buildAjacencyMatrix(double** adjacencyMatrix, vector<Planet> vectorPlanet){
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(adjacencyMatrix[i][j]!=0){
                //cout<<"distance between "<<i<<" and "<<j<<" = "<<calculateDistance(vectorPlanet[i],vectorPlanet[j])<<endl;
                adjacencyMatrix[i][j] = calculateDistance(vectorPlanet[i],vectorPlanet[j]);
            }
        }
    }
}

//////////////////////////////////////Edges/////////////////////////////
Edge::Edge(int planet1, int planet2, double distance){
    this->distance = distance;
    this->planet1 = planet1;
    this->planet2 = planet2;
}

vector<Edge> buildEdgeVector(double** adjacencyMatrix,vector<Planet> vectorPlanet){
    vector<Edge> edgeVector;
    //Make a copy otherwise the operation below will change the value of the original one
    double** matrixCopy = buildEmptyMatrix(10,10);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            matrixCopy[i][j] = adjacencyMatrix[i][j];
        }
    }

    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(matrixCopy[i][j]!=0){
                Edge tempEdge = Edge(i, j,adjacencyMatrix[i][j]);
                edgeVector.push_back(tempEdge);
                matrixCopy[j][i]=0;
                }
            }   
    }
    return edgeVector; 
}


 
// A utility function to print the adjacency list
// representation of graph
void printAdjacencyList(list<iPair>* adj){

    for(int i=0;i<10;i++){
        cout<<"\nAdjacency list of vertex "<<i<<endl;
        list<iPair> templist = adj[i];
          
        for ( const auto&  temp : templist )
        std::cout << temp.first << "| " << temp.second << "|\n";
            
        
    }
    cout<<endl;
    
}

void buildAdjacencyList(double** adjacencyMatrix,list<iPair>* adj){

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(adjacencyMatrix[i][j]!=0){ 
                iPair tempair = make_pair(j,adjacencyMatrix[i][j]);

                adj[i].push_back(tempair);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////

double calculateDistance(Planet planet1, Planet planet2){
    double distance;
    distance = pow((planet2.x-planet1.x),2) + pow((planet2.y-planet1.y),2) + pow((planet2.z-planet1.z),2);
    distance = sqrt(distance);
    return distance;
}

void mergeEdge(vector<Edge>& v, int s, int m, int e){
    vector<Edge> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {
		if (v[i].distance <= v[j].distance) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
	}
	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}

void mergeSortEdge(vector<Edge>& v, int s, int e){
    if (s < e) {
		int m = (s + e) / 2;
		mergeSortEdge(v, s, m);
		mergeSortEdge(v, m + 1, e);
		mergeEdge(v, s, m, e);
	}
}

void mergePlanet(vector<Planet>& v, int s, int m, int e){
    vector<Planet> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {
		if (v[i].profit >= v[j].profit) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
	}
	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}

void mergeSortPlanet(vector<Planet>& v, int s, int e){
    if (s < e) {
		int m = (s + e) / 2;
		mergeSortPlanet(v, s, m);
		mergeSortPlanet(v, m + 1, e);
		mergePlanet(v, s, m, e);
	}
}


