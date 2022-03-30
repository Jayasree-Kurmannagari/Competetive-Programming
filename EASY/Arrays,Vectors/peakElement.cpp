//GeeksForGeeks
//<a href="https://practice.geeksforgeeks.org/problems/peak-element/1">
//Algo: Divide and Conquer
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findPeak(int arr[],int n,int l,int r){
        int mid = l+((r-l)/2);
        if(mid>0 && arr[mid]<arr[mid-1]) findPeak(arr,n,l,mid-1);
        else if(mid<n-1 && arr[mid]<arr[mid+1]) findPeak(arr,n,mid+1,r);
        else return mid;
    }
    int peakElement(int arr[],int n){
        int l=0,r=n-1;
        if(n==0 || n==1) return r;
        int res = findPeak(arr,n,l,r);
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        int res = ob.peakElement(arr,n);
        cout<<res<<endl;
    }
    return 0;
}
