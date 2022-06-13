#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
vvi adj;
vi visited;
int get_count(int i){
    if(visited[i])
        return 0;
    visited[i] = 1;
    int count = 1;
    for(auto it: adj[i]){
        if(!visited[it]){
            count += get_count(it);
            visited[it] = 1;
        }
    }
    return count;
}
int32_t main(void){
    int n, m;
    cin>>n>>m;
    adj = vvi(n);
    visited = vi(n, 0);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi components;
    for(int i=0;i<n;i++){
        if(!visited[i])
            components.push_back(get_count(i));
    }
    for(auto i : components){
        cout<<i<<" ";
    }
}