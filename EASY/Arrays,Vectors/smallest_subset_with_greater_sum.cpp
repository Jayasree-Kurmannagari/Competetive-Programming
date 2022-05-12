//GeeksFOrGeeks
//https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1/#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        if(N==1) return 1;
        sort(Arr.begin(),Arr.end(),greater<int>());
        int count = 0;
        long long sum=0;
        long long allSum = 0;
        for(int i=0;i<N;i++) allSum+=Arr[i];
        for(int i=0;i<N;i++){
            sum+=Arr[i];
            count++;
            if(sum > allSum-sum) break;
        }
        return count;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
    Solution ob;
    cout<<ob.minSubset(v,n)<<endl;
    return 0;
}