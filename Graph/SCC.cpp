#include<bits/stdc++.h>
using namespace std;

/* 
    SCC defined only for directed graph.
    There are mainly 2 algorithm Kosaraju's and Tarjan's Algorithm.

    For both Algorithm -
    TC - O(E + V). 
    SC - O(V).

    In Kosaraju's algorithm 2 DFS traversal required but in Tarjan's algorithm
    1 DFS traversal required.
*/

void KosarajuDFS(int at, vector<int> adjList[], vector<bool> &visit, stack<int> &stack) {

    visit[at] = 1;

    for(int to : adjList[at]) {

        if(!visit[to]) {

            KosarajuDFS(to, adjList, visit, stack);
        }
    }

    stack.push(at);
}
void KosarajuDFS2(int at, vector<int> adjList2[], vector<bool> &visit) {

    visit[at] = 1;

    cout<<at<<" ";

    for(int to : adjList2[at]) {

        if(!visit[to]) {

            KosarajuDFS2(to, adjList2, visit);
        }
    }
}
void SCCUsingKosaraju(int n, vector<int> adjList[]) {

    vector<bool> visit(n,0);
    stack<int> stack;
    vector<int> adjList2[n];

    for(int i=0; i<n; i++) {

        if(!visit[i]) {

            KosarajuDFS(i, adjList, visit, stack);
        }
    }

    for(int i=0; i<n; i++) {

        visit[i] = 0;

        for(auto at : adjList[i]) {

            adjList2[at].push_back(i);
        }
    }

    while(!stack.empty()) {

        int at = stack.top();
        stack.pop();

        if(!visit[at]) {

            KosarajuDFS2(at, adjList2, visit);

            cout<<endl;
        }
    }
}


void TarjanDFS(int u, vector<int> adjList[], vector<bool> &visit, int *id, vector<int> &lowLink, vector<bool> &inStack, stack<int> &Stack) {

    visit[u] = 1;
    inStack[u] = 1;
    lowLink[u] = *id;
    *id  = *id + 1;
    Stack.push(u);

    for(auto v : adjList[u]) {

        if(!visit[v]) {

            TarjanDFS(v, adjList, visit, id, lowLink, inStack, Stack);
        }
        if(inStack[v]) {
            
            lowLink[u] = min(lowLink[u], lowLink[v]);
        }
    }

    if(lowLink[u]==u) {

        while(!Stack.empty()){

            int v = Stack.top();
            Stack.pop();

            inStack[v] = 0;
            cout<<v<<" ";

            if(v==u) {

                cout<<endl;
                break;
            }
        }
    }
}
void SCCUsingTarjan(int n, vector<int> adjList[]) {

    vector<bool> visit(n,0);
    vector<bool> inStack(n,0);
    int id = 0;
    vector<int> lowLink(n);
    stack<int> Stack;

    for(int i=0; i<n; i++) {

        if(!visit[i]) {

            TarjanDFS(i, adjList, visit, &id, lowLink, inStack, Stack);
        }
    }
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