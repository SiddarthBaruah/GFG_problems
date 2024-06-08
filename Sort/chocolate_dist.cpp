#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int minDistribution(int arr[], int n, int m)
{
    sort(arr, arr + n);
    int min_ = INT_MAX;
    for (int i = 0; i + m < n; i++)
    {
        min_ = min(min_, arr[i + m] - arr[i]);
    }
    return min_;
}

void solve()
{
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDistribution(arr, n, 2) << endl;
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