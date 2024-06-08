#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void merge_srt(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    int toret[m + n];
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            toret[i + j] = a[i];
            i++;
        }
        else
        {
            toret[i + j] = b[j];
            j++;
        }
    }
    while (i < m)
    {
        toret[i + n] = a[i];
        i++;
    }
    while (j < n)
    {
        toret[j + m] = b[j];
        j++;
    }
    for (int v : toret)
        cout << v << " ";
}

void solve()
{
    int arr1[] = {10, 15, 20, 20};
    int arr2[] = {1, 12};
    merge_srt(arr1, arr2, 4, 2);
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