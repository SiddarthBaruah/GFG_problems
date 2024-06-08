#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int eggSolve(int e, int f)
{
    if (f == 1 || f == 0)
        return f;
    if (e == 1)
        return f;
    int res = INT_MAX;
    for (int x = 1; x < f; x++)
    {
        res = min(res, max(eggSolve(e - 1, x - 1), eggSolve(e, f - x)));
    }

    return res + 1;
}
// now applying dp
int eggSolve_dp(int e, int f)
{
    int dp[e + 1][f + 1];
    for (int i = 0; i <= e; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int i = 0; i <= f; i++)
    {
        dp[1][i] = i;
    }
    for (int i = 2; i <= e; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            int res = INT_MAX;
            for (int x = 1; x < j; x++)
            {
                res = min(res, max(dp[i - 1][x - 1], dp[i][j - x]));
            }
            dp[i][j] = res + 1;
        }
    }
    return dp[e][f];
}

void solve()
{
    cout << eggSolve(10, 10) << endl;
    cout << eggSolve_dp(10, 100) << endl;
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