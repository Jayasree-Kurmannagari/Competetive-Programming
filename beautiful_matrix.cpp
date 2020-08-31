//Codeforces
//Problem 263A Beautiful Matrix
//<a herf="https://codeforces.com/contest/263/problem/A">

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5][5],val;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>val;
            a[i][j]=val;
            if(val==1){
                cout<<abs(2-i)+abs(2-j);
            }
        }
    }
    return 0;
}
