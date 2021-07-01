#include<bits/stdc++.h>
using namespace std;

// Topological Sort is only defined for DAG.
// TC = O(V + E) and SC = O(V) for all the algorithms.

// Approch 1 - Using DFS. 
void TopologicalSortDFS(int at, vector<int> adjList[], vector<bool> &visited, vector<int> &order){

    visited[at] = 1;

    for(int to : adjList[at]){

        if(!visited[to]){

            TopologicalSortDFS(to, adjList, visited, order);
        }
    }

    order.push_back(at);
}

void TopologicalSortUsingDFS(int n, vector<int> adjList[]){

    vector<bool> visit(n, 0);
    vector<int> order;

    for(int i = 0; i < n; i++) {

        if(!visit[i]){

            TopologicalSortDFS(i, adjList, visit, order);
        }
    }

    for(int i= n - 1; i >= 0; i--) {

        cout << order[i]<<" ";
    }
}

// Approch 2 - Using Khan's Algorithm.
void TopologicalSortUsingKhansAlgorithm(int n, vector<int> adjList[]){

    vector<int> inDegree(n, 0), order;

    for(int i = 0; i < n; i++){

        for(int j : adjList[i]){

            inDegree[j]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < n; i++){

        if(inDegree[i] == 0){
            
            q.push(i);
        }
    }

    while(!q.empty()) {

        int at = q.front();

        q.pop();
        
        order.push_back(at);

        for(int to : adjList[at]) {

            inDegree[to]--;

            if(inDegree[to] == 0) {

                q.push(to);
            }
        }
    }

    if(order.size() != n) {

        cout << "Graph is cyclic";

        return;
    }

    for(int i : order){

        cout << i << " ";
    }
}

// Approch 3 - Using DFS and departure time.
void TopologicalSortDFS2(int at, vector<int> adjList[], vector<bool> &visited, int &time, vector<int> &order){

    visited[at] = 1;

    for(int to : adjList[at]){

        if(!visited[to]){

            TopologicalSortDFS2(to, adjList, visited, time, order);
        }
    }

    order[time++] = at;
}

void TopologicalSortUsingDepartureTime(int n, vector<int> adjList[]){

    vector<int> order(n, 0);
    vector<bool> visit(n, 0);

    int time = 0;

    for(int i = 0; i < n; i++) {

        if(!visit[i]){
            
            TopologicalSortDFS2(i, adjList, visit, time, order);
        }
    }

    for(int i= n - 1; i >= 0; i--) {

        cout<<order[i]<<" ";
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> adjList[n];

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
    }

    return 0;
}