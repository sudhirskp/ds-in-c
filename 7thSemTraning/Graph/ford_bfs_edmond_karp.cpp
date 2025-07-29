#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii;
class Graph {

    struct Edge {
        int v;
        int flow;
        int cap; // capacity
        int rev; // index of the reverse edge in the adjacency list
    };

    int V;
    vector<vector<Edge>> adj;

    

    bool bfs(int u , int v ,vector<int>& parent) {
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(u);
        visited[u] = true;
        parent[u] = -1; // Mark the source node's parent as -1
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (Edge& edge : adj[curr]) {
                if (!visited[edge.v] && edge.flow < edge.cap) { // Check if the edge has capacity left
                    visited[edge.v] = true;
                    parent[edge.v] = curr; // Set the parent of the current vertex
                    if (edge.v == v) return true; // If we reached the sink, return true
                    q.push(edge.v);
                }
            }
        }
        return false; // No path found
    }

public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
  
    void addEdge(int u, int v, int Capacity) {
        Edge forwardEdge  {v, 0, Capacity, (int)adj[v].size()};
        Edge reverseEdge  {u, 0, 0, (int)adj[u].size()}; // reverse edge with 0 capacity
        adj[u].push_back(forwardEdge);
        adj[v].push_back(reverseEdge); // add reverse edge
    }


    int fordfulkersonBFS(int src , int sink){
        int maxFlow = 0;
        vector<int> parent(V);
        while (true) {
            fill(parent.begin(), parent.end(), -1);
            if(!bfs(src, sink, parent)) {
                break; // No more augmenting path found
            }

            // Find the minimum capacity in the path from source to sink
            int pathFlow = INT_MAX;
            for (int v = sink; v != src; v = parent[v]) {
                int u = parent[v];
                for (Edge& edge : adj[u]) {
                    if (edge.v == v) {
                        pathFlow = min(pathFlow, edge.cap - edge.flow);
                        break;
                    }
                }
                //cout << "Path flow from " << u << " to " << v << ": " << pathFlow << endl;
            }

            // Update the flow for each edge in the path
            for (int v = sink; v != src; v = parent[v]) {
                int u = parent[v];
                for (Edge& edge : adj[u]) {
                    if (edge.v == v) {
                        edge.flow += pathFlow; // update forward edge flow
                        adj[edge.v][edge.rev].flow -= pathFlow; // update reverse edge flow
                        break;
                    }
                }
            }
            maxFlow += pathFlow;
           // cout << "Current max flow: " << maxFlow << endl; // Debugging output
        }
        
        return maxFlow;
    }

};
int main(){
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(1, 2, 3);
    //g.displayGraph();
    cout << "Maximum flow: " << g.fordfulkersonBFS(0, 3) << endl;

    return 0;

}