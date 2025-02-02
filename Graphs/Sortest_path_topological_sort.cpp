#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph
{
    int V;

    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &st);

public:
    Graph(int V);

    void addEdge(int u, int v, int weight);

    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st)
{
    visited[v] = true;
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
        {
            topologicalSortUtil(node.getV(), visited, st);
        }
    }
    st.push(v);
}

void Graph::shortestPath(int s)
{
    stack<int> st;
    bool visited[V];
    vector<int> dist(V, INT_MAX);
    for (bool v : visited)
    {
        v = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, visited, st);
    }
    dist[s] = 0;
    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();
        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); i++)
            {
                if (dist[i->getV()] > dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        (dist[i] == INF) ? cout << "INF" : cout << dist[i] << " ";
    }
}

void solve(int s, Graph &g)
{
    g.shortestPath(s);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);

    int s = 0;
    while (t--)
    {
        solve(s, g);
    }
    return 0;
}