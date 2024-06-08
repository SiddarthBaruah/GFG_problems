#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int lomuto(int arr[], int l, int h)
{
    int i = l, j = l;
    int pivot = arr[h];
    while (j < h)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i++], arr[j]);
        }
        j++;
    }
    swap(arr[i], arr[j]);
    return i;
}

void q_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lomuto(arr, l, h);
        q_sort(arr, l, p - 1);
        q_sort(arr, p + 1, h);
    }
}

void solve()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    q_sort(arr, 0, n - 1);
    for (int i : arr)
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