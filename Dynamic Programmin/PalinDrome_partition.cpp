#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

bool isPal(string s, int l, int r)
{
    for (int i = 0; i <= (r - l) / 2; i++)
    {
        if (s[l + i] != s[r - i])
            return false;
    }
    return true;
}

int PalinPart(string s, int i, int j)
{
    if (i + 1 == j)
        return 1;
}

void solve()
{
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