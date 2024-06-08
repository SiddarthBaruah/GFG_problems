#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int find(int parent[], int rep)
{
    if (rep = parent[rep])
        return rep;
    parent[rep] = find(parent, parent[rep]);
    return parent[rep];
}

void union_(int parent[], int rank[], int u, int v)
{
    int rep_x = find(parent, u);
    int rep_y = find(parent, v);
    if (rank[rep_x] > rank[rep_y])
        parent[rep_y] = rep_x;
    else if (rank[rep_x] < rank[rep_y])
        parent[rep_x] = rep_y;
    else
    {
        parent[rep_x] = rep_y;
        rank[rep_y]++;
    }
}

void solve()
{
    int n = 0;
    int parent[n];
    int rank[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
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