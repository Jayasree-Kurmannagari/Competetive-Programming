//Leetcode
//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        array<int,26> freq{};
        for(auto x:s) freq[x-'a']++;
        sort(freq.begin(),freq.end(),greater<int>());
        int final_count = 0,prev=INT_MAX;
        for(auto x:freq){
            if(!x || !prev) break;
            prev = min(x,prev-1);
            final_count += prev;
        }
        return s.size()-final_count;
    }
};

int main(){
    fio
    string s;
    getline(cin,s);
    Solution ob;
    int res = ob.minDeletions(s);
    cout<<res;
    return 0;
}