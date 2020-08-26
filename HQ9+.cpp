//Codeforces
//Problem 133A HQ9+
//<a href="https://codeforces.com/contest/133/problem/A">

#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  bool flag=false;
  for(int i=0;i<s.size();i++){
    if(s[i]=='H'||s[i]=='Q'||s[i]=='9'){
      cout<<"YES";
      flag=true;
      break;
    }
  }
  if(!flag)cout<<"NO";
  return 0;
}
