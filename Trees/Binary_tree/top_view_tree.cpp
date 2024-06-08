#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

struct Node
{
    Node *left;
    Node *right;
    int root;
    Node(int a)
    {
        this->left = NULL;
        this->right = NULL;
        this->root = a;
    }
};

int max_right = -1, max_left = 1;

void top(Node *root, int pos, vector<pair<int, int>> &l)
{
    if (root == NULL)
    {
        return;
    }
    if (pos < max_left)
    {
        l.push_back({root->root, pos});
        max_left = pos;
    }
    if (pos > max_right && pos != 0)
    {
        l.push_back({root->root, pos});
        max_right = pos;
    }
    top(root->left, pos - 1, l);
    top(root->right, pos + 1, l);
}

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->right = new Node(60);

    vector<pair<int, int>> l;
    top(root, 0, l);
    sort(l.begin(), l.end(), myCmp);
    for (pair<int, int> i : l)
    {
        cout << i.first << " ";
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