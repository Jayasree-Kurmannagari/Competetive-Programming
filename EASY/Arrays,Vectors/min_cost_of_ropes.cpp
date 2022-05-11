//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minCost(int arr[],int n){
            int sum=0;
            priority_queue<int,vector<int>,greater<int>> p(arr,arr+n);
            while(p.size()>1){
                int tempSum = p.top();p.pop();
                tempSum+=p.top();p.pop();
                sum+=tempSum;
                p.push(tempSum);
            }
            return sum;
        }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    cout<<ob.minCost(arr,n)<<endl;
    return 0;
}