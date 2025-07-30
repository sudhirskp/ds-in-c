#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

//by sir


struct Edge {
    int v, flow, cap, rev;
    int residual() const { return cap - flow; }  // Helper function
};

class Graph {
    int V;
    vector<vector<Edge>> adj;

    bool dfs(int u, int t, vector<bool>& visited, vector<int>& parent, vector<int>& path) {
        stack<int> st;
        st.push(u);
        visited[u] = true;
        parent[u] = -1;

        while (!st.empty()) {
            int current = st.top();
            st.pop();

            for (Edge& e : adj[current]) {
                if (!visited[e.v] && e.residual() > 0) {
                    parent[e.v] = current;
                    if (e.v == t) {
                        int node = t;
                        while (node != -1) {
                            path.push_back(node);
                            node = parent[node];
                        }
                        reverse(path.begin(), path.end());
                        return true;
                    }
                    visited[e.v] = true;
                    st.push(e.v);
                }
            }
        }
        return false;
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int cap) {
        Edge forward{v, 0, cap, (int)adj[v].size()};
        Edge backward{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(forward);
        adj[v].push_back(backward);
    }

    int fordFulkersonWithDFS(int s, int t) {
        int max_flow = 0;
        vector<int> parent(V);
        vector<bool> visited(V);

        while (true) {
            fill(visited.begin(), visited.end(), false);
            vector<int> path;
            if (!dfs(s, t, visited, parent, path)) break;

            // Print augmenting path and residual capacities
            cout << "Augmenting Path: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\nResidual Capacities: ";

            // Calculate and print residuals for each edge in the path
            int path_flow = INT_MAX;
            for (int i = 0; i < path.size() - 1; i++) {
                int u = path[i], v = path[i + 1];
                for (Edge& e : adj[u]) {
                    if (e.v == v) {
                        cout << e.residual() << " ";
                        path_flow = min(path_flow, e.residual());
                        break;
                    }
                }
            }
            cout << "\nBottleneck Capacity: " << path_flow << endl;

            // Update flows
            for (int i = 0; i < path.size() - 1; i++) {
                int u = path[i], v = path[i + 1];
                for (Edge& e : adj[u]) {
                    if (e.v == v) {
                        e.flow += path_flow;
                        adj[e.v][e.rev].flow -= path_flow;
                        break;
                    }
                }
            }

            max_flow += path_flow;
            cout << "Updated Max Flow: " << max_flow << "\n\n";
        }
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

    cout << "Maximum flow: " << endl << g.fordFulkersonWithDFS(0, 3) << endl;
    
	/*
    Graph g(6);
    
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 5, 10);
    g.addEdge(4, 5, 10);
    g.addEdge(4, 3, 6);

    cout << "Maximum flow: " << endl << g.fordFulkersonWithDFS(0, 5) << endl;
	*/

	
	return 0;

}

/*


Maximum flow:
Augmenting Path: 0 ? 2 ? 3
Residual Capacities: 5 7
Bottleneck Capacity: 5
Updated Max Flow: 5

Augmenting Path: 0 ? 1 ? 3
Residual Capacities: 10 8
Bottleneck Capacity: 8
Updated Max Flow: 13

Augmenting Path: 0 ? 1 ? 2 ? 3
Residual Capacities: 2 3 2
Bottleneck Capacity: 2
Updated Max Flow: 15

15

*/



/*

Maximum flow:
Augmenting Path: 0 ? 2 ? 4 ? 5
Residual Capacities: 10 9 10
Bottleneck Capacity: 9
Updated Max Flow: 9

Augmenting Path: 0 ? 1 ? 4 ? 5
Residual Capacities: 10 8 1
Bottleneck Capacity: 1
Updated Max Flow: 10

Augmenting Path: 0 ? 1 ? 3 ? 5
Residual Capacities: 9 4 10
Bottleneck Capacity: 4
Updated Max Flow: 14

Augmenting Path: 0 ? 1 ? 4 ? 3 ? 5					//Reverse edge (4 -> 3) is used here.
Residual Capacities: 5 7 6 6
Bottleneck Capacity: 5
Updated Max Flow: 19

19


*/