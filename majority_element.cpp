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

//Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,candidate;
        for(int num:nums){
            if(!count)
                candidate = num;
            count+= (num==candidate)?1:-1;
        }
        return candidate;
    }
};
