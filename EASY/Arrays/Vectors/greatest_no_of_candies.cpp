//Leetcode
//Problem  Kids With the Greatest Number of Candies
//<a href="https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/">

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(),candies.end());
        vector<bool> v;
        for(int candy:candies){
            if(candy+extraCandies >= max) v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};
