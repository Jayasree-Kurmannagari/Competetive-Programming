//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findMinDiff(vector<int> v,int n,int m){
            sort(v.begin(),v.end());
            int diff = INT_MAX;
            for(int i=0;i+m-1<n;i++){
                int tempDiff = v[i+m-1]-v[i];
                diff = min(diff,tempDiff); 
            }
            return diff;
        }
};


int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    int n,m;cin>>n;cin>>m;
    vector<int> v;
    for(int i=0;i<n;i++) {int x;cin>>x;v.push_back(x);};
    Solution ob;
    cout<<ob.findMinDiff(v,n,m)<<endl;
    return 0;
}