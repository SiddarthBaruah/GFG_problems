#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void sort_type(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < 0);
        do
        {
            j--;
        } while (arr[j] >= 0);
        if (i >= j)
            return;
        swap(arr[i], arr[j]);
    }
}

void solve()
{
    int arr[] = {13, -12, 18, -10};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort_type(arr, n);
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