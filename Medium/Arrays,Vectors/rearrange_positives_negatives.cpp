//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1#

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        void rearrangeWithSpace(int arr[],int n){
            //Order Retention,Space:O(n),Time:O(n)
            vector<int> pos,neg;
            for(int i=0;i<n;i++){
                if(arr[i]>=0) pos.push_back(arr[i]);
                else neg.push_back(arr[i]);
            }
            int i=0,j=0,x=0;
            while(i<pos.size() && j<neg.size()){
                if(x%2) arr[x++]=neg[j++];
                else arr[x++]=pos[i++];
            }
            while(i<pos.size()) arr[x++]=pos[i++];
            while(j<neg.size()) arr[x++]=neg[j++];
        }

        int partition(int arr[],int l,int h){
            int i=-1,j=0,pivot=0;
            for(int j=0;j<h;j++){
                if(arr[j]<pivot) swap(arr[++i],arr[j]);
            }
            swap(arr[++i],arr[h-1]);
            return i;
        }

        void rearrangeWithPartition(int arr[],int n){
            //No Order Retention, Space:O(1),Time:O(n)
            int pos = partition(arr,0,n);
            int neg = 0;
            while(neg<pos){
                swap(arr[neg],arr[pos++]);
                neg+=2;
            }
        }
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    //ob.rearrangeWithSpace(arr,n);
    //ob.rearrangeWithPartition(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}