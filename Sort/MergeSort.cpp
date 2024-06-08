#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
        a[i] = arr[i + low];

    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = a[i++];
    }
    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2; // to stop the overflow but basically means (r+l)/2
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void solve()
{
    int arr[] = {10, 5, 30, 15, 7};
    mergeSort(arr, 0, 4);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    int arr2[] = {10, 15, 20, 40, 8, 11, 55};
    merge(arr2, 0, 3, 6);
    for (int x : arr2)
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