#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int longesstPair(vector<pair<int, int>> arr, int n)
{
    sort(arr.begin(), arr.end(), myCmp);

    int lis[n], res = 1;
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i].first > arr[j].second)
            {
                lis[i] = max(lis[j] + 1, lis[i]);
            }
        }
    }

    int ret = INT_MIN;
    for (int x : lis)
        ret = max(ret, x);

    return ret;
}

void solve()
{
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(5, 24));
    arr.push_back(make_pair(39, 60));
    arr.push_back(make_pair(15, 28));
    arr.push_back(make_pair(27, 40));
    arr.push_back(make_pair(50, 90));

    vector<pair<int, int>> arr1;
    arr1.push_back(make_pair(6, 8));
    arr1.push_back(make_pair(3, 4));

    cout << longesstPair(arr, arr.size()) << endl;
    cout << longesstPair(arr1, arr1.size()) << endl;
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