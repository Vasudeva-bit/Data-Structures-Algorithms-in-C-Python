#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

int find_set(int val);
int N = 1e5+6;
vi parent(N);
vi size(N);

void make_set(int val){
    parent[val] = val;
    size[val] = 1;
}

void union_set(int val1, int val2){
    int x = find_set(val1);
    int y = find_set(val2);
    if(x != y){
        if(size[x]<size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
}

int find_set(int val){
    if(parent[val] == val)
    return val;
    return parent[val] = find_set(parent[val]);
}

int main(void){
    int n, m;
    vvi edges;
    cin>>n>>m;

    for(int i=0;i<N;i++){
        make_set(i);
    }

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }

    for(auto i:edges){
        int x = find_set(i[0]);
        int y = find_set(i[1]);
        if(x == y){
            cout<<"Cycle is Detected!";
            return 0;
        }
        else{
            union_set(i[0], i[1]);
        }
    }
    cout<<"Cycle is not Detected!";

}