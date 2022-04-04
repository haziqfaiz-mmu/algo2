#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Planet.h"

using namespace std;

int main(){

    /* Planet planetA = Planet("Planet_A", 120, 120, 120, 0, 0);
    Planet planetB = Planet("Planet_B", 201, 201, 201, 15, 50);
    Planet planetC = Planet("Planet_C", 13, 13, 13, 17, 100);
    Planet planetD = Planet("Planet_D", 130, 130, 130, 5, 120);
    Planet planetE = Planet("Planet_E", 302, 302, 301, 15, 170);
    Planet planetF = Planet("Planet_F", 26, 27, 19, 13, 200);
    Planet planetG = Planet("Planet_G", 267, 274, 195, 14, 170);
    Planet planetH = Planet("Planet_H", 675, 740, 958, 17, 90);
    Planet planetI = Planet("Planet_I", 751, 401, 581, 6, 60);
    Planet planetJ = Planet("Planet_J", 512, 12, 812, 14, 120);
 */
   
    fstream newfile;
    vector<string> line;
    vector<Planet> planetVector;

    newfile.open("A2planets.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        string tp;
        int i=0;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            line.push_back(tp);
            i++;
        }
        newfile.close(); //close the file object.
    }

    for(int i=0;i<line.size();i++){
        istringstream my_stream(line[i]);
        string n;
        vector<string> temp;
        while (my_stream) {
 
            // Streaming until space is
            // encountered
            my_stream >> n;
 
            // If my_stream is not empty
            if (my_stream) {
                cout << "That stream was successful: "
                     << n << "\n";
                     temp.push_back(n);
        }   
 
            // Else print not successful
            else {
                cout << "That stream was NOT successful!"
                     << "\n";
            }
        }
        Planet tempPlanet = Planet(temp[0],stoi(temp[1]),stoi(temp[2]),stoi(temp[3]),stoi(temp[4]),stoi(temp[5]));
        planetVector.push_back(tempPlanet);
    }
    //cout<<planetVector[0].x<<endl;

    double tempMatrix[10][10]={{0,1,1,0,0,0,0,0,0,0},//a
                             {1,0,0,0,0,1,1,0,0,0},//b
                             {1,0,0,1,1,0,0,0,0,0},//c
                             {0,0,1,0,0,0,0,1,1,0},//d
                             {0,0,1,0,0,1,0,1,0,0},//e
                             {0,1,0,0,1,0,0,0,0,1},//f
                             {0,1,0,0,0,0,0,0,1,1},//g
                             {0,0,0,1,1,0,0,0,1,0},//h
                             {0,0,0,1,0,0,1,1,0,1},//i
                             {0,0,0,0,0,1,1,0,1,0}//j
                             };
    
    double** adjacencyMatrix = buildEmptyMatrix(10,10);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            adjacencyMatrix[i][j] = tempMatrix[i][j];
        }
    }

    buildAjacencyMatrix(adjacencyMatrix,planetVector);

    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<adjacencyMatrix[i][j]<<" ";
            }
        cout<<endl;
        
    }
   
}