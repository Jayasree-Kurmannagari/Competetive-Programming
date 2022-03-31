//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

#include<bits/stdc++.h>
#define ll long long
using namespace std;

pair<long long,long long> getMinMax(ll arr[],int n){
    ll min = *min_element(arr,arr+n);
    ll max = *max_element(arr,arr+n);
    pair<ll,ll> p = make_pair(min,max);
    return p;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        pair<ll,ll> p = getMinMax(arr,n);
        cout<<p.first<<" "<<p.second<<endl;
    }
     return 0;
}
