#include<iostream>
#include <vector>
#include <queue>
#define INF 1e8
using namespace std;

vector<int> BellMen(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (const vector<int>& node : edges) {
            int u = node[0], v = node[1], w = node[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (const vector<int>& node : edges) {
        int u = node[0], v = node[1], w = node[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return vector<int>(n, -1);
        }
    }

    return dist;
}

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int src = 0;

    vector<int> distances = BellMen(n, edges, src);
    
    if (distances[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    } else {
        cout << "Distances from source " << src << ": ";
        for (int i = 0; i < n; i++) {
            cout << distances[i] << " ";
        }
        cout << endl;
    }

    return 0;
}