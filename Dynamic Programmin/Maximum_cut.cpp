#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int maximum_cut(int n, int a, int b, int c)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;

    int res = max(maximum_cut(n - a, a, b, c), max(maximum_cut(n - b, a, b, c), maximum_cut(n - c, a, b, c)));
    if (res == -1)
        return res;
    else
        return res + 1;
}

int maxCut(int n, int a, int b, int c, int memo[])
{
    if (n < 0)
        return -1;
    if (n == 0)
    {
        memo[n] = 0;
        return 0;
    }

    int res1, res2, res3;
    if (n - a >= 0)
    {
        res1 = (memo[n - a] != INT_MIN) ? memo[n - a] : maxCut(n - a, a, b, c, memo);
    }
    else
    {
        res1 = -1;
    }
    if (n - b >= 0)
    {
        res2 = (memo[n - b] != INT_MIN) ? memo[n - b] : maxCut(n - b, a, b, c, memo);
    }
    else
    {
        res2 = -1;
    }
    if (n - c >= 0)
    {
        res3 = (memo[n - c] != INT_MIN) ? memo[n - c] : maxCut(n - c, a, b, c, memo);
    }
    else
    {
        res3 = -1;
    }
    int res = max(res1, max(res2, res3));

    if (res == -1)
    {
        memo[n] = res;
        return res;
    }

    else
    {
        memo[n] = res + 1;
        return memo[n];
    }
}
// tabulation

int max_cut_table(int n, int a, int b, int c)
{
    int table[n + 1];
    table[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        table[i] = -1;
        if (i - a >= 0)
            table[i] = max(table[i], table[i - a]);
        if (i - b >= 0)
            table[i] = max(table[i], table[i - b]);
        if (i - c >= 0)
            table[i] = max(table[i], table[i - c]);
        if (table[i] != -1)
            table[i]++;
    }
    return table[n];
}
void solve()
{
    int n = 5;
    cout << maximum_cut(5, 1, 2, 3) << endl;

    int memo[n + 1];
    for (int x : memo)
        x = INT_MIN;
    cout << maxCut(n, 1, 2, 3, memo) << endl;
    cout << max_cut_table(n, 1, 2, 3) << endl;
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