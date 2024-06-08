/*
    Here we swap the two adjacent elements
    its a stable algo since it doesnt change the order
    time complexity O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
void bubblesort(vector<int> &V)
{
    bool swapped = false;
    for (int i = 0; i < V.size(); i++)
    {
        swapped = false;
        for (int j = 0; j < V.size() - 1 - i; j++)
        {
            if (V[j] > V[j + 1])
            {
                swap(V[j], V[j + 1]);
                swapped = true;
            }
            if (!swapped)
                break;
        }
    }
}
void bublesrt(vector<int> &V)
{
    int n = V.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (V[j] > V[j + 1])
            {
                swap(V[j], V[j + 1]);
            }
        }
    }
}

void solve()
{
    vector<int> V = {1, 5, 4, 7, 8, 5, 9, 2, 23, 4, 32, 123, 12, 32, 33, 32, 4, 324, 324, 236, 224, -12, 3, 43, 42, 12, 421, 3, 12, 1, 32, 23, 2131, 24, 3112, 32, 1312, 2433, 2, 321, 1, 1, 3213, 2, 3, 43, 32, 46, 67, 45, 456, 5, 34, 534, 55, 36, 65, 5, 4, 7, 8, 5, 9, 2, 23, 4, 32, 123, 12, 32, 33, 32, 4, 324, 324, 236, 224, -12, 3, 43, 42, 12, 421, 3, 12, 1, 32, 23, 2131, 24, 3112, 32, 1312, 2433, 2, 321, 1, 1, 3213, 2, 3, 43, 32, 46, 67, 45, 456, 5, 34, 534, 55, 36, 65, 1, 5, 4, 7, 8, 5, 9, 2, 23, 4, 32, 123, 12, 32, 33, 32, 4, 324, 324, 236, 224, -12, 3, 43, 42, 12, 421, 3, 12, 1, 32, 23, 2131, 24, 3112, 32, 1312, 2433, 2, 321, 1, 1, 3213, 2, 3, 43, 32, 46, 67, 45, 456, 5, 34, 534, 55, 36, 65, 1, 5, 4, 7, 8, 5, 9, 2, 23, 4, 32, 123, 12, 32, 33, 32, 4, 324, 324, 236, 224, -12, 3, 43, 42, 12, 421, 3, 12, 1, 32, 23, 2131, 24, 3112, 32, 1312, 2433, 2, 321, 1, 1, 3213, 2, 3, 43, 32, 46, 67, 45, 456, 5, 34, 534, 55, 36, 65, 1, 5, 4, 7, 8, 5, 9, 2, 23, 4, 32, 123, 12, 32, 33, 32, 4, 324, 324, 236, 224, -12, 3, 43, 42, 12, 421, 3, 12, 1, 32, 23, 2131, 24, 3112, 32, 1312, 2433, 2, 321, 1, 1, 3213, 2, 3, 43, 32, 46, 67, 45, 456, 5, 34, 534, 55, 36, 65};

    // for (auto i : V)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    bublesrt(V);
    for (auto i : V)
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