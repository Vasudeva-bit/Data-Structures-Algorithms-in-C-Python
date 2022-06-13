#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution {
public:
    int count(string s){
        int c=0;
        for(auto i:s){
            if(i == '0')
                c++;
        }
        return c;
    }
    int recur(vector<string>& strs, int m, int n, int index){
        if(m +n == 0 || index==strs.size())
            return 0;
        int mm = count(strs[index]);
        int nn = strs[index].size() - mm;
        int consider = 0;
        int skip = 0;
        // Consider the element
        if(m-mm>=0 && n-nn>=0)
        consider += recur(strs, m-mm, n-nn, index+1);
        // Not consider the element
        skip += recur(strs, m, n, index+1);
        return min(consider , skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return recur(strs, m, n, 0);
    }
};

int main(){
    Solution ob;
    vi input({"10","0001","111001","1","0"});
    ob.findMaxForm(input, 5, 3);
    return 0;
}