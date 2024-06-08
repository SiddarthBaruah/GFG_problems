// Hybrid of Heap, Quic and Insertion sort
/*
    if sees it is making unfair comparisions then goes to quicksort

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

struct Point

{
    int x, y;
};

bool compare(Point p1, Point p2)
{
    return p1.x < p2.x;
}
void solve()
{
    int n = 6;
    int arr[] = {1, 2, 0, 6, 4, 3};
    sort(arr, arr + n);
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    sort(arr, arr + n, greater<int>());
    for (int x : arr)
    {
        cout << x << " ";
    }
    Point a[] = {{1, 2}, {3, 2}, {9, 4}, {5, 6}, {3, 4}};
    sort(a, a + 5, compare);
    cout << endl;
    for (auto i : a)
    {
        cout << i.x << " " << i.y << "/";
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