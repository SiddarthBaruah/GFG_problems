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

int Building_bridges(vector<pair<int, int>> arr, int n)
{
    sort(arr.begin(), arr.end(), myCmp);
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i].second > arr[j].second)
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int res = INT_MIN;
    for (int x : lis)
        res = max(x, res);

    return res;
}

// using binary search
int comIdx(int arr[], int l, int r, int var)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (arr[m] > var)
            r = m;
        else
            l = m + 1;
    }
    return r;
}
int BuildBridge_BS(vector<pair<int, int>> arr, int n)
{
    sort(arr.begin(), arr.end(), myCmp);
    int lis[n], res = 1;

    lis[0] = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].second > arr[i].first)
        {
            res++;
            lis[i] = arr[i].second;
        }
        else
        {
            int index = comIdx(lis, 0, res, arr[i].second);
            lis[index] = arr[i].second;
        }
    }
    return res;
}

void solve()
{
    int n = 4;
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(6, 2));
    arr.push_back(make_pair(4, 3));
    arr.push_back(make_pair(2, 6));
    arr.push_back(make_pair(1, 5));

    cout << Building_bridges(arr, n) << endl;
    cout << BuildBridge_BS(arr, n) << endl;
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