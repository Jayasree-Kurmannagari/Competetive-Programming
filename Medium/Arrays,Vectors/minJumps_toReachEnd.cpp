//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
//Greedy Algorithm


#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        int range = arr[0],steps = arr[0],count=1;
        for(int i=1;i<n;i++){
            if(i==n-1)return count;
            steps--;
            range = max(range,i+arr[i]);
            if(steps==0){
                count++;
                if(i>=range) return -1;
                steps = range - i;
                
            }
        }
        return count;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}