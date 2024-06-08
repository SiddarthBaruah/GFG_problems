#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void merge_(list<int> &a, list<int> &b)
{
    std::list<int>::iterator i = a.begin(), j = b.begin();
    while (j != b.end())
    {
        if (i == a.end() || *i > *j)
        {
            a.insert(i, *j);
            j++;
        }
        else
        {
            i++;
        }
    }
    // return a;
}
void solve()
{
    list<int> a = {1, 3, 5, 6, 9};
    list<int> b = {2, 4, 6, 8, 9};
    merge_(a, b);
    for (int i : a)
    {
        cout << i << " ";
    }
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