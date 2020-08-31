//Codeforces
//Problem 282A Bit++
//<a href="https://codeforces.com/contest/282/problem/A">

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,result=0;
    cin>>n;
    string s;
    vector<string> v;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        if(v[i]== "++X" || v[i]=="X++")
        result++;
        else
        result--;
    }
    cout<<result;
    return 0;
}
