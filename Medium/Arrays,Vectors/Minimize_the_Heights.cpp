// GeeksForGeeks
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int tempmin = arr[0];
        int tempmax = arr[n - 1];
        int res = tempmax - tempmin;
        for (int i = 0; i < n - 1; i++)
        {
            tempmin = min(arr[0] + k, arr[i + 1] - k);
            tempmax = max(arr[n - 1] - k, arr[i] + k);
            res = min(res, tempmax - tempmin);
        }
        return res;
    }
};

int main(){
    int n;cin>>n;
    int k;cin>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution ob;
    int ans = ob.getMinDiff(arr,n,k);
    cout<<ans<<endl;
    return 0;
}