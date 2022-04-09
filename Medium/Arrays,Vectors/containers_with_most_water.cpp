//Leetcode
//https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1,minimum=0,area=0,curr=0;
        while(i<j){
            curr = (j-i)*min(height[i],height[j]);
            if(curr>area) area=curr;
            minimum = min(height[i],height[j]);
            if(minimum==height[i]) i++;
            else j--;
        }
        return area;
    }
};

int main(){
    vector<int> height;
    int input;
    while (cin >> input) height.push_back(input);
    Solution ob;
    int area = ob.maxArea(height);
    cout<<area<<endl;
    return 0;
}