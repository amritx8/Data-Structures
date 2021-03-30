#include<bits/stdc++.h>
using namespace std;

// Topological Sort is only defined for DAG.

// TC - O(V + E) and SC - O(V) for all the algorithm.


// Using Dfs. 
void TopologicalSortDfs(int u, vector<int> adjList[], vector<bool> &visit, vector<int> &ordering){

    visit[u] = 1;

    for(auto x:adjList[u]){

        if(!visit[x]){

            TopologicalSortDfs(x, adjList, visit, ordering);
        }
    }

    ordering.push_back(u);
}
void TopologicalSortUsingDfs(int n, vector<int> adjList[]){

    vector<bool> visit(n,0);
    vector<int> ordering;

    for(int i=0; i<n; i++){

        if(!visit[i]){

            TopologicalSortDfs(i, adjList, visit, ordering);
        }
    }

    for(int i=n-1; i>=0; i--){

        cout<<ordering[i]<<" ";
    }
}


// Using Khan's Algorithm.
void TopologicalSortUsingKhanAlgorithm(int n, vector<int> adjList[]){

    vector<int> inDegree(n,0), ordering;

    for(int i=0; i<n; i++){

        for(auto x:adjList[i]){

            inDegree[x]++;
        }
    }

    queue<int> Q;

    for(int i=0; i<n; i++){

        if(inDegree[i]==0){
            
            Q.push(i);
        }
    }

    while(!Q.empty()){

        int u = Q.front();
        Q.pop();
        ordering.push_back(u);

        for(auto x:adjList[u]){

            inDegree[x]--;
            if(inDegree[x]==0){

                Q.push(x);
            }
        }
    }

    if(ordering.size()!=n){

        cout<<"There exists a cycle in the graph.";
        return;
    }

    for(auto x:ordering){

        cout<<x<<" ";
    }
}


// Using Dfs and departure time.
void TopologicalSortDfs2(int u, vector<int> adjList[], vector<bool> &visit, int *time, vector<int> &ordering){

    visit[u] = 1;

    for(auto x:adjList[u]){

        if(!visit[x]){

            TopologicalSortDfs2(x, adjList, visit, time, ordering);
        }
    }

    ordering[(*time)++] = u;
}
void TopologicalSortUsingDepartureTimeOfVertex(int n, vector<int> adjList[]){

    vector<int> ordering(n,0);
    vector<bool> visit(n,0);

    int time = 0;

    for(int i=0; i<n; i++){

        if(!visit[i]){
            
            TopologicalSortDfs2(i, adjList, visit, &time, ordering);
        }
    }

    for(int i=n-1; i>=0; i--){

        cout<<ordering[i]<<" ";
    }
}

void AllTopologicalOrdering(int n, vector<int> adjList[]) {

    
}


int main(){
    int n;
    cin>>n;
    vector<int> adjList[n];

    int m; cin>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }

    TopologicalSortUsingDepartureTimeOfVertex(n, adjList);

    return 0;
}