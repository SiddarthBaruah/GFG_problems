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

bool DFS_Rec(vector<int> adj[], int s, bool visited[], bool RecSt[])
{
    visited[s] = true;
    RecSt[s] = true;
    for (int v : adj[s])
    {
        if (visited[v] == false && DFS_Rec(adj, v, visited, RecSt))
        {
            return true;
        }
        else if (RecSt[v] == true)
        { // we are not accouting parrent because it cannot come back
            return true;
        }
    }
    RecSt[s] = false;
    return false;
}

bool DFS_cycle_directed(vector<int> adj[], int V)
{
    bool visited[V];
    bool RecSt[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        RecSt[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (DFS_Rec(adj, i, visited, RecSt))
            {
                return true;
            }
        }
    }
    return false;
}

void solve(vector<int> adj[], int V)
{
    if (DFS_cycle_directed(adj, V))
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    // addEdge(adj, 3, 0);
    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}