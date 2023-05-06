#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int a[N];
int tree[2*N];

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = start+(end-start)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int l, int r) {
    if(start > r or end < l)
        return 0;
    if(l <= start and end <= r)
        return tree[node];
    int mid = start+(end-start)/2;
    int q1 = query(2*node, start, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);
    return q1+q2;
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        a[start] = val;
        tree[node] = val;
        return;
    }
    int mid = start+(end-start)/2;
    if(idx <= mid)
        update(2*node, start, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);
    tree[node] = tree[2*node]+tree[2*node+1];
}

int main() {
    int n;
    cout<<"Enter the no of elements in the array: "<<endl;
    cin>>n;
    cout<<"Enter the elements into the array:"<<endl;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    build(1, 0, n-1);
    cout<<"Value before updation"<<endl<<query(1, 0, n-1, 0, n-3)<<endl;
    cout<<"Updating the value in array"<<endl;
    update(1, 0, n-1, 1, 3);
    cout<<query(1, 0, n-1, 0, n-3);
}