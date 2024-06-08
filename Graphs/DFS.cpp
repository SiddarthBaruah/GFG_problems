#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS_Rec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int v : adj[s])
    {
        if (!visited[v])
        {
            DFS_Rec(adj, v, visited);
        }
    }
}

void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for (bool x : visited)
    {
        x = false;
    }
    DFS_Rec(adj, s, visited);
}

void solve(vector<int> adj[], int V, int s)
{
    DFS(adj, V, s);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 7;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    while (t--)
    {
        solve(adj, V, 0);
    }
    return 0;
}