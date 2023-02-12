#include <bits/stdc++.h>
using namespace std;
int recursiveFib(int n) {
    if(n <= 2)
        return n-1;
    return recursiveFib(n-1)+recursiveFib(n-2);
}
int memoFib(int n, vector<int>& dp) {
    if(dp[n] != -1)
        return dp[n];
    if(n <= 2)
        return n-1;
    return dp[n] = memoFib(n-1, dp)+memoFib(n-2, dp);
}
int tabFib(int n) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}
int main() {
    int n;
    cout<<"Enter the input to get fibonacci: ";
    cin>>n;
    cout<<"Recursive implementation of fibonacci logic "<<recursiveFib(n);
    vector<int> dp(n+1, -1);
    cout<<endl<<"Memoized implementation of fibonacci logic "<<memoFib(n, dp);
    cout<<endl<<"Tabulated implementation of fibonacci logic "<<tabFib(n);
}