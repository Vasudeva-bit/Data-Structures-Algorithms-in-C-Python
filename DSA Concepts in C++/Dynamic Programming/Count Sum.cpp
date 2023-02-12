#include <bits/stdc++.h>
using namespace std;

int recursive(string str, vector<string>& vectr) {
    if(str == "")
        return 1;
    int out = 0;
    for(auto Sstr: vectr) {
        size_t found = str.find(Sstr);
        if(found == 0) {
            out += recursive(str.substr(Sstr.size(), str.size()-Sstr.size()), vectr);
        }
    }
    return out;
}
int memo(string str, vector<string>& vectr, unordered_map<string, int>& dp) {
    if(str == "")
        return dp[""] = 1;
    if(dp.find(str) != dp.end())
        return dp[str];
    int out = 0;
    for(auto Sstr: vectr) {
        size_t found = str.find(Sstr);
        if(found == 0) {
            out += memo(str.substr(Sstr.size(), str.size()-Sstr.size()), vectr, dp);
        }
    }
    return dp[str] = out;
}
int tab(string str, vector<string>& vectr) {
    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        for(auto ele: vectr) {
            if(ele[0] == str[i-1]) {
                dp[i+ele.size()-1] += dp[i-1];
            }
        }
    }
    return dp[n];
}
int main() {
    string src = "abcdef";
    vector<string> opts = {"ab", "abc", "def", "abcd", "c", "ef"};
    unordered_map<string, int> dp;
    cout<<"Memo: "<<memo(src, opts, dp)<<endl;
    cout<<"Recursive: "<<recursive(src, opts)<<endl;
    cout<<"Tabulation: "<<tab(src, opts);
}