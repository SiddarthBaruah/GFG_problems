#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int mult_chain(int arr[], int i, int j)
{
    if (i + 1 == j)
        return 0;
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, mult_chain(arr, i, k) + mult_chain(arr, k, j) + arr[i] * arr[j] * arr[k]);
    }
    return res;
}
int mult_chain_dp(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i + 1] = 0;
    }
    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
            }
        }
    }

    return dp[0][n - 1];
}
void solve()
{
    int arr[] = {2, 1, 3, 4};
    cout << mult_chain(arr, 0, 3) << endl;
    cout << mult_chain_dp(arr, 4) << endl;
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