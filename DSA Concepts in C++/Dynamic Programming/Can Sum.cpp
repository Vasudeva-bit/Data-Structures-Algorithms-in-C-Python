#include <bits/stdc++.h>
using namespace std;

int recursiveSum(int n, vector<int>& vectr) {
    if(n == 0)
        return true;
    if(n < 0)
        return false;
    for(auto val:vectr) {
        if(recursiveSum(n-val, vectr))
            return true;
    }
    return false;
}
int memoSum(int n, vector<int>& vectr, vector<int>& memo) {
    if(memo[n] != -1)
        return memo[n];
    if(n == 0)
        return memo[n] = 1;
    if(n < 0)
        return memo[n] = 0;
    for(auto val:vectr) {
        if(memoSum(n-val, vectr, memo) == 1)
            return memo[n] = 1;
    }
    return memo[n] = 0;
}
int tabSum(int n, vector<int>& vectr) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        for(auto val:vectr) {
            if(i-val >= 0)
                dp[i] = max(dp[i], dp[i-val]);
        }
    }
    return dp[n];
}
int main() {
    int n;
    int m;
    cout<<"Enter the number to be verified";
    cin>>n;
    cout<<"Enter the no of arr elements";
    cin>>m;
    vector<int> vectr;
    vector<int> memo(n+1, -1);
    for(int i=0;i<m;i++) {
        int val;
        cin>>val;
        vectr.push_back(val);
    }
    if(memoSum(n, vectr, memo))
        cout<<"The element can be made using the elements in the array";
    else
        cout<<"The element can't be made using the elements in the array";
    cout<<endl; 
    if(tabSum(n, vectr))
        cout<<"The element can be made using the elements in the array";
    else
        cout<<"The element can't be made using the elements in the array"; 
}