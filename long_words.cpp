// Codeforces
// Problem 71A Way-too-long-words
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;
    for(int i=0;i<n;i++){
    cin>>s;
    int size = s.size();
    if(size>10)
    cout<<s[0]+to_string(size-2)+s[size-1]<<endl;
    else
    cout<<s<<endl;
    }
    return 0;
}