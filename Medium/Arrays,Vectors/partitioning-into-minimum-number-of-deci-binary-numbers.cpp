//Leetcode
//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

#include<bits/stdc++.h>
using namespace std;

int main(){
    fio
    string s;
    getline(cin,s);
    int res = 0;
    for(auto x:s) res = max(res,x - '0');
    cout<<res;
    return 0;
}