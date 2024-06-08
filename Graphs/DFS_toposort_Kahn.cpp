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

void DFS_single_cycle(vector<int> adj[], bool visited[], stack<int> &st, int s)
{
    visited[s] = true;
    for (int v : adj[s])
    {
        if (!visited[v])
        {
            // visited[v] = true;
            DFS_single_cycle(adj, visited, st, v);
        }
    }
    st.push(s);
}

void DFS_toposort(vector<int> adj[], int V)
{
    bool visited[V];
    for (bool x : visited)
    {
        x = false;
    }
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS_single_cycle(adj, visited, st, i);
    }
    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
}

void solve(vector<int> adj[], int V)
{
    DFS_toposort(adj, V);
}

signed main()
{
    fastio;
    int t;
    cin >> t;

    int V = 11;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 6, 5);
    addEdge(adj, 5, 4);
    addEdge(adj, 5, 7);
    addEdge(adj, 4, 8);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    addEdge(adj, 10, 8);

    while (t--)
    {
        solve(adj, V);
    }
    return 0;
}