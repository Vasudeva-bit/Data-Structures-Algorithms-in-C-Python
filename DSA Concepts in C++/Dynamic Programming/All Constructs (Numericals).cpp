#include <bits/stdc++.h>
using namespace std;

vector<int> tab(int n, vector<int> vectr) {
    vector<vector<int>> dp(n+1, {-1});
    dp[0] = {};
    for(int i=0;i<=n;i++) {
        vector<int> null = {-1};
        vector<int> vec = dp[i];
        if(vec != null) {
            for(auto opts: vectr) {
                if(i+opts > n)
                    continue;
                if(dp[i+opts][dp[i+opts].size()-1] == -1)
                    dp[i+opts].pop_back();
                for(auto val: dp[i]) {
                    dp[i+opts].push_back(val);
                }
                dp[i+opts].push_back(opts);
                if(i+opts == n) {
                    for(auto ele: dp[i+opts])
                        cout<<ele<<" ";
                    cout<<endl;
                }
                dp[n] = {};
            }
        }
    }
    return dp[n];
}
int main() {
    // Tabulation for How Sum.cpp on integer data
    auto output = tab(7, {5, 3, 4, 7});
    for(auto val:output) {
        cout<<val<<" ";
    }
}