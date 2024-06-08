#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// using recurssion
int min_coin(int arr[], int n, int var)
{
    if (var == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (var - arr[i] >= 0)
        {
            int sub_res = min_coin(arr, n, var - arr[i]);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}

// using memorization this is wrong
int min_coin_memo(int arr[], int n, int var, int memo[])
{
    if (var == 0)
    {
        memo[var] = 0;
        return 0;
    }

    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (var - arr[i] >= 0)
        {
            int sub_res = (memo[var - arr[i]] != -1) ? memo[var - arr[i]] : min_coin_memo(arr, n, var - arr[i], memo);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    memo[var] = res;
    return res;
}

// using tabulation
int min_coin_dp(int arr[], int n, int var)
{
    int dp[var + 1];
    dp[0] = 0;
    for (int i = 1; i < var + 1; i++)
        dp[i] = INT_MAX;

    int ret = INT_MAX;
    for (int i = 1; i < var + 1; i++)
    {
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                int sub_res = dp[i - arr[j]];
                if (sub_res != INT_MAX)
                    dp[i] = min(dp[i], sub_res + 1);
            }
        }
    }
    return dp[var];
}

void solve()
{
    int arr[] = {25, 10, 5};
    cout << min_coin(arr, 3, 30) << endl;

    int memo[31];
    for (int x : memo)
        x = -1;
    cout << min_coin_memo(arr, 3, 30, memo) << endl;
    cout << min_coin_dp(arr, 3, 30) << endl;
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