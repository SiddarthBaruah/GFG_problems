#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define V 4
vector<int> dikstra(int graph[V][V], int src)
{
    // int V = graph[0].size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    bool fin[V];
    fill(fin, fin + V, false);
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        fin[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !fin[v])
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}

void solve()
{
    int graph[V][V] = {
        {0, 50, 100, 0},
        {50, 0, 30, 200},
        {100, 30, 0, 20},
        {0, 200, 20, 0},
    };
    for (int x : dikstra(graph, 0))
    {
        cout << x << " ";
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