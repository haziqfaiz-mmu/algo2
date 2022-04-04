#include <string>
#include <vector>
#ifndef PLANET_H
#define PLANET_H

using namespace std;

class Planet{
    
    public:
        std::string p_name;
        int x,y,z;
        int weight,profit;
        float value;
        Planet(std::string p_name, int x, int y, int z, int weight, int profit);
        Planet(std::string p_name);    
};

///for adjacency matrix//////////////////////////////////////
double** buildEmptyMatrix(int m, int n);
void buildAjacencyMatrix(double** adjacencyMatrix, vector<Planet> vectorPlanet);
double calculateDistance(Planet planet1, Planet planet2);

//////////////for adjacency list//////////////////////////////

#endif