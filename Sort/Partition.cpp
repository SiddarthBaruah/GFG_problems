#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// time: O(n) space: O(n)
void partition__1(int arr[], int n, int p)
{
    int num = arr[p], arr2[n];
    int i = 0, k = 0, r = 0, l = n - 1;
    while (i < n)
    {
        if (arr[i] == num)
        {
            i++;
            continue;
        }
        if (arr[i] < num)
        {
            arr2[r++] = arr[i++];
        }
        else
        {
            arr2[l--] = arr[i++];
        }
    }
    arr2[r] = num;
    for (int i : arr2)
    {
        cout << i << " ";
    }
}

void solve()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    partition__1(arr, n, 3);
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