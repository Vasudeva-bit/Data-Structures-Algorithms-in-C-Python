#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> recursive(string str, vector<string>& vectr) {
    if(str == "")
        return {{}};
    vector<vector<string>> result;
    for(auto Sstr: vectr) {
        size_t found = str.find(Sstr);
        if(found == 0) {
            vector<vector<string>> suffixOut;
            string suffix = str.substr(Sstr.size(), str.size()-Sstr.size());
            suffixOut = recursive(suffix, vectr);
            for(auto &vec:suffixOut) {
                vec.push_back(Sstr);
            }
            for(auto vec: suffixOut) {
            result.push_back(vec);
            }
        }
    }
    return result;
}
vector<vector<string>> memo(string str, vector<string>& vectr, unordered_map<string, vector<vector<string>>>& dp) {
    if(str == "")
        return dp[""] = {{}};
    if(dp.find(str) != dp.end())
        return dp[str];
    vector<vector<string>> result;
    for(auto Sstr: vectr) {
        size_t found = str.find(Sstr);
        if(found == 0) {
            vector<vector<string>> suffixOut;
            string suffix = str.substr(Sstr.size(), str.size()-Sstr.size());
            suffixOut = recursive(suffix, vectr);
            for(auto &vec:suffixOut) {
                vec.push_back(Sstr);
            }
            for(auto vec: suffixOut) {
                result.push_back(vec);
            }
        }
    }
    return dp[str] = result;
}
int main() {
    string src = "abcdef";
    vector<string> opts = {"ab", "abc", "def", "abcd", "cd", "ef"};
    auto result = recursive(src, opts);
    unordered_map<string, vector<vector<string>>> dp;
    cout<<"Recursive: "<<endl;
    for(auto each:result) {
        for(auto word:each) {
            cout<<word<<" ";
        }
        cout<<endl;
    }
    cout<<"Memo: "<<endl;
    result = memo(src, opts, dp);
    for(auto each:result) {
        for(auto word:each) {
            cout<<word<<" ";
        }
        cout<<endl;
    }
}