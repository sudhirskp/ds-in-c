#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DSU {
    vector<int> leader , size;

public:
    DSU(int nodes) {
        leader.resize(nodes);
        for(int i = 0; i < nodes; i++) {
            leader[i] = i;
        }

        size.resize(nodes, 1);
    }


    int find (int x) {
        if(x == leader[x]) {
            return x;
        }
        return leader[x] = find(leader[x]);
    }


    void UnionbySize(int u , int v){
        int x = find (u);
        int y = find (v);
        if(x==y){
            return;
        }

        if(size[x] < size[y]) {
            leader[x] = y;
            size[y] += size[x];
            //swap(x, y);
        } else {
            leader[y] = x;
            size[x] += size[y];
        }
    }
};


int journeyToMoon(int n, vector<vector<int>> astronaut) {
    DSU dsu(n);
    for(auto &pair : astronaut) {
        dsu.UnionbySize(pair[0], pair[1]);
    }

    unordered_map<int, int> componentSize;
    for(int i = 0; i < n; i++) {
        int x = dsu.find(i);
        componentSize[x]++;
    }

    long long totalPairs =  (long long)n * (n - 1) / 2;
    for(auto &entry : componentSize) {
        totalPairs -= (long long)entry.second * (entry.second - 1) / 2;
    }
    return totalPairs;
}

int main() {
    int n, m;
    cout << "Enter number of astronauts and total pairs: ";
    cin >> n >> m;
    vector<vector<int>> astronaut(m, vector<int>(2));
    cout<< "Enter astronaut pairs : ";
    for(int i = 0; i < m; i++) {
        cin >> astronaut[i][0] >> astronaut[i][1];
    }
    cout << "Total pairs of astronauts that can be selected: ";
    cout << journeyToMoon(n, astronaut) << endl;

    return 0;
}

//input:
// 5 3
// 0 1
// 2 3
// 0 4