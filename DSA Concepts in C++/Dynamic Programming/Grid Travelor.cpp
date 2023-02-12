#include <bits/stdc++.h>
using namespace std;
int recursiveGrid(int n, int m) {
    if(n == 0 or m == 0)
        return 0;
    if(n == 1 and m == 1)
        return 1;
    if(n == 1 or m == 1)
        return 1;
    return recursiveGrid(n-1, m) + recursiveGrid(n, m-1);
}
int memoGrid(int n, int m, vector<vector<int>>& dp) {
    if(dp[n][m] != -1)
        return dp[n][m];
    if(n == 0 or m == 0)
        return dp[n][m] = 0;
    if(n == 1 and m == 1)
        return dp[n][m] = 1;
    if(n == 1 or m == 1)
        return dp[n][m] = 1;
    return dp[n][m] = memoGrid(n-1, m, dp) + memoGrid(n, m-1, dp);
}
int tabGrid(int n, int m) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[1][1] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main() {
    int n, m; 
    cout<<"Enter the input to get grid co-ordinates: ";
    cin>>n;
    cin>>m;
    cout<<"Recursive implementation of fibonacci logic "<<recursiveGrid(n, m);
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<endl<<"Memoized implementation of fibonacci logic "<<memoGrid(n, m, dp);
    cout<<endl<<"Tabulated implementation of fibonacci logic "<<tabGrid(n, m);
}