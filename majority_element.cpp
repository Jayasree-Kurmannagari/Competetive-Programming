//Leetcode
//Problem Majority Element
//<a href="https://leetcode.com/problems/majority-element/">

//Using Hash-map:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            if(++umap[nums[i]]>nums.size()/2){
                return nums[i];
            }
    }
        return -1;
    }
};
