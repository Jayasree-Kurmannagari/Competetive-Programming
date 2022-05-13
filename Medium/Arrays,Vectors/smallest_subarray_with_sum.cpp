//Leetcode
//https://leetcode.com/problems/minimum-size-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minSubArrLen(int arr[],int target,int n){
            int i=0,j=0,sum=0,len=INT_MAX;
            while(i<n){
                sum+=arr[i++];
                while(sum>=target){
                    sum-=arr[j++];
                    len = min(len,i-j+1);
                }
            }
            return len;
        }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    int n;cin>>n;
    int target;cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    cout<<ob.minSubArrLen(arr,target,n)<<endl;
    return 0;
}