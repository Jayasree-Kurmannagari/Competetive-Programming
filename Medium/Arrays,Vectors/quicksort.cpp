//Sorting

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h){
    int i=l-1,pivot=h;
    for(int j=l;j<h;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[pivot]);
    return i+1;
}
void quickSort(int arr[],int l,int h){
    if(l<h){
        int p = partition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}