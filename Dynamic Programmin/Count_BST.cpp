#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int countBST(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += countBST(i) * countBST(n - i - 1);
    }
    return res;
}

int count_BST_dp(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int res = 0;
        for (int j = 0; j < i; j++)
        {
            res += dp[j] * dp[i - j - 1];
        }
        dp[i] = res;
    }
    return dp[n];
}
void solve()
{
    cout << countBST(5) << endl;
    cout << count_BST_dp(5) << endl;
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