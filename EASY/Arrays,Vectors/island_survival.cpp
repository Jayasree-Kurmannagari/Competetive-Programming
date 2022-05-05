//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1/#

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    int minimumDays(int S, int N, int M){
       if(6*N>=7*M or (S<7 and M<=N)) return ceil((double)(S*M)/N);
       else return -1;
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}