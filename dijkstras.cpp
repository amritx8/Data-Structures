
#include <bits/stdc++.h>

#define ll long long
 
using namespace std;

vector<vector<pair<int, int>>> adj;

// Time complexity
/*

    1. Each vertex can be connected to (V-1) vertices, hence the number of adjacent edges to each vertex is V - 1. Let us say E represents V-1 edges connected to each vertex.
    2. Finding each adjacent vertex's distance in min heap is O(log(V)) (update is O(1))
    3. From 1 and 2 above, the time complexity for updating all adjacent vertices of a vertex is E*(logV)
    4. Hence time complexity for all V vertices is V * (E*logV) i.e O(VElogV) -- ( imp: E is the maximum number of edges attached to a single node and VE is the total number of edges).


*/

vector<int> dijkstra(int src, int n){


	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

	// Create a vector for distances and initialize all 
    // distances as infinite 
	vector<int> dis(n+1, INT_MAX);
	

	// Insert source itself in priority queue and initialize 
    // its distance as 0. 
	pq.push({0,src});
	dis[src]=0;


	while(!pq.empty()){
		
		// The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 

		int curVertex= pq.top().second;
		pq.pop();

		for(auto i: adj[curVertex]){
			int child = i.first;
			int weight= i.second;
			if(dis[curVertex]+ weight < dis[child]){
				dis[child]= dis[curVertex] + weight;
				pq.push({dis[child], child});
			}
		}
	}
	return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    
 
}

