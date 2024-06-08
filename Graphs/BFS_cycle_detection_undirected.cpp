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

bool check_cycle_BFS(vector<int> adj[], int V, bool visited[], int s)
{ // search for cycle in one subgraph if find one returns true
    queue<int> q;
    vector<int> parent(V, -1);
    q.push(s);
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
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}

bool BFS_Cycle_detection(vector<int> adj[], int V)
{ // if finds cycle returns true
    bool visited[V + 1];
    for (int x : visited)
    {
        x = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            if (!check_cycle_BFS(adj, V, visited, i))
                continue;
            else
                return true;
        }
    }
    return false;
}

void solve(vector<int> adj[], int V)
{
    if (BFS_Cycle_detection(adj, V))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 20;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 10);
    addEdge(adj, 10, 11);
    addEdge(adj, 11, 12);
    addEdge(adj, 12, 13);
    addEdge(adj, 13, 14);
    addEdge(adj, 14, 15);
    addEdge(adj, 15, 16);
    addEdge(adj, 16, 17);
    addEdge(adj, 17, 18);
    addEdge(adj, 18, 19);
    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}