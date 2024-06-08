#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int meet_Max(int arr[], int go[], int n)
{
    sort(arr, arr + n);
    sort(go, go + n);
    int ret = INT_MIN;
    int people = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] < go[j])
        {
            people++;
            i++;
        }
        else if (arr[i] > go[j])
        {
            people--;
            j++;
        }
        else
        {
            i++;
            j++;
            continue;
        }
        ret = max(ret, people);
    }
    while (i < n)
    {
        ret++;
    }

    return ret;
}

void solve()
{
    int arr[] = {900, 600, 700}, dep[] = {1000, 800, 730};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << meet_Max(arr, dep, n) << endl;
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