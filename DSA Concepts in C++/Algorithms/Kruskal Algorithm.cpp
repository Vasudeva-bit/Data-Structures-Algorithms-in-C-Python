#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

int N = 1e5+6;
vi parent(N);
vi size(N);

void make_set(int val){
    parent[val] = val;
    size[val] = 1;
}

int find_set(int val){
    if(val == parent[val])
        return val;
    return parent[val] = find_set(parent[val]);
}

void union_set(int val1, int val2){
    int x = find_set(val1);
    int y = find_set(val2);
    if(x != y){
        if(size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
}

int main(void){

    for(int i=0;i<N;i++){
        make_set(i);
    }

    int n, m;
    cin>>n>>m;
    vvi edges;
    int cost = 0;

    for(int i=0;i<m;i++){
        int w, u, v;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    for(auto i:edges){
        int x = find_set(i[1]);
        int y = find_set(i[2]);
        if(x == y)
            continue;
        union_set(i[1], i[2]);
        cost += i[0];
    }
    cout<<cost<<" is the Minimum Spanning Tree Cost!";
}