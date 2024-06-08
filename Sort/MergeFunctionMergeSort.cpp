#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void merge_sort(int arr[], int low, int mid, int high)
{
    int a[mid - low + 1];
    int b[high - mid];
    for (int i = 0; i <= mid; i++)
    {
        a[i] = arr[i];
    }
    for (int i = mid + 1; i <= high; i++)
    {
        b[i - mid - 1] = arr[i];
    }
    int i = 0, j = 0;
    while (i < mid + 1 && j < (high - mid))
    {
        if (a[i] < b[j])
        {
            arr[i + j] = a[i];
            i++;
        }
        else
        {
            arr[i + j] = b[j];
            j++;
        }
    }
    while (i < mid + 1)
    {
        arr[i + j] = a[i];
        i++;
    }
    while (j < high - mid)
    {
        arr[i + j] = b[j];
        j++;
    }
}

void solve()
{
    int arr[] = {10, 15, 20, 40, 8, 11, 55};
    merge_sort(arr, 0, 3, 6);
    for (int x : arr)
        cout << x << " ";
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