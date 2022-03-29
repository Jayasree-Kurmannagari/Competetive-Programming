//Codeforces
//Problem 96A Football
//<a href="https://codeforces.com/contest/96/problem/A">
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  bool flag=false;
  int count0=0,count1=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='1'){
      count0=0;
      count1++;
      if(count1>=7) {flag=true;cout<<"YES";break;}
    }
    else if(s[i]=='0'){
      count1=0;
      count0++;
       if(count0>=7){flag=true;cout<<"YES";break;}
    }
  }
  if(!flag)
 cout<<"NO";
  return 0;
}
