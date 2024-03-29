// GeeksForGeeks
// https://practice.geeksforgeeks.org/problems/common-elements1132/1#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        unordered_set<int> s1;
        s1.insert(A, A + n1);
        unordered_set<int> s2;
        vector<int> v;
        for (int i = 0; i < n2; i++)
        {
            if (s1.find(B[i]) != s1.end())
                s2.insert(B[i]);
        }
        for (int i = 0; i < n3; i++)
        {
            if (s2.find(C[i]) != s2.end())
            {
                v.push_back(C[i]);
                s2.erase(C[i]);
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}