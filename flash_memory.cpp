//Codeforces
//Problem 102397J AbuTahun and Flash Memories
//<a href="https://codeforces.com/gym/102397/problem/J">

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,s,count=0,value,devices=0;
    cin>>n>>x>>s;
    value=s/x;
    while(devices<n){
        devices +=value;
        count++;
    }
    cout<<count;
    return 0;
}
