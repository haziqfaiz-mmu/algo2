#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <graphviz/gvc.h>
#include "Planet.h"
#include "Graph.h"

using namespace std;

int main(){

    fstream newfile;
    vector<string> line;
    vector<Edge> edgeVector;

    newfile.open("EdgesNumber.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            line.push_back(tp);
        }
        newfile.close(); //close the file object.
    }

    for(int i=1;i<line.size();i++){
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
        Edge tempEdge = Edge(stoi(temp[0]),stoi(temp[1]),stod(temp[2]));
        edgeVector.push_back(tempEdge);
    }
    //sort in increasing order
    sort(edgeVector.begin(), edgeVector.end(), distanceComparator());
    
    //add edges that we read earlier into the graph
    Graph g(edgeVector);
    g.printEdgeVector();
    g.kruskal2();
    g.printMST();
    g.createMSTGV();
    g.createGraphGV();
    g.saveImageGV("/home/haziq/Documents/algo2/Question2_Cmake/Graph");
    g.saveImageGV("/home/haziq/Documents/algo2/Question2_Cmake/Mst");
    //g.saveImageGV();

    ///draw the graph
    
}



