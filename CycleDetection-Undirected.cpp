#include<bits/stdc++.h>
using namespace std;


// Using DFS.
// TC - O(E + V).
// SC - O(V).
bool DFS(int at, int parent, vector<int> adjList[], vector<bool> &visit) {
    
    visit[at] = 1;

    for(auto to : adjList[at]) {

        if(visit[to]){

            if(to!=parent) {

                return 1;
            }
        }
        else {

            if(DFS(to, at, adjList, visit)) {

                return 1;
            }
        }
    }

    return 0;
}
void CycleDetectionUsingDFS(int n, vector<int> adjList[]) {

    vector<bool> visit(n,0);
    bool isCycle = 0;

    for(int i=0; i<n; i++) {

        if(!visit[i]) {

            isCycle = isCycle|DFS(i, -1, adjList, visit);
        }
    }

    cout<<isCycle;
}


// Using Union-Find.
// TC - O(E*log(V)).
// SC - O(E + V).
int findRoot(int i, int root[]) {

    if(i!=root[i]){

        root[i] = findRoot(root[i], root);
    }

    return root[i];
}
void UnionRoots(int i, int j, int root[], int size[]) {

    if(size[j]>size[i]) {

        swap(i, j);
    }
    root[j] = i;
    size[i] = size[i] + size[j];
}
void CycleDetectionUsingUnionFind(int n, vector<int> adjList[]) {

    list<pair<int,int>> edgeList;
    int root[n], size[n];
    bool isCycle = 0;

    for(int i=0; i<n; i++) {

        root[i] = i;
        size[i] = 1;

        for(int j : adjList[i]) {

            if(j>=i) {

                edgeList.push_back({i, j});
            }
        }
    }

    while(!edgeList.empty()) {

        pair<int,int> edge = edgeList.front();

        int root1 = findRoot(edge.first, root);
        int root2 = findRoot(edge.second, root);

        if(root1==root2) {

            isCycle = 1;
        }
        else {

            UnionRoots(root1, root2, root, size);
        }

        edgeList.pop_front();
    }

    cout<<isCycle;
}


int main(){

    int n;
    cin>>n;
    vector<int> adjList[n];

    int m; cin>>m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return 0;
}