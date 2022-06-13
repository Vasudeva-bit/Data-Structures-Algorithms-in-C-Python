#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

const int INF = 1e9;
const int N = 1e3;
vi visited(N, 0);
vi parent(N);
vi dist(N);
vvi adj[N];
int cost = 0;

int primsMST(int src){
    for(int i=0;i<N;i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert(make_pair(0, src));
    while(!(s.empty())){
        auto x = *(s.begin());
        s.erase(x);
        visited[x.second] = 1;
        cout<<x.second<<" "<<parent[x.second]<<" "<<x.first<<endl;
        cost += x.first;
        for(auto i:adj[x.second]){
            if(visited[i[0]] == 1)
            continue;
            if(dist[i[0]] > i[1]){
                s.erase(make_pair(dist[i[0]], i[0]));
                dist[i[0]] = i[1];
                s.insert(make_pair(dist[i[0]], i[0]));
                parent[i[0]] = x.second;
            }
        }
    }
}

int main(void){
    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int w, u, v;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    primsMST(0);
    cout<<cost;
}