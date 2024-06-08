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

void BFS(vector<int> adj[], bool visited[], int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void BFS_dis(vector<int> adj[], int V)
{
    bool visited[V + 1];
    for (bool x : visited)
    {
        x = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            BFS(adj, visited, i);
        }
    }
}

void solve(vector<int> adj[], int V)
{
    BFS_dis(adj, V);
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
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}