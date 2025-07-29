#include<iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

void addEdge(int u , int v, int w, vector<vector<pii>>& adj) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
int main(){

}