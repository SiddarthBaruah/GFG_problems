// Variation of LIS

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// need to find maximum sum of subsequence of an array
int Max_sum_IS(int arr[], int n)
{
    int lis[n];
    lis[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lis[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[i], lis[j] + arr[i]);
            }
        }
    }
    int res = INT_MIN;

    for (int x : lis)
    {
        res = max(x, res);
    }
    return res;
}

// need to find longest bitonic Subsequence
// here we maintain two array, one lis and one lds
int Biotonic(int arr[], int n)
{
    int lis[n], lds[n];
    lis[0] = 1;
    lds[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        lds[n - 1 - i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j] + 1);
            if (arr[n - 1 - i] > arr[n - 1 - j])
                lds[n - 1 - i] = max(lds[n - 1 - i], lds[n - 1 - j] + 1);
        }
    }

    int res1 = INT_MIN;
    for (int i = 0; i < n; i++)
        res1 = max(lis[i] + lds[n - 1 - i] - 1, res1);

    return res1;
}

void solve()
{
    int arr[] = {3, 20, 4, 6, 7, 30};
    int m = 6;
    cout << "Maximum SumIS: " << Max_sum_IS(arr, m) << endl;

    int arr1[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int m1 = 8;
    cout << "Biotonic: " << Biotonic(arr1, m1) << endl;
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