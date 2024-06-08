// basically i have to pick coins from the both side and need to get the maximum values of coins

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int strat(int arr[], int l, int r)
{
    if (l + 1 == r)
        return max(arr[l], arr[r]);
    int res;
    res = max(arr[l] + min(strat(arr, l + 1, r - 1), strat(arr, l + 2, r)), arr[r] + min(strat(arr, l, r - 2), strat(arr, l + 1, r - 1)));
    return res;
}

int strat_dp(int arr[], int n)
{
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    for (int gap = 3; gap < n; gap += 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];
}

void solve()
{
    int arr[] = {2, 3, 15, 7};
    cout << strat(arr, 0, 3) << endl;
    cout << strat_dp(arr, 4) << endl;
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