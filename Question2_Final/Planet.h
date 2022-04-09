#include <string>
#include <vector>
#ifndef PLANET_H
#define PLANET_H

using namespace std;
class Planet{
    
    public:
        string p_name;
        int x,y,z;
        int weight,profit;
        float value;
        Planet(string p_name, int x, int y, int z, int weight, int profit);
};
////////////////////////////////////////////////////
class Edge{
    public:
    int planet1;
    int planet2;
    double distance;
    Edge(int planet1, int planet2, double distance);
};

struct distanceComparator
{
    inline bool operator() (const Edge& edge1, const Edge& edge2){
        return(edge1.distance<edge2.distance);
    }
};
#endif