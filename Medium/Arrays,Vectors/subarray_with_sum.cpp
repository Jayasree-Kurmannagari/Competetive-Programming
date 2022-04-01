// GeeksForGeeks
//<a href="https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#">
// Sliding window Algorithm

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> subarraysum(int arr[], int n, int s)
    {
        int sum = 0;
        int curr_index = 0;
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {
            if (sum == s)
            {
                v.push_back(curr_index + 1);
                v.push_back(i);
                return v;
            }
            sum += arr[i];
            while (sum > s)
            {
                sum -= arr[curr_index];
                curr_index++;
            }
        }
        return v;
    };
};
int main()
{
    int n, s;
    cin >> n;
    cin >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution ob;
    vector<int> res;
    res = ob.subarraysum(arr, n, s);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}