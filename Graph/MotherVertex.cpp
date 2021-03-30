#include<bits/stdc++.h>
using namespace std;

// If graph is disconnected then mother vertex doesn't exist.

// For undirected connected graph all the vertices are mother vertex.

// Naive approach is to apply dfs to all the vertex and check for mother vertex.
// This algoritm finds all the mother vertixe of directed connected graph in O(E + V) and .
void dfs(int u, vector<int> adjList[], vector<bool> &visit) {

    visit[u] = 1;

    for(int v : adjList[u]) {

        if(!visit[v]) {

            dfs(v, adjList, visit);
        }
    }
}

void findMotherVertex(int n, vector<int> adjList[]) {

    int motherVertex;
    vector<bool> visit(n,0);
    vector<int> adjList2[n];

    for(int i=0; i<n; i++) {

        if(!visit[i]) {

            dfs(i, adjList, visit);
            motherVertex = i;
        }
    }

    for(int i=0; i<n; i++) {

        visit[i] = 0;

        for(int u : adjList[i]) {

            adjList2[u].push_back(i);
        }
    }

    dfs(motherVertex, adjList2, visit);

    for(int i=0; i<n; i++) {

        if(visit[i]) {

            cout<<i<<" ";
        }
    }
}

int main() {

    int n;
    cin>>n;
    vector<int> adjList[n];

    int m; cin>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }

    findMotherVertex(n, adjList);

    return 0;
}