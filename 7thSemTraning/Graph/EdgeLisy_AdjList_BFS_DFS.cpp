#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

#define DIR true
#define UNDIR false
#define type float
#define default 4


//by sir in class


class Graph{
    int vertices; //no of vertices
    vector<vector<pair<type,type>>> adjList;
    vector<pair<type, type>> EdgeList;

public:
    Graph(int vertex=default)
    {
        vertices=vertex;
        adjList.resize(vertices);
    }
    void displayEdgeList()
    {
        cout<<endl<<"{";
        for (auto pair_value: EdgeList)
                cout<<"("<<pair_value.first<<","<<pair_value.second<<")  ";

        cout<<"}"<<endl;
    }

    void addEdgeList(int one, int two)
    {
        pair<type, type> edge={one, two};
        EdgeList.push_back(edge);
    }

    void displayAdjList()
    {
        cout<<endl<<"AdjList Vector of Vector"<<endl;

        for (int i=0;i<vertices;i++)
        {
            cout<<endl<<i<<":";
            for (auto pair_value: adjList[i])
                cout<<"("<<pair_value.first<<","<<pair_value.second<<")  ";
        }
    }

    void addEdges(int row, int column, bool direction=false, type weight =1) //by default undirected
    {
        if (row>=vertices || row<0 || column>= vertices || column<0)
            cout<<"\nHamse na Ho Payega...Out of Bond";

    pair<type,type> value={column,weight};
    adjList[row].push_back(value);
    cout<<endl<<value.first<<" & "<<value.second<<" is pushed into AdjList of "<<row;


    if (!direction) // by default un directed
    {
        value={row, weight};
        adjList[column].push_back(value);
        cout<<endl<<value.first<<" & "<<value.second<<" is pushed into AdjList of "<<column;
    }
    }

    void bfsTraversal(int src=0)
    {
        queue<int> q;
        unordered_map<int, bool> visited_map;
        cout<<endl;

        q.push(src);
        visited_map[src]=true;

        while(!q.empty())
        {
            int Node=q.front();
            cout<<Node<<" ";
            q.pop();

            for(auto neighbour : adjList[Node])
            {
                int val=neighbour.first;
                if (!visited_map[val])
                {
                    q.push(val);
                    visited_map[val]=true;
                }
            }


        }

        for (int i=0;i<vertices;i++) //this loop is for dis-connected graphs onlyyyyyyyy this will display left over elements
        
            if (!visited_map[i])
                cout<<i<<" ";
        }
    

    void recursionDFS(int src, unordered_map<int, bool> &visited_map)
    {
        cout<<src<<",";
        visited_map[src]=true;

        for (auto neighbour : adjList[src])
        {
            int node=neighbour.first;

            if (!visited_map[node])
                recursionDFS(node,visited_map);
        }

    }
    void dfsTraversal ()
    {
        unordered_map <int, bool> visited_map;
        cout<<endl;

        for (int src=0;src<vertices;src++) //this loop is for dis-connected graphs onlyyyyyyyy this will display left over elements
        
        {
            if (!visited_map[src]) 
            {
                recursionDFS(src, visited_map);
            }
        }
    }
};

int main()
{
    Graph G(7);
    G.displayEdgeList();
    G.addEdgeList(1,2);
    G.displayEdgeList();
    G.addEdges (0,4,DIR);
    G.addEdges (0,3,DIR);
    G.addEdges (0,2,DIR);
   // G.addEdges (3,5,DIR);
    //G.addEdges (2,5,DIR);
    G.addEdges (5,4,DIR);
    G.addEdges (1,6,DIR);
    G.addEdges (4,4,DIR);
    G.addEdges (6,2,DIR);
    G.displayAdjList();

    G.dfsTraversal();
    G.bfsTraversal();



}

