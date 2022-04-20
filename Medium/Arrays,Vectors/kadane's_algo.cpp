//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#
//Dynamic Programming

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int curr_sum=0,maxTillNow=INT_MIN;
        for(int i=0;i<n;i++){
            curr_sum+=arr[i];
            if(maxTillNow < curr_sum) maxTillNow = curr_sum;
            if(curr_sum<0) curr_sum=0;
        }
        return maxTillNow;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends