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

bool cycle_detection_kahn(vector<int> adj[], int V)
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
        // cout << u << " ";
        for (int v : adj[u])
        {
            degrees[v]--;
            if (degrees[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int v : degrees)
    {
        if (v)
            return true;
    }
    return false;
}

void solve(vector<int> adj[], int V)
{
    if (cycle_detection_kahn(adj, V))
        cout << "Yes";
    else
        cout << "No";
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
    addEdge(adj, 3, 5);
    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}