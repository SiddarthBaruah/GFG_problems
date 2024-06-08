#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int countInversion(int arr[], int n)
{
    // naive
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
                count++;
        }
    }
    return count;
}

int mergee(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = l, res = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
            res += (n1 - i);
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
    return res;
}

int mergeSortCount(int arr[], int l, int r)
{
    int res = 0;
    if (r > l)
    {
        int m = l + (r - l) / 2;
        res += mergeSortCount(arr, l, m);
        res += mergeSortCount(arr, m + 1, r);
        res += mergee(arr, l, m, r);
    }
    return res;
}
int countInversion_optimised(int arr[], int n)
{
    // using mergesort thing
    int count = 0;
    count = mergeSortCount(arr, 0, n - 1);
    return count;
}

void solve()
{
    int arr[] = {2, 5, 8, 11, 3, 6, 9, 13}, n = 8;
    cout << countInversion_optimised(arr, n) << endl;
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