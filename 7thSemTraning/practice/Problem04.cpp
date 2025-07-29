/*
Journey to the Moon
https://www.hackerrank.com/challenges/journey-to-the-moon/problem
*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


/*
DSU Implementation:
> The DSU class handles union and find operations with path compression and union by size optimizations.
> find(u) returns the root of the set containing u while compressing the path.
> unite(u, v) merges the sets containing u and v.
*/

//LOGIC BUILDING CODE - SUPPORTER
class DSU {
    vector<int> parent, size;
public:

    DSU(int n) {

		parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size.resize(n, 1);

		//Team Leader: parent = [0, 1, 2, 3, 4]  // Each astronaut is their own parent
		//Team Member: size   = [1, 1, 1, 1, 1]  // Each team has size 1
        

    }
    
    //2
    int find(int u) {
    
	    if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
    
	    return parent[u];
    }
    
	//1    
    void unite(int u, int v) {
        
		int pu = find(u);			//find parent of u
        int pv = find(v);			//find parent of v
        
		if (pu == pv) return;		//when parents of both u and v are same, return
                
        
        //the smaller team always joins the larger team when merging two teams
		if (size[pu] < size[pv]) {
            swap(pu, pv);
        }
        
        //update...
		parent[pv] = pu;			//update the 'v' with team leader
        size[pu] += size[pv];		//increase 'u' by adding 'v'	


		/*
		Initially: 		
		parent[] = [0,0,2,3,4]
		size[]   = [2,1,1,1,1]   


		For (0,1): 
		parent[] = [0,0,2,3,4]
		size[]   = [2,1,1,1,1] 
		
		For (2,3): 
		parent[] = [0,0,2,2,4]
		size[]   = [2,1,2,1,1] 
	
		For (0,4): 
		parent[] = [0,0,2,2,0]
		size[]   = [3,1,2,1,1] 
	
		 
		*/ 
	}
    
    
    int getSize(int u) {
        return size[find(u)];
    }

};



/*
journeyToMoon Function:
> Uses DSU to group astronauts from the same country.
> Counts the size of each connected component (country).
> Calculates the total possible pairs and subtracts pairs from the same country.
*/

//LOGIC BUILDING CODE
int journeyToMoon(int n, vector<vector<int>> astronaut) {

    DSU dsu(n);		//N = 5

    for (auto& pair : astronaut) {
        dsu.unite(pair[0], pair[1]);	//(0,1) (2,3) (0,4)
    }
    
    
    //counts how many astronauts are in each team (connected component) after all unions are done.
    unordered_map<int, int> componentSizes;
    for (int i = 0; i < n; i++) {
        componentSizes[dsu.find(i)]++;	
    }
    /*
    componentSizes = {
    	0: 3,  // Team 0 has 3 astronauts (0, 1, 4)
    	2: 2   // Team 2 has 2 astronauts (2, 3)
	}
	*/
    
    
    long long totalPairs = (long long)n * (n - 1) / 2;		// = 5 * (4)/2 = 10

    for (auto& [root, size] : componentSizes) {
    	//cout<<size;		//2 3
		/*
		totalPairs = 10 - (2*1)/2 = 10 - 1 = 9
		totalPairs = 9  - (3*2)/2 =  9 - 3 = 6   <- ANSWER
		*/
        totalPairs -= (long long)size * (size - 1) / 2;
    }
    
    
    return totalPairs;

}


//DRIVER CODE
int main() {
    int n, p;
    cin >> n >> p;
    vector<vector<int>> astronaut(p, vector<int>(2));
    for (int i = 0; i < p; i++) cin >> astronaut[i][0] >> astronaut[i][1];
    cout << journeyToMoon(n, astronaut) << endl;
    return 0;
}

/*

Input:

5 3

0 1
2 3
0 4

Output:

6



Input:

4 1

0 2

Output:

5


*/
