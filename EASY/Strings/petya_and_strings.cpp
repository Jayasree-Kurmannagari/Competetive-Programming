//Codeforces
//Problem 112A Petya and Strings
//<a href="https://codeforces.com/contest/112/problem/A>"

#include<bits/stdc++.h>
using namespace std;
int main(){
    char s1[150],s2[150];
    int result;
    cin>>s1>>s2;
    for(int i=0;i<strlen(s1);i++){
        s1[i]=tolower(s1[i]);
        s2[i]=tolower(s2[i]);
    }
    result = strcmp(s1,s2);
    if(result==0)cout<<0;
    else if(result<0) cout<< -1;
    else cout<<1;
    return 0;
}
