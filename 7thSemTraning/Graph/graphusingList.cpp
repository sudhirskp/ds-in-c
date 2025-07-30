#include<iostream>
#include<vector>
using namespace std;

#define undir false;
#define dir true;

class Graph{
    int V;
   // vector<vector<int>>adjList;
    vector<vector<pair<int,int>>>adjList;

    public:
    Graph(int vertices=3) {
        V = vertices;
        adjList.resize(V);
    }

        void displayGraph() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i <V; i++) {
            cout<<endl<<i<<": ";
            for(auto pair_value : adjList[i]) {
                cout<<pair_value.first<<" , " <<pair_value.second<<"  ";
                
            }
            cout << endl;   
        }
    }

    void addEdge(int u, int v, bool isDirected = false , int w = 1) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid edge!" << endl;
            return;
        pair<int int >val = {u,v};
        adjList[u].push_back(val);
        if (!isDirected) {
            val = {v,u};
            adjList[v].push_back(val);
        }
    }
    }
};





int main(){
    Graph G;
    G.displayGraph();

}
