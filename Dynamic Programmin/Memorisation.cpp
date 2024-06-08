// Fibonaci

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

vector<int> memo(100, -1);

int Fibo(int n)
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            res = n;
        else
        {
            res = Fibo(n - 1) + Fibo(n - 2);
        }
        memo[n] = res; // storing the result so we dont have to call again
    }
    return memo[n];
}

void solve()
{
    cout << Fibo(5) << endl;
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