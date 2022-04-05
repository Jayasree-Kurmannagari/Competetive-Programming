//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void countSubarrWithEqualZeroAndOne(int arr[], int n){
            for(int i=0;i<n;i++){
                if(arr[i]==0) arr[i]=-1;
            }
            unordered_map<int,int> umap;
            int count=0,sum=0;
            umap[0]=1;
            for(int i=0;i<n;i++){
                sum+=arr[i];
                if(umap[sum]>=1) count+=umap[sum];
                umap[sum]++;
            }
        cout<<count<<endl;
        }

        void printSubarrWithEqualZeroAndOne(int arr[],int n){
            unordered_map<int,vector<int>> umap;
            vector<pair<int,int>> p;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=arr[i];
                if(sum==0) p.push_back(make_pair(0,i));
                if(umap.find(sum)!=umap.end()){
                    vector<int> v = umap[sum];
                    for(auto x:v) p.push_back(make_pair(x+1,i));
                }
                umap[sum].push_back(i);
            }
            for(auto x:p) {cout<<x.first<<" "<<x.second;cout<<endl;}
        }
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    ob.countSubarrWithEqualZeroAndOne(arr,n);
    ob.printSubarrWithEqualZeroAndOne(arr,n);
    return 0;
}