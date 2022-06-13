#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
vi color;
vvi adj;
bool isBipartite = true;
void coloring(int idx, int cur){
    if(color[idx] != -1 && color[idx] != cur){
        isBipartite = false;
        return;
    }
    if(color[idx] != -1)
    return;
    color[idx] = cur;
    for(auto it:adj[idx]){
        coloring(it, cur xor 1);
    }
}
int main(void){
    int n, m;
    cin>>n>>m;
    color = vi(n, -1);
    adj = vvi(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Traversing the graph
    for(int i=0;i<n;i++){
        if(color[i] == -1)
            coloring(i, 0);

    }
    if(isBipartite)
    cout<<"The Graph is Bipartite";
    else
    cout<<"The Graph is not Bipartite";
}