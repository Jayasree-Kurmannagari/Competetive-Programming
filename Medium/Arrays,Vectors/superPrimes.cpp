//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/super-primes2443/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<bool> listPrimes(int n){
            vector<bool> v(n+1,0);
            for(int i=2;i<=n;i++){
                bool isPrime = true;
                for(int j=2;j*j<=i;j++){
                    if(i%j==0){
                        isPrime = false;
                        break;
                    }
                }
                if(isPrime) v[i]=isPrime;
            }
            return v;
        }
        int superPrimes(int n){
            vector<bool> v;
            v = listPrimes(n);
            int count = 0;
            for(int i=5;i<=n;i++) if(v[i]&&v[i-2]) count++;
            return count;
        }
};

int main(){
    int n;cin>>n;
    Solution ob;
    int res = ob.superPrimes(n);
    cout<<res<<endl;
    return 0;
}