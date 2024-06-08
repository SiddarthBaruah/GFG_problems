#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

void MergeInterval(vector<pair<int, int>> arr)
{
    sort(arr.begin(), arr.end(), myCmp);
    vector<pair<int, int>> toret;
    int i = 0;
    while (i < arr.size())
    {
        int f = arr[i].first;
        int s = arr[i].second;
        while (arr[i + 1].first <= s && i + 1 < arr.size())
        {
            i++;
            s = max(s, arr[i].second);
        }
        toret.push_back(make_pair(f, s));
        i++;
    }
    for (pair<int, int> i : toret)
        cout << i.first << " " << i.second << endl;
}

void solve()
{
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(5, 10));
    arr.push_back(make_pair(3, 15));
    arr.push_back(make_pair(18, 30));
    arr.push_back(make_pair(2, 7));

    MergeInterval(arr);
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