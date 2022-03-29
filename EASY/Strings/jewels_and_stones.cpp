//Leetcode
//Problem Jewels and Stones
//<a href="https://leetcode.com/problems/jewels-and-stones/">

#include<algorithm>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int tcount=0;
        for(char c:J){
            tcount+=count(S.begin(),S.end(),c);
        }
        return tcount;
    }
};
