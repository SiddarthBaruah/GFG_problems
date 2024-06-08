#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void lomuto(int arr[], int l, int h, int p)
{
    int i = l - 1, j = l;
    int num = arr[p];
    while (j < h)
    {
        if (arr[j] == num)
        {
            swap(arr[j], arr[h]);
            continue;
        }
        if (arr[j] < num)
        {
            i++;
            swap(arr[i], arr[j]);
            j++;
            continue;
        }
        j++;
    }
    i++;
    swap(arr[i], arr[h]);
}

void solve()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    lomuto(arr, 0, n - 1, 4);
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