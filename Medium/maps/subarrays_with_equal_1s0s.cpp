//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int countSubarrWithEqualZeroAndOne(int arr[], int n){
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
        return count;
        }
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    int res = ob.countSubarrWithEqualZeroAndOne(arr,n);
    cout<<res;
    return 0;
}