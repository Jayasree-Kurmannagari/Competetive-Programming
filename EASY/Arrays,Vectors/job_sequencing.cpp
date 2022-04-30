//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
//Greedy Algorithm

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution{
    public:
        static bool compare(Job a, Job b){
            return a.profit>b.profit;
        }
        vector<int> JobScheduling(Job arr[],int n){
            vector<int> v(n,-1);
            vector<int> res;
            sort(arr,arr+n,compare);
            int profit=0,count=0;
            for(int i=0;i<n;i++){
                for(int j=arr[i].dead-1;j>=0;j--){
                    if(v[j]==-1) {
                        v[j] = arr[i].profit;
                        profit+=arr[i].profit;
                        count++;
                        break;
                    }
                }
            }
            res.push_back(count);
            res.push_back(profit);
            return res;
        }
};

int main(){
    int n;cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x;cin>>y;cin>>z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    Solution ob;
    vector<int> res = ob.JobScheduling(arr,n);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}