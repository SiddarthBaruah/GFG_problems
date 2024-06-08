/*
    selection sort reduces memory writes
    cycle sort is the most optimised
    its not stable
    In-place algo
    Time Complexity O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void selection_sort(vector<int> &A)
{
    int num = INT_MIN;
    int num_index = 0;
    for (int i = 0; i < A.size(); i++)
    {
        num = INT_MIN;
        for (int j = 0; j < A.size() - i; j++)
        {
            if (A[j] >= num)
            {
                num_index = j;
                num = A[j];
            }
        }
        swap(A[num_index], A[A.size() - 1 - i]);
    }
}

void solve()
{
    vector<int> V = {1, 5, 4, 7, 8, 5, 9, 2, 23, 4, 32, 123, 12, 32, 33, 32, 4, 324, 324, 236, 224, -12};
    for (auto i : V)
    {
        cout << i << " ";
    }
    cout << endl;
    selection_sort(V);
    for (auto i : V)
    {
        cout << i << " ";
    }
    cout << endl;
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