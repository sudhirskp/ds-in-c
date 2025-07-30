#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

//by sir

struct Edge {
    int v;      // Target node
    int flow;   // Current flow
    int cap;    // Capacity
    int rev;    // Index of reverse edge
};

class Graph {
    int V;
    vector<vector<Edge>> adj;

    bool bfs(int s, int t, vector<int>& parent) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (Edge &e : adj[u]) {
                if (!visited[e.v] && e.flow < e.cap) {
                    parent[e.v] = u;
                    visited[e.v] = true;
                    q.push(e.v);
                    if (e.v == t) return true;
                }
            }
        }
        return false;
    }

    void printAugmentingPath(int t, const vector<int>& parent) {
        vector<int> path;
        for (int v = t; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "Augmenting Path: ";
        for(size_t i = 0; i < path.size(); i++) {
            if (i != 0) cout << " -> ";
            cout << path[i];
        }
        cout << endl;
    }

    void printResidualCapacities(int u, int v) {
        for (Edge &e : adj[u]) {
            if (e.v == v) {
                cout << "Residual Capacity " << u << " -> " << v << ": " 
                     << (e.cap - e.flow) << "/" << e.cap << endl;
                break;
            }
        }
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int cap) {
        Edge forward{v, 0, cap, (int)adj[v].size()};
        Edge backward{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(forward);
        adj[v].push_back(backward);
    }

    int fordFulkersonWithBFS(int s, int t) {
        int max_flow = 0;
        vector<int> parent(V);
        int iteration = 1;

        while (bfs(s, t, parent)) {
            cout << "\n--- Iteration " << iteration++ << " ---" << endl;

            // Print augmenting path
            printAugmentingPath(t, parent);

            // Find bottleneck capacity
            int path_flow = INT_MAX;
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                for (Edge &e : adj[u]) {
                    if (e.v == v) {
                        path_flow = min(path_flow, e.cap - e.flow);
                        printResidualCapacities(u, v);
                        break;
                    }
                }
            }
            cout << "Bottleneck Capacity: " << path_flow << endl;

            // Update flows
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                for (Edge &e : adj[u]) {
                    if (e.v == v) {
                        e.flow += path_flow;
                        adj[e.v][e.rev].flow -= path_flow;
                        break;
                    }
                }
            }

            max_flow += path_flow;
            cout << "Updated Max Flow: " << max_flow << endl;
        }

        cout << "\nFinal Max Flow: " << max_flow << endl;
        return max_flow;
    }
};

int main() {
	
    Graph g(4);
    
	g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(1, 2, 3);

    cout << "Starting Ford-Fulkerson with BFS (Edmonds-Karp)\n";
    g.fordFulkersonWithBFS(0, 3);
    return 0;
}