#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>
#include <graphviz/gvc.h>
#include "Planet.h"

using namespace std;

int main(){
   
    fstream newfile;
    vector<string> line;
    vector<Planet> planetVector;

    //////////////read//////////////////////////////////
    newfile.open("planetNumber.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            line.push_back(tp);
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
                //cout << "That stream was successful: "<< n << "\n";
                     temp.push_back(n);
        }   
 
            // Else print not successful
            else {
            //cout << "That stream was NOT successful!"<< "\n";
            }
        }
        Planet tempPlanet = Planet(stoi(temp[0]),stoi(temp[1]),stoi(temp[2]),stoi(temp[3]),stoi(temp[4]),stoi(temp[5]));
        //cout<<endl<<stoi(temp[0])<<" "<<stoi(temp[1])<<" "<<stoi(temp[2])<<" "<<stoi(temp[3])<<endl;
        planetVector.push_back(tempPlanet);
    }

    /* for(int i=0;i<planetVector.size();i++){
        cout<<endl<<planetVector[i].p_name<<" "<<planetVector[i].x<<" "<<planetVector[i].y<<" "<<planetVector[i].z<<endl;
        
    } */
    /* for(int i=0;i<planetVector.size();i++){
        cout<<"p_name = "<<planetVector[i].p_name<<endl;
    }
     */
   

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

    //build adjacency matrix
    buildAjacencyMatrix(adjacencyMatrix,planetVector);
    //print adjacency matrix
    cout<<"The adjacency matrix:"<<endl<<endl;
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<setw(8)<<adjacencyMatrix[i][j]<<" |";
            }
        cout<<endl;
        cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    }

    //build and print adjacency list
    list<iPair> adj[10];
    buildAdjacencyList(adjacencyMatrix,adj);
    printAdjacencyList(adj);

   
    ///////////////
    vector<Edge> edgeVector = buildEdgeVector(adjacencyMatrix,planetVector);
    

    mergeSortPlanet(planetVector,0,planetVector.size()-1);
    //sort(planetVector.begin(), planetVector.end(), profitComparator());
    //print planet in ascending order according to profit
    cout<<"Planets in descending order according to profit"<<endl<<endl;
    for(int i=0;i<planetVector.size();i++){
        cout<<planetVector[i].p_name<<" "<<planetVector[i].profit<<endl;
    }
    cout<<endl;

    //create and write to Edges.txt
    std::ofstream ofs("Edges.txt");
    ofs << edgeVector.size() << std::endl;
    for(int i=0;i<edgeVector.size();i++){
        ofs<<edgeVector[i].planet1<<" "<<edgeVector[i].planet2<<" "<<edgeVector[i].distance<<endl;
    }

    mergeSortEdge(edgeVector,0,edgeVector.size()-1);
    //sort(edgeVector.begin(), edgeVector.end(), distanceComparator());
    //print edges in descending order of profit
    cout<<"Edges in ascending order according to distance"<<endl<<endl;
    for(int i=0;i<edgeVector.size();i++){
        cout<<edgeVector[i].planet1<<" "<<edgeVector[i].planet2<<" "<<edgeVector[i].distance<<endl;
    }
    cout<<endl;
}