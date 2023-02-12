#include <bits/stdc++.h>
using namespace std;
vector<int> null = {-1};
vector<int> recursive(int tSum, vector<int> vectr) {
    if(tSum == 0) return {};
    if(tSum < 0) return {-1};
    vector<int> out = null;
    for(auto ele: vectr) {
        auto curOut = recursive(tSum-ele, vectr);
        if(curOut == null) continue; 
        curOut.push_back(ele);
        if(out == null or curOut.size() < out.size())
            out = curOut;
    }
    return out;
}

vector<int> memo(int tSum, vector<int> vectr, vector<vector<int>>& dp) {
    if(tSum == 0) return dp[tSum] = {};
    if(tSum < 0) return {-1};
    if(dp[tSum] != null)
        return dp[tSum];
    vector<int> out = null;
    for(auto ele: vectr) {
        auto curOut = memo(tSum-ele, vectr, dp);
        if(curOut == null) continue; 
        curOut.push_back(ele);
        if(out == null or curOut.size() < out.size())
            out = curOut;
    }
    return dp[tSum] = out;
}

vector<int> tab(int tSum, vector<int> vectr) {
    vector<vector<int>> dp(tSum+1, null);
    dp[0] = {};
    for(int i=0;i<=tSum;i++) {
        if(dp[i] != null) {
            for(auto ele: vectr) {
                if(i+ele > tSum)
                    continue;
                vector<int> out;
                for(auto val: dp[i]) {
                    out.push_back(val);
                }
                out.push_back(ele);
                if(dp[i+ele] == null or out.size() < dp[i+ele].size())
                    dp[i+ele] = out;
            }vector<int> out;
        }
    }
    return dp[tSum];
}

int main() {
    cout<<"The shortest combination of to sum upto target sum using recursion: "<<endl;
    auto out = recursive(7, {5, 2, 4, 6, 1});
    for(auto ele: out) {
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<"The shortest combination of to sum upto target sum using recursion: "<<endl;
    vector<vector<int>> dp(8, null);
    out = memo(7, {5, 3, 4, 7}, dp);;
    for(auto ele: out) {
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<"The shortest combination of to sum upto target sum using recursion: "<<endl;
    out = tab(8, {5, 3, 4, 7});;
    for(auto ele: out) {
        cout<<ele<<" ";
    }
}