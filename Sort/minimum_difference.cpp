#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int minDiff(int arr[], int n)
{
    sort(arr, arr + n);
    int min_ = INT_MAX;
    if (n == 1)
        return min_;

    for (int i = 1; i < n; i++)
    {
        min_ = min(min_, arr[i] - arr[i - 1]);
    }
    return min_;
}

void solve()
{
    int arr[] = {1, 8, 12, 5, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDiff(arr, n) << endl;
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