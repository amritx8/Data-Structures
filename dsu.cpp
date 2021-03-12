#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

// dsu simple algorithm

vector<int> parent(MAX);
vector<int> rk(MAX);

// making separate sets for all the nodes first
void make_set(int v){
    parent.resize(v);
    rk.resize(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
        rk[i]=1; 
    }
}

// finding the parent set with path compression
// if we don't apply path compression, the time complexity
// for each find_set() call is O(n)
// After applying path compression, the time complexitiy
// is averaged to O(logn) i.e maximum height of the tree
int find_set(int v){
    if(v==parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

// union by rank ensures that always attach the tree 
// with the lower rank to the one with the bigger rank
void union_set(int u,int v){
    u=find_set(u);
    v=find_set(v);
    
    if(u!=v) {
        if(rk[u]>rk[v]){
            parent[v]=u;
            rk[u]+=rk[v];
        }
        else{
            parent[u]=v;
            rk[v]+=rk[u]; 
        }
    }
}


int main(){

    int n;
    cin>>n;
    // types of problems mainly include connected vertices
    // and then we need to find all the components etc.

    return 0;
}