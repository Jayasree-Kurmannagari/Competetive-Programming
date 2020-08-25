//Codeforces
//Problem 231A Team
//<a href="https://codeforces.com/problemset/problem/231/A">


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m1,m2,m3,count;cin>>n;
    count=0;
    for(int i=0;i<n;i++){
        cin>>m1>>m2>>m3;
        if(m1+m2+m3 >= 2)
        count++;
    }
    cout<<count;
    return 0;
}
