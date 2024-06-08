#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// memorization

int edit_dist(string s1, string s2, int m, int n, vector<vector<int>> memo)
{
    if (m == 0)
    {
        memo[m][n] = n;
        return n; // since n deletion operation has to occur
    }

    if (n == 0)
    {
        memo[m][n] = m;
        return m; // since m intertion has to occur
    }

    if (s1[m - 1] == s2[n - 1]) // if the last letter is same we will just remove it
    {
        if (memo[m][n] != -1)
            return memo[m][n];
        else
        {
            memo[m][n] = edit_dist(s1, s2, m - 1, n - 1, memo);
            return memo[m][n];
        }
    }
    else
    {
        int num1 = (memo[m][n - 1] != -1) ? memo[m][n - 1] : edit_dist(s1, s2, m, n - 1, memo);             // intertion
        int num2 = (memo[m - 1][n] != -1) ? memo[m - 1][n] : edit_dist(s1, s2, m - 1, n, memo);             // deletion
        int num3 = (memo[m - 1][n - 1] != -1) ? memo[m - 1][n - 1] : edit_dist(s1, s2, m - 1, n - 1, memo); // replace
        return 1 + min(num1, min(num2, num3));
    }
}

// tabulation
int edit_dist_dp(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[m][n];
}

void solve()
{
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    cout << edit_dist(s1, s2, s1.length(), s2.length(), memo) << endl;
    cout << edit_dist_dp(s1, s2) << endl;
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