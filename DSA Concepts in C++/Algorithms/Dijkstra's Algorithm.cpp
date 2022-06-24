#include <bits/stdc++.h>
#define vvi vector<vector<pair<int,int>>>
#define vi vector<int>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vvi edges(n+1);
    int INF = 1e9;
    vi dist(n+1, INF);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w}); // Remove this line in case of directed graph for dijkstra's algo
    }
    int src;
    cin>>src;
    set<pair<int,int>> s;
    dist[src] = 0;
    s.insert({0, src});
    // w, s => pair
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it: edges[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i]<INF)
        cout<<dist[i]<<" ";
        else
        cout<<-1<<" ";
    }
}