/*

Platform: LeetCode
Problem: Detect Number of Islands
Representation: Adjacency Matrix
Algorithm: DFS

*/

#include <iostream>
#include <vector>
using namespace std;


//LOGIC BUILDING CODE - SUPPORTER
void dfs(vector<vector<char>>& grid, int i, int j) {
	//BASE CASE
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
        return;
    
	grid[i][j] = '0'; // Mark as visited
    
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);

}


//LOGIC BUILDING CODE
int numIslands(vector<vector<char>>& grid) {
    
	int count = 0;	//NO_OF_ISLANDS
    
	for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
    
	        if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
    
	    }
    }
    
	return count;
}

int main() {
    // Test case 1
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Number of islands (Test 1): " << numIslands(grid1) << endl;

    // Test case 2
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of islands (Test 2): " << numIslands(grid2) << endl;

    // Test case 3 (Edge case: empty grid)
    vector<vector<char>> grid3 = {};
    cout << "Number of islands (Test 3): " << numIslands(grid3) << endl;

    // Test case 4 (Single island)
    vector<vector<char>> grid4 = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };
    cout << "Number of islands (Test 4): " << numIslands(grid4) << endl;

    return 0;
}

/*

Number of islands (Test 1): 1
Number of islands (Test 2): 3
Number of islands (Test 3): 0
Number of islands (Test 4): 1

*/
