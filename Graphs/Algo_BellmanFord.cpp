// this algo is used to  find mininmum distance evenif there is a negative edge.
// also helps to find if there is a negative cyclic edge

#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

// interesting data structure

struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edge;
};

// this is a function that returns type struct graph, wierdd
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->edge = new Edge[E];
    return graph;
}

void BellmanFord(struct Graph *graph, int s)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    fill(dist, dist + V, INT_MAX);
    dist[s] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        for (int i = 0; i < E; i++)
        {
            int u = graph->edge[i].src;
            int v = graph->edge[i].dest;
            int weight = graph->edge[i].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout << "Negative wieght cycle found" << endl;
        return;
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d ", dist[i]);
    }
    return;
}

void solve(struct Graph *graph, int s)
{
    BellmanFord(graph, s);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    /////for some reason print is not working after this line, god knows why
    int V = 4;
    int E = 5;
    struct Graph *graph = createGraph(V, E);

    // add edge 0-1 (or A-B)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;

    // add edge 0-2 (or A-C)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = -3;

    // add edge 1-3 (or B-D)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 2-3 (or C-D)
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 3;

    while (t--)
    {
        solve(graph, 0);
    }
    return 0;
}