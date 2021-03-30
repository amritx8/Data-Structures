#include <bits/stdc++.h>
using namespace std;

// Spanning Tree only defined for undirected graph.

// Prim's Algorithms
int MSTPrimUsingAdjMatrix(int n, int adjMatrix[100][100]){

    vector<int> Key(n, INT_MAX);
    vector<bool> MSTSet(n, 0);
    int countMSTSet = 0;
    int MSTCost = 0;
    
    Key[0] = 0;

    while(countMSTSet<n){

        int minKey = INT_MAX;
        int index;

        for(int i=0; i<n; i++){
            if(MSTSet[i]==0 and Key[i]<minKey){
                minKey = Key[i];
                index = i;
            }
        }

        MSTCost += minKey;
        MSTSet[index] = 1;
        countMSTSet++;

        for(int i=0; i<n; i++){
            if(MSTSet[i]==0 and adjMatrix[index][i]!=0 and adjMatrix[index][i]<Key[i]){
                Key[i] = adjMatrix[index][i];
            }
        }
    }

    return MSTCost;
}

int MSTPrimUsingAdjList(int n, vector<pair<int,int>> adjList[]){

    vector<bool> MSTSet(n, 0);
    vector<int> Key(n, INT_MAX);
    set<pair<int,int>> KeySet;
    int MSTCost = 0;

    for(int i=1; i<n; i++){
        KeySet.insert({INT_MAX, i});
        Key[i] = INT_MAX;
    }
    KeySet.insert({0, 0});
    Key[0] = 0;

    while(!KeySet.empty()){

        int minKey = KeySet.begin()->first;
        int index = KeySet.begin()->second;
        KeySet.erase(KeySet.begin());

        MSTCost += minKey;
        MSTSet[index] = 1;

        for(auto x:adjList[index]){
            if(MSTSet[x.first]==0 and x.second<Key[x.first]){
                KeySet.erase(KeySet.find({Key[x.first], x.first}));
                KeySet.insert({x.second, x.first});
                Key[x.first] = x.second;
            }
        }
    }

    return MSTCost;
}

// Kruskal's Algorithm

int MSTKruskal(int n, vector<pair<int,int>> adj[]){

    vector<pair<int,pair<int,int>>> edge;
    for(int i=0; i<n; i++){
        for(auto x:adj[i]){
            edge.push_back({x.second, {i, x.first}});
        }
    }
    sort(edge.begin(), edge.end());

    int dsu[n];
    for(int i=0; i<n; i++){
        dsu[i] = i;
    }

    int MSTCost = 0;
    set<pair<int,int>> MSTset;
    for(auto x:edge){
        int u = x.second.first;
        int v = x.second.second;
        int w = x.first;

        int p1 = u;
        while(p1!=dsu[p1]){
            p1 = dsu[p1];
        }

        int p2 = v;
        while(p2!=dsu[p2]){
            p2 = dsu[p2];
        }

        if(p1!=p2){
            MSTCost += w;
            MSTset.insert({u,v});
            dsu[p2] = p1;
        }

        // Path Compression
        int i = u;
        while(i!=dsu[i]){
            int temp = dsu[i];
            dsu[i] = p1;
            i = temp;
        }
        i = v;
        while(i!=dsu[i]){
            int temp = dsu[i];
            dsu[i] = p1;
            i = temp;
        }
    }

    return MSTCost;
}

int main(){
    int n; cin>>n;
    /*int adjMatrix[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adjMatrix[i][j];
        }
    }*/

    vector<pair<int,int>> adjList[n];
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    cout<<MSTPrimUsingAdjList(n, adjList);
    return 0;
}