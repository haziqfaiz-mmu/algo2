#include "Graph.h"
#include "Planet.h"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <graphviz/gvc.h>
#include <fstream>
using namespace std;

//Constructor for Graph using the number of vertices
Graph::Graph(int V) {
  parent = new int[V];

  //parent[i] = 0 1 2 3 4 5 6 7 8 9 10
  //if the graph is connected all parents should have the same value at the end
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}

//Constructor for Graph using the number of vertices
Graph::Graph(vector<Edge> edgeVector) {

    parent = new int[edgeVector.size()];
    this->edgeVector = edgeVector;

    //parent[i] = 0 1 2 3 4 5 6 7 8 9 10
    //if the graph is connected all parents should have the same value at the end
    for (int i = 0; i < edgeVector.size(); i++)
      parent[i] = i;

    mstDistance = 0;
}



//add the edge into the graph
void Graph::AddWeightedEdge(Edge e) {
    G.push_back(make_pair(e.distance, edge(e.planet1,e.planet2)));
}

int Graph::find_set(int i) {
    // If i is the parent of itself
    if (i == parent[i])
      return i;
    else
      // Else if i is not the parent of itself
      // Then i is not the representative of his set, hence a child node
      // so we recursively call Find on its parent
      return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end());  // increasing weight
    for (i = 0; i < G.size(); i++) {
      uRep = find_set(G[i].second.first);
      vRep = find_set(G[i].second.second);
      if (uRep != vRep) {
        T.push_back(G[i]);  // add to tree
        union_set(uRep, vRep);
      }
    }
}

void Graph::kruskal2() {
    int i, uRep, vRep;
    sort(edgeVector.begin(), edgeVector.end(), distanceComparator());
    for (i = 0; i < edgeVector.size(); i++) {
      uRep = find_set(edgeVector[i].planet1);
      vRep = find_set(edgeVector[i].planet2);
      if (uRep != vRep) {
        mst.push_back(edgeVector[i]);  // add to tree
        union_set(uRep, vRep);
      }
    }
    for(i=0;i<mst.size();i++){
      mstDistance += mst[i].distance;
    }
}

void Graph::print() {
    cout << "Edge :"
       << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
      cout << T[i].second.first << " - " << T[i].second.second << " : "
         << T[i].first;
      cout << endl;
    }
}

void Graph::printEdgeVector(){
    cout<<"The edges are"<<endl;
   
    for(int i=0;i<edgeVector.size();i++){
        cout<<edgeVector[i].planet1<<" "<<edgeVector[i].planet2<<" "<<edgeVector[i].distance<<endl;
    }
}

void Graph::printMST(){
    cout<<"The Minimum Spanning Trees are"<<endl;
  
    for(int i=0;i<mst.size();i++){
        cout<<mst[i].planet1<<" "<<mst[i].planet2<<" "<<mst[i].distance<<endl;
    }
    cout<<"MST total distance is "<<mstDistance<<endl;
}

bool Graph::saveImageGV(std::string file_path){
    GVC_t *gvc;
    Agraph_t *g;
    FILE *fp;
    gvc = gvContext();
    fp = fopen((file_path+".gv").c_str(), "r");
    g = agread(fp, 0);
    gvLayout(gvc, g, "dot");
    gvRender(gvc, g, "png", fopen((file_path+".png").c_str(), "w"));
    gvFreeLayout(gvc, g);
    agclose(g);
    return (gvFreeContext(gvc));
}

void Graph::createGraphGV(){
  std::ofstream ofs("Graph.gv");
    ofs << "graph G {"<< std::endl;
    for(int i=0;i<edgeVector.size();i++){
        double temp = edgeVector[i].distance;
        ofs<<edgeVector[i].planet1<<" -- "<<edgeVector[i].planet2<< " [label=\""<<temp<<"\", fontcolor=red, fontsize=8]"<<endl;
    }
    ofs << "}"<< std::endl;
}

void Graph::createMSTGV(){
  std::ofstream ofs("Mst.gv");
    ofs << "graph G {"<< std::endl;
    for(int i=0;i<mst.size();i++){
        double temp = mst[i].distance;
        ofs<<mst[i].planet1<<" -- "<<mst[i].planet2<< " [label=\""<<temp<<"\", fontcolor=red, fontsize=8]"<<endl;
    }
    ofs << "}"<< std::endl;
}