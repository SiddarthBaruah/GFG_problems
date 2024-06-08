#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int sum_(int arr[], int b, int e)
{
    int sum = 0;
    for (int i = b; i <= e; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int min_Page(int arr[], int n, int k)
{
    if (k == 1)
        return sum_(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(sum_(arr, i, n - 1), min_Page(arr, i, k - 1)));
    }
    return res;
}

int min_page_dp(int arr[], int n, int k)
{
    int dp[n + 1][k + 1];
    for (int i = 1; i <= k; i++)
    {
        dp[1][i] = arr[0];
    }
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += arr[i - 1];
        dp[i][1] = s;
    }
    for (int i = 2; i <= n; i++)
    {

        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int l = 1; l < i; l++)
            {
                dp[i][j] = min(dp[i][j], max(sum_(arr, l, i - 1), dp[l][j - 1]));
            }
        }
    }
    return dp[n][k];
}
void solve()
{
    int arr[] = {10, 5, 30, 1, 2, 5, 10, 10};
    cout << min_Page(arr, 8, 3) << endl;
    cout << min_page_dp(arr, 8, 3) << endl;
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