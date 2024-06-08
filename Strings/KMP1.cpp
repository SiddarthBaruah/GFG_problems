// constructing LPS array
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

vector<int> LPS(string s)
{
    int n = s.size();
    vector<int> ret(n);
    ret[0] = 0;
    for (int i = 1; i <n;i++)
    {
        int num=0;
        for(int j=0;j<=num+1;j++)
        {
            if(s[j]==s[i-num-1+j])
                num++;
        }
    }
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