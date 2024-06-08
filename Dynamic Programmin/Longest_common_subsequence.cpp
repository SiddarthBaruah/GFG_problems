// pick some character in order

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

const int m = 5;
const int n = 7;

// memorization implementation
vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

int lcs(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (s1[m - 1] == s2[n - 1])
    {
        memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
    }
    else
    {
        memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
    return memo[m][n];
}

int lcs_dp(string s1, string s2)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void solve()
{
    cout << lcs("HELLO", "FELQLSO", 5, 7) << endl;
    cout << lcs_dp("HELLO", "FELQLSO") << endl;
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