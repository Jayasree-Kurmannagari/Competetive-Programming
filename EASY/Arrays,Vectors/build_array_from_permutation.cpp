//LeetCode
//https://leetcode.com/problems/build-array-from-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i]+nums.size()*(nums[nums[i]]%nums.size());
        }
        for(int i=0;i<nums.size();i++) nums[i]/=nums.size();
        return nums;
    }
};

int main(){
    int input;
    vector<int> v;
    while(cin>>input) v.push_back(input);
    Solution ob;
    v = ob.buildArray(v);
    for(auto i:v) cout<<i<<" ";
    return 0;
}