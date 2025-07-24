#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> pii;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
        vector<vector<pii>> adj(n);
        
        for (const auto& edge : edges) {
            
			int u = edge[0], v = edge[1], w = edge[2];
            
			adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

		/*
		adj = [
		    0: [ (1,3) ],                 // City 0 ? City 1 (distance=3)
		    1: [ (0,3), (2,1), (3,4) ],   // City 1 ? Cities 0,2,3
		    2: [ (1,1), (3,1) ],          // City 2 ? Cities 1,3
		    3: [ (1,4), (2,1) ]           // City 3 ? Cities 1,2
		]
		*/




        int min_neighbors = n;
        int result_city = 0;







		// Dijkstra's Algorithm - Starts Here
        for (int i = 0; i < n; ++i) {




            
            vector<int> dist(n, INT_MAX);		// For each city 'i', initialize all distances as infinite
            
            dist[i] = 0;						// Distance to itself = 0
            
            
			/*            
			//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			priority_queue<
							pair<int, int>,				//... Stores pairs of (distance, city) 
							vector<pair<int, int>>, 	//... Uses a vector to store elements
							greater<pair<int, int>>		//... Orders elements in ascending order (min-heap)
							> pq;
			*/
			priority_queue<
							pii, 
							vector<pii>, 
							greater<pii>
							> pq;
							
            pq.push({0, i});	//For Node i = '0': [(0, 0)]; For Node i = '1': [(0, 1)]; For Node i = '2': [(0, 2)]; For Node i = '3': [(0, 3)]; 




			while (!pq.empty()) {
		        int current_dist = pq.top().first;  	// Current shortest distance
		        int u = pq.top().second;           		// Current city
		        pq.pop();
		
		        if (current_dist > dist[u]) continue;  	// Skip if outdated
		
		        for (const auto& neighbor : adj[u]) {  	// Check all neighboring cities
		            int v = neighbor.first;   			// Neighbor city
		            int w = neighbor.second;  			// Road distance
		            if (dist[v] > dist[u] + w) {  		// If found a shorter path
		                dist[v] = dist[u] + w;    		// Update distance
		                pq.push({dist[v], v});    		// Add to priority queue
		            }
		        }
		    }


            // Count reachable cities within threshold
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[j] <= distanceThreshold) {
                    count++;
                }
            }
			
			/*
			>>> For (City 0):	Initial Distances : [0, 8, 8, 8] and Final Distances : [0, 3, 4, 5]
			
			Check:
			City 1: 3 = 4 ? ? (count=1)
			City 2: 4 = 4 ? ? (count=2)
			City 3: 5 > 4 ? ?
			
			Final count for City 0: 2

			Similarly, 
			>>> For (City 1):	Initial Distances : [8, 0, 8, 8] and Final Distances : [3, 0, 1, 2] >> Count = 3
			>>> For (City 2):	Initial Distances : [8, 8, 0, 8] and Final Distances : [4, 1, 0, 1] >> Count = 3
			>>> For (City 3):	Initial Distances : [8, 8, 8, 0] and Final Distances : [5, 2, 1, 0] >> Count = 2

			*/


            // Update result if current city has fewer neighbors
            if (count <= min_neighbors) {
                min_neighbors = count;
                result_city = i;
            }
            /*
            >>> After All Cities:
			City	Count	Update
			0		2		min_neighbors = 2, result_city = 0
			1		3		No (3 > 2)
			2		3		No (3 > 2)
			3		2		min_neighbors = 2, result_city = 3 (since 3 > 0)
			Final Result: 3 (City 3 has the fewest neighbors within distance 4.)
			*/





                    
		} //ends for loop...
		// Dijkstra's Algorithm	- Ends Here		
		

        return result_city;
    }