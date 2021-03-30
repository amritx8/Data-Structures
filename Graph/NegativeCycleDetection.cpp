#include<bits/stdc++.h>
using namespace std;

const int INF = 10e9;

struct edge {

    int from, to, weigth;

    edge(int u, int v, int w) {

        from = u;
        to = v;
        weigth = w;
    }
};

bool BellmenFord(int n, set<edge> &edgeList){

    vector<int> distance(n, INF);
    
    distance[0] = 0;

    for(int i=1; i<n; i++) {

        for(auto itr : edgeList) {

            int from  = itr.from;
            int to = itr.to;
            int weight = itr.weigth;

            if(distance[from]!=INF and distance[to] < distance[to] + weight) {

                distance[to] = distance[from] + weight;
            }
        }
    }

    for(auto itr : edgeList) {

        int from  = itr.from;
        int to = itr.to;
        int weight = itr.weigth;

        if(distance[from]!=INF and distance[to] < distance[to] + weight) {

            return true;
        }
    }

    return false;
}

bool NegativeCycle(int n, vector<int> adjList) {
    
    set<edge> edgeList;
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