// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<iostream>
#include <list>
#include<queue>
#include<limits>
#include <graphviz/gvc.h>
#include <fstream>
#include "Graph.h"
#include "Planet.h"
using namespace std;
  
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

Graph::Graph(vector<Edge> edgeVector, int V){

    this->V = V;
    adj = new list<iPair> [V];

    for(int i=0;i<edgeVector.size();i++){
        addEdge(edgeVector[i].planet1, edgeVector[i].planet2,edgeVector[i].distance);
    }
}
  
void Graph::addEdge(int u, int v, double w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
  
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that are being preprocessed. This is weird syntax I copied from Stack Overflow.
    
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  
    // Create a vector for distances and initialize all distances as infinite (INT_MAX)
    vector<double> dist(V, INT_MAX);
  
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
  
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, double> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            double weight = (*i).second;
  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                Edge temp(u,v,dist[v]);
                for(int i=0;i<path.size();i++){
                    if(path[i].planet2==v){
                        path.erase(path.begin()+i);
                    }
                }
                path.push_back(temp);
            }
        }
    }
  
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %f\n", i, dist[i]);

    /* printf("Path from Source\n");
    for (int i = 0; i < path.size(); ++i)
        cout<<path[i].planet1<<" "<<path[i].planet2<<" "<<path[i].distance<<endl; */
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
  std::ofstream ofs("Path.gv");
    ofs << "graph G {"<< std::endl;
    for(int i=0;i<path.size();i++){
        double temp = path[i].distance;
        ofs<<path[i].planet1<<" -- "<<path[i].planet2<< " [label=\""<<temp<<"\", fontcolor=red, fontsize=8]"<<endl;
    }
    ofs << "}"<< std::endl;
}
  
