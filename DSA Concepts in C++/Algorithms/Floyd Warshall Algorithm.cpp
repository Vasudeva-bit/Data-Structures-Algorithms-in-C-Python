#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int32_t main(){
    // Consider an Example Adj Matrix
    vector<vector<int>> adjmat = {
                                    {0, 5, INF, 10},
                                    {INF, 0, 3, INF},
                                    {INF, INF, 0, INF},
                                    {INF, INF, INF, 0}
                                 };
    int n = adjmat.size();
    // Floyd Warshall Algorithm
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
        }
    }
    // Print the Shortest Paths
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjmat[i][j] != INF)
                cout<<adjmat[i][j]<<" ";
            else
                cout<<"I ";
        }
        cout<<endl;
    }
}   