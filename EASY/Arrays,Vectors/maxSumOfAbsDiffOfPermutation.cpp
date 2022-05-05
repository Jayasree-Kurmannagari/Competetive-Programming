//GeeksForGeeks
//https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int i=0,j=n-1;
    vector<int> v;
    while(i<j){
        v.push_back(arr[i++]);
        v.push_back(arr[j--]);
    }
    if(i==j) v.push_back(arr[i]);
    int sum=0;
    for(int i=0;i<n;i++){
        int diff = abs(v[i%n]-v[(i+1)%n]);
        sum+=diff;
    }
    cout<<sum;
    return 0;
}