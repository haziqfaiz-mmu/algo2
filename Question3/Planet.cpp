#include "Planet.h"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

//Constructor for Planet
Planet::Planet(std::string p_name, int x, int y, int z, int weight, int profit){

    this->p_name = p_name;
    this->x = x;
    this->y = y;
    this->z = z;
    this->weight = weight;
    this->profit = profit;
}

//Constructor for Edge that accept strings
Edge::Edge(int planet1, int planet2, double distance){
    this->distance = distance;
    this->planet1 = planet1;
    this->planet2 = planet2;
}