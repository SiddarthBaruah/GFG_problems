#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int minJump(int arr[], int n, int dist)
{
    if (dist == n - 1)
        return 0;
    int res = INT_MAX;
    for (int i = 1; i <= arr[dist]; i++)
    {
        if (dist + i < n)
        {
            res = min(res, minJump(arr, n, dist + i) + 1);
        }
    }
    return res;
}

// using tabulation
int minJump_dp(int arr[], int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (dp[j] != INT_MAX && arr[j] + j >= i)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}
void solve()
{
    int arr[] = {3, 4, 2, 1, 2, 1};
    int arr1[] = {4, 1, 5, 3, 1, 3, 2, 1, 8};
    cout << minJump(arr, 6, 0) << endl;
    cout << minJump(arr1, 9, 0) << endl;

    cout << minJump_dp(arr1, 9) << endl;
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