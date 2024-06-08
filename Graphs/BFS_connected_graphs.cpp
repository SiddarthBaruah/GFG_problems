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
    q.push(s);
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void BFS_dis(vector<int> adj[], int V)
{
    bool visited[V + 1];
    int count = 0;
    for (bool x : visited)
    {
        x = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            BFS(adj, visited, i);
            count++;
        }
    }
    cout << count;
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
    int V = 13;
    vector<int> adj[V];

    // Subgraph 1
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    // Subgraph 2
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);

    // Subgraph 3
    addEdge(adj, 8, 9);

    // Subgraph 4
    addEdge(adj, 10, 11);
    addEdge(adj, 11, 12);
    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}