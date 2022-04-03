//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    int low=0,mid=0,high=n-1;
    for(int i=0;i<n;i++) cin>>arr[i];
    while(mid<=high){
        switch(arr[mid]){
            case 0:
                swap(arr[low++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid++],arr[high--]);
                break;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}