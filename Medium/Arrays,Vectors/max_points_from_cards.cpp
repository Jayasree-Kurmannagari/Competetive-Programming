//Leetcode
//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/


#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curr_sum=0;
        int l=0,r=cardPoints.size()-k;
        for(int i=r;i<cardPoints.size();i++) curr_sum+=cardPoints[i];
        int max_sum = curr_sum;
        for(int i=0;i<k;i++){
            curr_sum +=  cardPoints[i] - cardPoints[r++];
            max_sum = max(curr_sum,max_sum);
        }
        return max_sum;
    }
};

int main(){
    fio
    int n;cin>>n;
    int k;cin>>k;
    vector<int> cardPoints;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        cardPoints.push_back(x);
    }
    Solution ob;
    int sum = ob.maxScore(cardPoints,k);
    cout<<sum;
    return 0;
}