#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// using tabulation
int LongestIncreasingSubsequence(int arr[], int m)
{
    int lis[m];
    lis[0] = 1;
    for (int i = 1; i < m; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int res = INT_MIN;
    for (int x : lis)
    {
        res = max(x, res);
    }
    return res;
}

// using Binary Search, this is more optimised
int ceilIndx(int tail[], int l, int r, int val)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] > val)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int LIS_BS(int arr[], int n)
{
    int lis[n], res = 1;
    lis[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > lis[res - 1])
        {
            lis[res] = arr[i];
            res++;
        }
        else
        {
            lis[ceilIndx(lis, 0, res - 1, arr[i])] = arr[i];
        }
    }
    return res;
}

void solve()
{
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    cout << LongestIncreasingSubsequence(arr, 7) << endl;
    cout << LIS_BS(arr, 7);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}