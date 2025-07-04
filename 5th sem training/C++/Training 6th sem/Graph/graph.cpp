#include <iostream>
#include <vector>
#include <limits>
#include<stack>
using namespace std;

const int MAX_VERTICES = 100;
vector<vector<int>> adj(MAX_VERTICES);

// Function to add an edge to the graph
void addedge(int u, int v, bool directed) {
   
    if (directed) {
         adj[u].push_back(v);
        adj[v].push_back(u);
    }else{
        adj[u].push_back(v);
    }
}

// BFS traversal
void bfs(int start, int V) {
    vector<bool> visited(V, false);
    vector<int> queue;
    visited[start] = true;
    queue.push_back(start);

    cout << "BFS Traversal: ";
    while (!queue.empty()) {
        int curr = queue.front();
        queue.erase(queue.begin());
        //queue.pop();
        cout << curr << " ";
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
    cout << endl;
}

// DFS traversal
// void dfs(int v, int V, vector<bool>& visited) {
//     visited[v] = true;
//     cout << v << " ";
//     for (int neighbor : adj[v]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, V, visited);
//         }
//     }
// }

void dfs(int start, int V, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        cout << curr << " ";
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}


int main() {
    int V, u, v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    if (V <= 0 || V > MAX_VERTICES) {
        cout << "Invalid number of vertices." << endl;
        return 1;
    }

    bool running = true;
    while (running) {
        cout << "\n1. Insert Data In Graph" << endl;
        cout << "2. Display graph using BFS traversal" << endl;
        cout << "3. Display graph using DFS traversal" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Insert Data In Graph" << endl;
                cout << "Enter the vertices u and v to add an edge (0 to " << V-1 << "): ";
                cin >> u >> v;
                if (u < 0 || u >= V || v < 0 || v >= V) {
                    cout << "Invalid vertices. Please enter values between 0 and " << V-1 << "." << endl;
                } else if (u == v) {
                    cout << "Self-loops are not allowed." << endl;
                } else {
                    addedge(u, v, false);
                    cout << "Edge added between " << u << " and " << v << endl;
                }
                break;

            case 2: {
                int startVertex;
                cout << "Enter the starting vertex for BFS traversal (0 to " << V-1 << "): ";
                cin >> startVertex;
                if (startVertex < 0 || startVertex >= V) {
                    cout << "Invalid starting vertex." << endl;
                } else {
                    bfs(startVertex, V);
                }
                break;
            }

            case 3: {
                int startVertex;
                cout << "Enter the starting vertex for DFS traversal (0 to " << V-1 << "): ";
                cin >> startVertex;
                if (startVertex < 0 || startVertex >= V) {
                    cout << "Invalid starting vertex." << endl;
                } else {
                    vector<bool> visited(V, false);
                    cout << "DFS Traversal: ";
                    dfs(startVertex, V, visited);
                    cout << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting..." << endl;
                running = false;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
