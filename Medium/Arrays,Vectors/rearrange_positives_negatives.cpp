//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1#

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        void rearrangeWithSpace(int arr[],int n){
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
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    ob.rearrangeWithSpace(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}