#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number upto which the prime numbers need to be generated: ";
    cin>>n;
    vector<int> primes;
    for(int i=0;i<=n;i++) {primes.push_back(i);}
    primes[0] = 0;
    primes[1] = 0;
    int p=2;
    while(p*p <= n) {
        if(primes[p] != 0) {
            int j = p*p;
            while(j <= n) {
                primes[j] = 0;
                j += p;
            }
        }
        p++;
    }
    for(auto p: primes) {
        if(p != 0)
            cout<<p<<" ";
    }
}