#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

int main(){
    int INF = 1e9;
    int n, m;
    cin>>n>>m;
    vi dist(n, INF);
    vvi edges(m);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
    }
    int src;
    cin>>src;
    dist[src] = 0;
    // for(int i=0;i<n;i++){
    //     edges.push_back({-1, i, 0});
    // }
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        dist[v] = min(dist[v], dist[u]+w);
    }
    // edges.pop_back();
    // for(auto edge:edges){
    //     edge[2] = edge[2] + dist[edge[1]] - dist[edge[0]];
    // }
    for(auto i:dist){
        cout<<i<<" ";
    }
}