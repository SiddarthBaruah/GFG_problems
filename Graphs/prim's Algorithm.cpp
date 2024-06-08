#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

/*
So, Basically prim's algorithm is a greedy algo,
where two sets of graphs are kept, mset and !mset and until and unless
all elements in !mset becomes empty, it keeps on going.

so, we see the graphs that are not in the mset and, see the edges that are comming out
of the mset. And pick the minimum one
*/

int Prims_Algo(vector<int> Graph[], int V)
{
    int key[V], res = 0;         // ths key will help us to get the minimum edge connected to
    fill(key, key + V, INT_MAX); // ith block
    key[0] = 0;                  // making the distance to source block as zero
    bool mSet[V] = {false};      // this is to track which block is at mset now
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        mSet[u] = true; // this is where we selected the node is in the mset
        res = res + key[u];
        for (int v = 0; v < V; v++)
        {
            if (Graph[u][v] != 0 && !mSet[v])
                key[v] = min(key[v], Graph[u][v]);
        }
    }
    return res;
}

void solve(vector<int> Graph[], int V)
{
    Prims_Algo(Graph, V);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 4;
    vector<int> graph[V];
    graph[0] = {0, 5, 8, 0};
    graph[1] = {5, 0, 10, 15};
    graph[2] = {8, 10, 0, 20};
    graph[3] = {0, 15, 20, 0};
    while (t--)
    {
        solve(graph, V);
    }
    return 0;
}

int prim_prac(vector<int> graph[], int V)
{
    int key[V];
    fill(key, key + V, INT_MAX);
    bool mSet[V] = {false};
    key[0] = 0;
    int res = 0;
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        mSet[u] = true; // at this point if we want to make some changes we can make.
        res += key[u];
        for (int v = 0; v < V; v++)
        {
            if (!mSet[v] && graph[u][v] != 0)
                key[v] = min(key[v], graph[u][v]);
        }
    }
    return res;
}