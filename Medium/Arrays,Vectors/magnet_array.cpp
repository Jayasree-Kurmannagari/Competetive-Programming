// GeeksForGeeks
// https://practice.geeksforgeeks.org/problems/magnet-array-problem3743/1#

#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nullPoints(int n, double magnets[], double getAnswer[])
    {
        if (n == 1)
            getAnswer[0] = magnets[0];
        for (int i = 0; i < n - 1; i++)
        {
            getAnswer[i] = binarySearch(magnets, magnets[i], magnets[i + 1], n);
        }
    }

    double binarySearch(double magnets[], double l, double r, int n)
    {
        if (l < r)
        {
            double mid = (l + r) / 2;
            double ntforce = netforce(magnets, mid, n);
            if (abs(ntforce) < 1e-9)
                return mid;
            else if (ntforce > 0)
                binarySearch(magnets, mid, r, n);
            else
                binarySearch(magnets, l, mid, n);
        }
    }
    double netforce(double magnets[], double mid, int n)
    {
        double ntforce = 0;
        for (int i = 0; i < n; i++)
            ntforce += 1 / (mid - magnets[i]);
        return ntforce;
    }
};

int main()
{
    fio
    int n;
    cin >> n;
    double magnets[n], getAnswer[n];
    for (int i = 0; i < n; i++)
        cin >> magnets[i];
    Solution ob;
    ob.nullPoints(n, magnets, getAnswer);
    for (int i = 0; i < n - 1; i++)
        cout <<fixed<<setprecision(2)<< getAnswer[i] << " ";
    cout << endl;
    return 0;
}