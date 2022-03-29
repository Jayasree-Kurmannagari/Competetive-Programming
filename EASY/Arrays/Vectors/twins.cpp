//Codeforces
//Problem 160A Twins
//<a href="https://codeforces.com/contest/160/problem/A">

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,val,tsum=0,sum=0,result=0;cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
    cin>>val;
    tsum+=val;
    v.push_back(val);
  }
  sort(v.begin(), v.end(), greater<int>());
  for(int i=0;i<n;i++){
    sum+=v[i];
     result++;
    if(sum>tsum-sum){
      cout<<result;
      break;
    }
  }
  return 0;
}
