// to find strongly connected graphs
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
    void TarganUtils(int u, bool visited[], int parent[], int low[], int disc[], stack<int> &st);

public:
    Graph(int V);
    void TarganAlgo();
    void addEdge(int u, int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void Graph::TarganUtils(int u, bool visited[], int parent[], int low[], int disc[], stack<int> &st)
{
    static int time = 0;

    low[u] = disc[u] = ++time;

    visited[u] = true;

    st.push(u);

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (!visited[v])
        {
            parent[v] = u;
            TarganUtils(v, visited, parent, low, disc, st);
            low[u] = min(low[u], low[v]);
        }
        else if (parent[u] != v)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u])
    {
        while (st.top() != u && !st.empty())
        {
            int l = st.top();
            st.pop();
            std::cout << l << " ";
        }
        int l = st.top();
        st.pop();
        std::cout << l << endl;
    }
}

void Graph::TarganAlgo()
{
    bool visited[V];
    int parent[V];
    int disc[V];
    int low[V];
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = NIL;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            TarganUtils(i, visited, parent, low, disc, st);
    }
}

void solve()
{
    std::cout << "SCCs in the graph \n";
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.TarganAlgo();
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