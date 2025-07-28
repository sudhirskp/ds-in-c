//write code of topo sort here of both dfs and Kahn's algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<Graph\graph_adjMatrix_Direction_Weight.cpp>
using namespace std;

 vector<int> indgree(V,0);
        vector<int> q;
        vector<int> ans;

 void bfstraversal(int start) {

        for(int i=0;i<V;i++)
        {
            for (int j=0;j<V;j++)
            {
                if (adjMatrix[i][j]!=0)
                    indgree[j]++;
            }
        }

        for (int i=0;i<V;i++)
        {
            if (indgree[i]==0)
                q.push_back(i);
        }

        while (!q.empty()) {
            int node = queue.front();
            ans.push_back(node);
            q.pop();

            for (int i = 0; i < V; ++i) {
                if (adjMatrix[node][i] != 0) {
                    indgree[i]--;
                    if (indgree[i] == 0) {
                        q.push_back(i);
                    }
                }
            }
        }
        cout << endl;
    } 

int main() {
    cout << "Topological Sort in C++" << endl;
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    bfstraversal(5);
    // while(!ans.empty){
    //     cout << ans.front();
    //     ans.pop();
    // }
    return 0;
}
