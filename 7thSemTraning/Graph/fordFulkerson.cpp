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

    

    bool dfs(int u , int v , vector<bool>& visited, vector<int>& parent) {
        stack<int> s;
        s.push(u);
        visited[u] = true;
        parent[u] = -1; // Mark the source node's parent as -1
        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            for (Edge& edge : adj[curr]) {
                if (!visited[edge.v] && edge.flow < edge.cap) { // Check if the edge has capacity left
                    visited[edge.v] = true;
                    parent[edge.v] = curr; // Set the parent of the current vertex
                    if (edge.v == v) return true; // If we reached the sink, return true
                    s.push(edge.v);
                }
            }
        }
    }

public:
    Graph(int V) : V(V) {
        //this->V = V;
        adj.resize(V);
    }
  
    void addEdge(int u, int v, int Capacity) {
        Edge forwardEdge  {v, 0, Capacity, (int)adj[v].size()};
        Edge reverseEdge  {u, 0, 0, (int)adj[u].size()}; // reverse edge with 0 capacity
        adj[u].push_back(forwardEdge);
        adj[v].push_back(reverseEdge); // add reverse edge
    }

    int fordFulkerson(int src , int sink){
        int maxFlow = 0;
        vector<int> parent(V);
        vector<bool> visited(V);


        while (true) {
            fill(visited.begin(), visited.end(), false);
            if(!dfs(src, sink, visited, parent)) {
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
               // cout << "Path flow from " << u << " to " << v << ": " << pathFlow << endl;
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
            cout << "Current max flow: " << maxFlow << endl;
            //cout << "Path flow: " << pathFlow << endl;
        }

        return maxFlow;
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (Edge& edge : adj[i]) {
                cout << " -> (" << edge.v << ", " << edge.flow << ")";
            }
            cout << endl;
        }
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
    cout << "Maximum flow: " << g.fordFulkerson(0, 3) << endl;

    return 0;

}