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
}

// basic idea is to find the in degrees of all the nodes
// then pushing the nodes which have degree 0 in the queue
// and can print the way we want.

// int V = 10;
// vector<int> adj[V];
// addEdge(adj, 0, 1);
// addEdge(adj, 0, 2);
// addEdge(adj, 2, 3);
// addEdge(adj, 2, 4);
// addEdge(adj, 6, 5);
// addEdge(adj, 5, 4);
// addEdge(adj, 5, 7);
// addEdge(adj, 4, 8);
// addEdge(adj, 7, 8);
// addEdge(adj, 8, 9);
void Kahns_topological_sort(vector<int> adj[], int V)
{
    vector<int> degrees(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            degrees[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (degrees[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            degrees[v]--;
            if (degrees[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

void solve(vector<int> adj[], int V)
{
    Kahns_topological_sort(adj, V);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 6;
    vector<int> adj[V];

    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}