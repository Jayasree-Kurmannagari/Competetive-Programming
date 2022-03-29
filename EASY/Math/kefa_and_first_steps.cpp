//Codeforces
//Problem 580A Kefa and First steps 
//<a href="https://codeforces.com/contest/580/problem/A">

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,val,count=0,maximum=0;cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
    cin>>val;
    v.push_back(val);
  }
  for(int i=1;i<n;i++){
    if(v[i-1] <= v[i]){
      count++;
      maximum=max(maximum,count);
    }
    else if(v[i-1]>v[i]){
      maximum=max(maximum,count);count=0;
    }
  }
  cout<<maximum+1;
  return 0;
}
