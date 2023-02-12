#include <bits/stdc++.h>
using namespace std;
bool isConnectedDFS(int src, int dst, vector<vector<int>>& adjMat) {
    if(src == dst)
        return true;
    for(auto neighbour: adjMat[src]) {
        return isConnectedDFS(neighbour, dst, adjMat);
    }
    return false;
}
bool isConnectedBFS(int src, int dst, vector<vector<int>>& adjMat) {
    if(src == dst) 
        return true;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int cur = q.front();
        if(cur == dst) 
            return true;
        q.pop();
        for(auto neighbour: adjMat[cur])
            q.push(neighbour);
    }
    return false;
}
int main() {
    vector<vector<int>> adjMat;
    adjMat = {{1}, {3, 5}, {3, 1}, {4}, {2}, {}};
    int src = 0;
    int dst = 2;
    if(isConnectedDFS(0, 2, adjMat))
        cout<<"Reachable - DFS"<<endl;
    if(isConnectedBFS(0, 2, adjMat))
        cout<<"Reachable - BFS";
    return 0;
}