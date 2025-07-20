#include<iostream>
#include<vector>
#define DIR false
#define UNDIR true
using namespace std;

//by sir in class

class Graph
{
    int vertices; //no of nodes
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertex=4)
    {
        vertices=vertex;
        adjMatrix.resize(vertices,vector<int>(vertices,0));
    }
    void addEdges(int row, int column, bool direction=true, int weight=1)
    {
    	// direction true  - undirected - bidirectional
        if (row>=vertices || column>=vertices || row<0 || column<0)
        {
            cout<<"\nOut of Bond Error";
            return;
        }

        adjMatrix[row][column]=weight;

        if(direction) //by default un directed
        {
        	adjMatrix[column][row]=weight;
        }


    }

    void display_adjMatrix()
    {
        cout<<"\n Adjancency Matrix - Vector of Vector on Int - 2D Vector--";

        cout<<"\n  ";
        for (int i=0;i<vertices;i++)
            cout<<i<<" ";
        for (int i=0;i<vertices;i++)
        {
            cout<<endl;
            cout<<i<<" ";
            for (int j=0;j<vertices;j++)
                cout<<adjMatrix[i][j]<<" ";


        }
    }

};


int main()
{
    Graph G(8);
    G.display_adjMatrix();
    G.addEdges(0,1);
    G.addEdges(2,0);
    G.addEdges(1,3);
    G.addEdges(1,4);
    G.display_adjMatrix();

    G.addEdges(1,2,DIR);
    G.addEdges(3,2,DIR,55);
    G.display_adjMatrix();
    G.addEdges(13,2,DIR,55);

}
