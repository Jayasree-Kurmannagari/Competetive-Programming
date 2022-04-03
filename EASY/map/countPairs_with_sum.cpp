//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

#include<bits/stdc++.h>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
using namespace std;

class Solution{
    public:
        int countPairs(int arr[],int n,int sum){
            int count=0;
            unordered_map<int,int> umap;
            unordered_map<int, int>:: iterator itr;
            for(int i=0;i<n;i++){
                if(umap.count(sum-arr[i])) count+=umap[sum-arr[i]];
                umap[arr[i]]++;
            }
            return count;
        }
};

int main(){
    int n;cin>>n;
    int sum;cin>>sum;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    Solution ob;
    int res = ob.countPairs(arr,n,sum);
    cout<<res<<endl;
    return 0;
}