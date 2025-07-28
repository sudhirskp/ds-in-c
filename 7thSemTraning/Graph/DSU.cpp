#include<iostream>
#include<vector>
using namespace std;

//home work - 

class Disjoint_Set {
    vector<int> leader;

    public : 
    Disjoint_Set(int nodes) {
        leader.resize(nodes);
        for(int i=0;i<nodes;i++) {
            leader.push_back(i);
        }
    }

    int find (int x){
        if(x==leader[x]) {
            return x;
        }
        return find(leader[x]);
    }

    void Union (int u , int v){
        int x = find(u);
        int y = find(v);
        if(x==y){
            cout<<endl<<"Already in same set"<<endl;
        }else{
            leader[y] = x;
        }
    }

    void display() {
        cout << "Leaders: ";
        // for(int i=0;i<size;i++) {
        //     cout << find(i) << " ";
        // }
        // cout << endl;

        for(auto i : leader) {
            cout << i << " ";
        }
    }

};

int main(){

    Disjoint_Set DSU(3);

    DSU.display();

    DSU.Union(1, 2);
   // DSU.Union(1, 2);

   // DSU.display();


}

//disjoint set union or DSU it allow us to keep of track of collection of non overlapping sets