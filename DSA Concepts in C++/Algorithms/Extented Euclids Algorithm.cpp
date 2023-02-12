#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> gcd(int a, int b){
        // code here
        if(b == 0) {
            vector<int> t(3);
            t[0] = a;
            t[1] = 1;
            t[2] = 0;
            return t;
        }
        vector<int> t(3);
        auto T = gcd(b, a%b);
        t[0] = T[0];
        t[1] = T[2];
        t[2] = T[1]-(a/b)*T[2];
        return t;
    }
};