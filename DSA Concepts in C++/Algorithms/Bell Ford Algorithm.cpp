#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

int main(void){
    int INF = 1e9;
    vvi edges;
    int n, m;
    vi dist(n, INF);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
    }
    int src;
    cin>>src;
    dist[src] = 0;
    for(auto e:edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        dist[v] = min(dist[v], dist[u] + w);
    }

    for(auto i:dist){
        cout<<i<<" ";
    }
    cout<<endl;
}