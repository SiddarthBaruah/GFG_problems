// basically to find the number of ways a coins can be selected to
// get a certain output

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// memorization method
vector<vector<int>> memo(4, vector<int>(101, INT_MIN));

int coin_select(int coins[], int m, int sum)
{
    if (sum == 0)
    {
        memo[m][sum] = 1;
        return 1;
    }
    if (sum < 0 || m == 0)
    {
        // memo[m][sum] = 0;
        return 0;
    }

    int res1, res2;
    res1 = (memo[m - 1][sum] != INT_MIN) ? memo[m - 1][sum] : coin_select(coins, m - 1, sum);
    if (sum - coins[m - 1] >= 0)
        res2 = (memo[m][sum - coins[m - 1]] != INT_MIN) ? memo[m][sum - coins[m - 1]] : coin_select(coins, m, sum - coins[m - 1]);
    else
        res2 = 0;
    return res1 + res2;
}

// tabultion
int coin_select_dp(int coins[], int m, int sum)
{
    int dp[m + 1][sum + 1];

    int const__ = m + 1;
    for (int i = 0; i < const__; i++)
    {
        dp[i][0] = 1;
    }

    const__ = sum + 1;
    for (int i = 1; i < const__; i++)
    {
        dp[0][i] = 0;
    }

    const__ = m + 1;
    for (int i = 1; i < const__; i++)
    {
        int const___ = sum + 1;
        for (int j = 1; j < const___; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0)
            {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[m][sum];
}

void solve()
{
    int coins[3] = {1, 2, 3};
    int sum = 100;
    cout << coin_select(coins, 3, sum) << endl;
    cout << coin_select_dp(coins, 3, sum) << endl;
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