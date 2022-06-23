//LeetCode
//https://leetcode.com/problems/course-schedule-iii/


#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int totalTime = 0;
        int count = 0;
        sort(courses.begin(), courses.end(), [](auto &a, auto &b) {return a[1] < b[1];});
        priority_queue<int> pq;
        for(int i=0;i<courses.size();i++){
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            if(lastDay>=duration){
                if(duration+totalTime <= lastDay){
                    totalTime+=duration;
                    count++;
                    pq.push(duration);
                }
                else if(pq.size() && pq.top()>duration){
                    totalTime+= duration-pq.top();
                    pq.pop();
                    pq.push(duration);
                }
            }
        }
        return count;
    }
};

int main(){
    fio
    int n;cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<2;j++) {
            int x;cin>>x;
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }
    Solution ob;
    int res = ob.scheduleCourse(v);
    cout<<res;
    return 0;
}