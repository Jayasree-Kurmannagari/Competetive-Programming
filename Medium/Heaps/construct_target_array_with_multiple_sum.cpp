//LeetCode
//https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        unsigned int sum = 0;
        sum = accumulate(target.begin(),target.end(),sum);
        priority_queue<int> pq(target.begin(),target.end());
        while(pq.top()!=1){
            sum -= pq.top(); 
            if(sum==0 || sum >= pq.top()) return false;
            int new_val = pq.top()%sum;
            if(sum!=1 && new_val < 1) return false;
            pq.pop();
            pq.push(new_val);
            sum+=new_val;
        }
        return true;
    }
};

int main(){
    fio
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    Solution ob;
    bool ans = ob.isPossible(v);
    cout<<ans;
    return 0;
}