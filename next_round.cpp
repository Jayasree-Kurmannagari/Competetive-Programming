//Codeforces
//Problem 158A Next Round
//<a href="https://codeforces.com/contest/158/problem/A">

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,value,count=0;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>value;
        v.push_back(value);
    }
    for(int i=0;i<n;i++){
        if(v.at(i) >= v.at(k-1) && v.at(i)!=0)
        count++;
    }
    cout<<count;
    return 0;
}
