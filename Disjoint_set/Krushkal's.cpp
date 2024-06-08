#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

int find(int parent[], int x)
{
    if (x == parent[x])
        return x;
    parent[x] = find(parent, parent[x]);
    return parent[x];
}

void union_(int parent[], int rank[], int u, int v)
{
    int rep_x = u, rep_y = v;
    if (rank[rep_x] > rank[rep_y])
        parent[rep_y] = rep_x;
    else if (rank[rep_y] > rank[rep_x])
        parent[rep_x] = rep_y;
    else
    {
        parent[rep_x] = rep_y;
        rank[rep_y]++;
    }
}

struct Edge
{
    int from, to, weight;
    Edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

class Graph
{
    int E;

public:
    vector<Edge> edge;
    void addEdge(int from, int to, int w);
    vector<Edge>::iterator begin()
    {
        return edge.begin();
    }
    vector<Edge>::iterator end()
    {
        return edge.end();
    }
};

void Graph::addEdge(int from, int to, int w)
{
    edge.push_back(Edge(from, to, w));
}

bool myCmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void Khruskal(vector<int> from_, vector<int> to, vector<int> weight, int V)
{
    int n = from_.size();
    Graph graph;
    for (int i = 0; i < n; i++)
    {
        graph.addEdge(from_[i] - 1, to[i] - 1, weight[i]);
    }
    sort(graph.begin(), graph.end(), myCmp);

    int parent[V];
    int rank[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int sum_ = 0;
    vector<Edge>::iterator i;
    for (i = graph.begin(); i != graph.end(); i++)
    {
        int rep_a = find(parent, i->from), rep_b = find(parent, i->to);
        if (rep_a == rep_b)
            continue;
        union_(parent, rank, rep_a, rep_b);
        sum_ += i->weight;
    }
    cout << sum_ << endl;
}

void solve()
{
    vector<int> from = {1, 4, 2, 3, 5};
    vector<int> to = {3, 3, 1, 2, 1};
    vector<int> weight = {6, 9, 6, 10, 3};
    Khruskal(from, to, weight, 5);
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