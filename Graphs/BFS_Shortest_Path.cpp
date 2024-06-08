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

void BFS_shortest_path(vector<int> adj[], int V, int s)
{
    bool visited[V];
    int distance[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
    distance[s] = 0;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                distance[v] = distance[u] + 1; // imp
                q.push(v);
            }
        }
    }
    for (int x : distance)
    {
        cout << x << " ";
    }
}
void solve(vector<int> adj[], int V, int s)
{
    BFS_shortest_path(adj, V, s);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 50;
    vector<int> adj[V];

    // Subgraph 1
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 7);
    addEdge(adj, 3, 8);
    addEdge(adj, 4, 9);
    addEdge(adj, 4, 10);
    addEdge(adj, 5, 11);
    addEdge(adj, 5, 12);
    addEdge(adj, 6, 13);
    addEdge(adj, 6, 14);

    // Subgraph 2
    addEdge(adj, 15, 16);
    addEdge(adj, 15, 17);
    addEdge(adj, 16, 18);
    addEdge(adj, 16, 19);

    // Subgraph 3
    addEdge(adj, 20, 21);
    addEdge(adj, 20, 22);
    addEdge(adj, 21, 23);
    addEdge(adj, 21, 24);
    addEdge(adj, 22, 25);
    addEdge(adj, 22, 26);
    addEdge(adj, 23, 27);
    addEdge(adj, 23, 28);
    addEdge(adj, 24, 29);
    addEdge(adj, 24, 30);
    addEdge(adj, 25, 31);
    addEdge(adj, 25, 32);
    addEdge(adj, 26, 33);
    addEdge(adj, 26, 34);

    // Subgraph 4
    addEdge(adj, 35, 36);
    addEdge(adj, 35, 37);
    addEdge(adj, 36, 38);
    addEdge(adj, 36, 39);
    addEdge(adj, 37, 40);
    addEdge(adj, 37, 41);
    addEdge(adj, 38, 42);
    addEdge(adj, 38, 43);
    addEdge(adj, 39, 44);
    addEdge(adj, 39, 45);
    addEdge(adj, 40, 46);
    addEdge(adj, 40, 47);
    addEdge(adj, 41, 48);
    addEdge(adj, 41, 49);

    // connecting the subgraphs

    addEdge(adj, 41, 1);
    addEdge(adj, 17, 26);
    addEdge(adj, 26, 41);
    while (t--)
    {
        solve(adj, V, 0);
    }
    return 0;
}