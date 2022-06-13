#include <bits/stdc++.h>
using namespace std;
int main(){
    // Take the vertices and edges of the graph (directed)
    cout<<"Take the vertices and edges of the graph"<<endl;
    int n, m;
    cin>>n>>m;
    // Forming the graph
    cout<<"Enter the values into graph or pairs"<<endl;
    // Nested vector to store the values of graph
    vector<vector<int>> adj(n);
    queue<int> qu;
    vector<int> indeg(n, 0);
    for(int i=0;i<m;i++){
        //Take the pair attached an edge
        int u,v;
        cin>>u>>v;
        // u --> v
        adj[u].push_back(v);
        indeg[v] += 1;
    }
    // Make a queue of first nodes having in degree 0
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            qu.push(i);
        }
    }
    // Continue to remove nodes and work on the rest
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        cout<<x;
        for(auto it:adj[x]){
            indeg[it]--;
            if(indeg[it] == 0)
                qu.push(it);
        }
    }
}