#include<bits/stdc++.h>
using namespace std;


// Only for Unweighted Graph
void ShortestPathUsingBFS(int s, int n, vector<int> adjList[]){

    queue<int> Q;
    vector<bool> visit(n,0);
    vector<int> distance(n,INT_MAX);
    vector<int> parent(n,-1);
    int level = 0;

    Q.push(s);
    distance[s] = level;
    visit[s] = 1;

    while(!Q.empty()){

        int v = Q.front();
        Q.pop();

        for(auto x:adjList[v]){
            if(!visit[x]){
                visit[x] = 1;
                distance[x] = level;
                Q.push(x);
                parent[x] = v;
            }
        }

        level++;
    }

    for(int i=0; i<n; i++){
        cout<<parent[i]<<" "<<i<<" "<<distance[i]<<"\n";
    }
}

// Only for DAG
void ShortestPathUsingTopologicalSort(int s, int n, vector<pair<int,int>> adjLsit[]){

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


    return 0;
}