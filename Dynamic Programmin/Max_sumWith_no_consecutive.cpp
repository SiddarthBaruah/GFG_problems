#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// Time complex- O(n^2)  Space complex- O(1)
int max_sum(int arr[], int n)
{
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res, arr[i]);
        for (int j = i + 2; j < n; j++)
        {
            res = max(res, arr[i] + arr[j]);
        }
    }
    return res;
}

// Time complex- O
int max_sum_recur(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);

    return max(max_sum_recur(arr, n - 1), max_sum_recur(arr, n - 2) + arr[n - 1]);
}
// Time complex- O(n) Space- O(n)
int max_sum_dp(int arr[], int n)
{
    int dp[n + 1];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
    }
    return dp[n];
}

// Time complex- O(n) Space- O(1)
int max_sum_dp_space_optimised(int arr[], int n)
{
    int a0 = arr[0];
    int a1 = max(arr[0], arr[1]);
    int res;
    for (int i = 3; i <= n; i++)
    {
        res = max(arr[i - 1] + a0, a1);
        a0 = a1;
        a1 = res;
    }
    return res;
}

void solve()
{
    int arr[] = {1, 10, 2};
    cout << max_sum(arr, 3) << endl;
    cout << max_sum_recur(arr, 3) << endl;
    cout << max_sum_dp(arr, 3) << endl;
    cout << max_sum_dp_space_optimised(arr, 3) << endl;
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