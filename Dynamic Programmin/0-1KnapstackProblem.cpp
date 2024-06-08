#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int zeroOneKS(int val[], int w[], int n, int W)
{
    if (W <= 0)
        return 0;
    if (n == 0)
        return 0;
    int res;
    if (W - w[n - 1] >= 0)
        res = max(zeroOneKS(val, w, n - 1, W), zeroOneKS(val, w, n - 1, W - w[n - 1]) + val[n - 1]);
    else
        res = zeroOneKS(val, w, n - 1, W);

    return res;
}

// using dp
int zeroOneKS_dp(int val[], int w[], int n, int W)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i < W + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    // here what we are doing is that
    for (int i = 1; i <= n; i++) // going though row
    {
        for (int j = 1; j <= W; j++) // going through the wieghts
        {
            if (w[i - 1] >= j)           // if the current Weight left is less the weight of the value
                dp[i][j] = dp[i - 1][j]; // then simply the previos one will be taken
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]); // otherwise the max of two will be taken
        }
    }
    return dp[n][W];
}

void solve()
{
    int val[] = {10, 40, 30, 50};
    int w[] = {5, 4, 6, 3};
    int W = 10;

    cout << zeroOneKS(val, w, 4, W) << endl;
    cout << zeroOneKS_dp(val, w, 4, W) << endl;
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