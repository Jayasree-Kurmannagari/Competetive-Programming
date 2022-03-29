//Codeforces
//Problem 102397C The Ending Point
//<a href="https://codeforces.com/gym/102397/problem/C">

#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;cin>>x>>y;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        switch (s[i])
        {
        case 'U':
            y++;
            continue;
        case 'D':
        y--;
        continue;
        case 'L':
        x--;
        continue;
        case 'R':
        x++;
        continue;
    }
}
cout<<x<<" "<<y;
    return 0;
}
