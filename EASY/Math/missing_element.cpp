//GeeksForGeeks
//<a href="https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1#">

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findMissing(int arr[],int n){
            int sum = 0;
            sum = accumulate(arr,arr+n-1,sum);
            int actual_sum = (n*(n+1))/2;
            cout<<sum<<" "<<actual_sum<<endl;
            return actual_sum-sum;
        }
};
int main(){
    int n;cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++) cin>>arr[i];
    Solution ob;
    int res = ob.findMissing(arr,n);
    cout<<res<<endl;
    return 0;
}