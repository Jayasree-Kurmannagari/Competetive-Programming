//Leetcode
//https://leetcode.com/problems/non-decreasing-array/

#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(i-2>=0 && nums[i-2]>nums[i]) {nums[i]=nums[i-1];count++;}
                else {nums[i-1]=nums[i];count++;}
            } 
        }
        return count<=1;
    }
};

int main(){
    fio
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        v.push_back(x);
    }
    Solution ob;
    bool res = ob.checkPossibility(v);
    cout<<res;
    return 0;
}