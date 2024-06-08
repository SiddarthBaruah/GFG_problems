#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

void DFS_travel(vector<vector<int>> graph, int V, bool visited[], int s, queue<int> &st)
{
    visited[s] = true;
    for (int v : graph[s])
    {
        if (v != 0 && !visited[v])
            DFS_travel(graph, V, visited, v, st);
    }
    st.push(s);
}

queue<int> Preproscessing(vector<vector<int>> graph, int V)
{
    bool visited[V] = {false};
    queue<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS_travel(graph, V, visited, i, st);
    }
    return st;
}

void DFS_print(vector<vector<int>> graph, int V, bool visited[], int s)
{
    visited[s] = true;
    for (int v = 0; v < V; v++)
    {
        if (graph[v][s] != 0 && !visited[v])
            DFS_print(graph, V, visited, v);
    }
    cout << s << " ";
}

void Kosaraju(vector<vector<int>> graph, int V)
{
    queue<int> data = Preproscessing(graph, V);
    bool visited[V] = {false};
    while (!data.empty())
    {
        int u = data.front();
        data.pop();
        if (!visited[u])
        {
            DFS_print(graph, V, visited, u);
            cout << endl;
        }
    }
}

void solve(vector<vector<int>> graph, int V)
{
    Kosaraju(graph, V);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    int V = 5;
    vector<vector<int>> graph;
    graph.push_back({0, 1, 0, 1, 0});
    graph.push_back({0, 0, 1, 0, 0});
    graph.push_back({1, 0, 0, 0, 0});
    graph.push_back({0, 0, 0, 0, 1});
    graph.push_back({0, 0, 0, 0, 0});
    while (t--)
    {
        solve(graph, V);
    }
    return 0;
}