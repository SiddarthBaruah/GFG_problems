#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// Naive method
void merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    // int pivot = arr[m];
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
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
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
}

void sortMerge(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = l + (h - l) / 2;
        sortMerge(arr, l, m);
        sortMerge(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

// using Lomuto
int lomuto(int arr[], int l, int h)
{
    int i = l - 1, j = l;
    int pivot = arr[h];
    while (j < h)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            j++;
            continue;
        }
        j++;
    }
    swap(arr[++i], arr[j]);
    return i;
}

int kth_element(int arr[], int n, int k)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int p = lomuto(arr, l, h);
        if (p == k - 1)
        {
            return arr[p];
        }
        else if (p > k - 1)
        {
            h = p - 1;
        }
        else
        {
            l = p + 1;
        }
    }
    return -1;
}

void solve()
{
    int arr[] = {3, 2, 1, 6, 5, 4, 3, 8, 9};
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    sortMerge(arr, 0, n - 1);
    for (int i : arr)
        cout << i << " ";

    int k = 4;
    cout << endl
         << arr[k - 1] << endl;
    int l = kth_element(arr, n, k);
    cout << l;
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