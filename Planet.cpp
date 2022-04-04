#include "Planet.h"
#include <vector>
#include <cmath>
using namespace std;

//Constructor
Planet::Planet(std::string p_name, int x, int y, int z, int weight, int profit){

    this->p_name = p_name;
    this->x = x;
    this->y = y;
    this->z = z;
    this->weight = weight;
    this->profit = profit;
}

Planet::Planet(std::string p_name){
    this->p_name = p_name;
}

//we use map 2
double** buildEmptyMatrix(int m, int n){
     double** a = new double * [n];
    for ( size_t i = 0; i < n; i++ ) a[i] = new double [m];
    return a;
}

void buildAjacencyMatrix(double** adjacencyMatrix, vector<Planet> vectorPlanet){
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(adjacencyMatrix[i][j]!=0){
                adjacencyMatrix[i][j] = calculateDistance(vectorPlanet[i],vectorPlanet[j]);
            }
        }
    }
}

double calculateDistance(Planet planet1, Planet planet2){
    double distance;
    distance = pow((planet2.x-planet1.x),2) + pow((planet2.y-planet1.y),2) + pow((planet2.z-planet1.z),2);
    distance = sqrt(distance);
    return distance;
}