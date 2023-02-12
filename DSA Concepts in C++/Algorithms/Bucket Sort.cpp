#include <bits/stdc++.h>
using namespace std;
// Bucket sort is powerful only if the data is uniformly distributed so we assume that the data is 
// uniformly distributed and we make 10 buckets based on the last digit
int main() {
    vector<float> arr;
    int n;
    cout<<"Enter the no of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++) {
        float tem;
        cin>>tem;
        arr.push_back(tem);
    }
    // Containarize the values into containers or buckets
    vector<vector<float>> buckets(10);
    for(int i=0;i<arr.size();i++) {
        int in = arr[i]*10;
        buckets[in].push_back(arr[i]);
    }
    // Sort each bucket
    for(int i=0;i<buckets.size();i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    // Concatenate the sorted buckets
    int index = 0;
    for(int i=0;i<buckets.size();i++){
        for(auto it:buckets[i]) {
            arr[index++] = it; 
        }
    }
    // Print the sorted array
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<endl;
    }
}