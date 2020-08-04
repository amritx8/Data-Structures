#include<bits/stdc++.h>

using namespace std;

// Using DFS and Recursion Satck.
// TC - O(E + V).
// SC - O(V).
bool DFS(int at, vector<int> adjList[], vector<bool> &visit, vector<bool> &recursionStack){
    
    visit[at] = 1;

    for(int to : adjList[at]){

        if(!visit[to]){
            
            if(DFS(to, adjList, visit, recursionStack)) {

                return 1;
            }
        }
        else{

            if(recursionStack[at]) {

                return 1;
            }
        }
    }

    return 0;
}
void CycleDetectionUsingRecursionStack(int n, vector<int> adjList[]) {

    vector<bool> visit(n,0), recursionStack(n,0);
    bool isCycle = 0;

    for(int i=0; i<n; i++) {

        if(!visit[i]) {

            isCycle = isCycle|DFS(i, adjList, visit, recursionStack);
        }
    }

    cout<<isCycle;
}


// Using DFS and Graph Coloring.
// TC - O(E + V).
// SC - O(V).
bool DFS2(int at, vector<int> adjList[], vector<int> &color) {

    color[at] = 1;

    for(int to : adjList[at]) {

        if(color[to]==0) {

            if(DFS2(to, adjList, color)) {

                return 1;
            }
        }
        else if(color[to]==1) {

           return 1;
        }
    }

    color[at] = 2;
    return 0;
}
void CycleDetectionUsingGraphColoring(int n, vector<int> adjList[]) {

    vector<int> color(n, 0);
    bool isCycle = 0;

    for(int i=0; i<n; i++) {

        if(color[i]==0) {

            isCycle = isCycle|DFS2(i, adjList, color);
        }
    }

    cout<<isCycle;
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