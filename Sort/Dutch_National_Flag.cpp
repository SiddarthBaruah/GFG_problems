// used for sepearating three types of objects

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void sort__(int arr[], int n)
{
    int mid = 0, i = 0, h = n - 1;
    while (mid <= h)
    {
        if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 0)
        {
            swap(arr[i], arr[mid]);
            i++;
            mid++;
        }
        else
        {
            swap(arr[mid], arr[h]);
            h--;
        }
    }
}

void solve()
{
    int arr[] = {0, 1, 0, 2, 0, 4, 1, 1, 0, 3, 3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort__(arr, n);
    for (int i : arr)
        cout << i << " ";
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