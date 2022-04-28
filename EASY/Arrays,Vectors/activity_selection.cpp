//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
//Greedy Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        int count = 1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            pair<int,int> p = make_pair(end[i],start[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        int endpoint_index=0;
        for(int i=0;i<n-1;i++) {
            if(v[endpoint_index].first<v[i+1].second) {count++;endpoint_index=i+1;}
        }
        return count;
    }
};