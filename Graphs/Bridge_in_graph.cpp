#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NIL -1

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

class Graph
{
    int V;
    list<int> *adj;
    void BridgeUtil(int u, bool visited[], int low[], int disc[], int parent[]);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void Bridge();
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

Graph::Graph(int V)
{
    this->V = V;
    this->adj = new list<int>[V];

    // for (int i = 0; i < V; i++)
    // {
    //     adj[i] = list<int>(); // Initialize each list
    // }
}

void Graph::BridgeUtil(int u, bool visited[], int low[], int disc[], int parent[])
{

    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;

        if (!visited[v])
        {
            parent[v] = u;
            BridgeUtil(v, visited, low, disc, parent);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
            {
                cout << u << " " << v << endl;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::Bridge()
{
    bool visited[V];
    int parent[V];
    int disc[V];
    int low[V];

    for (int i = 0; i < V; i++)
    {

        visited[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            BridgeUtil(i, visited, low, disc, parent);
        }
    }
}

void solve()
{
    cout << "Bridges in first graph \n";
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.Bridge();
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