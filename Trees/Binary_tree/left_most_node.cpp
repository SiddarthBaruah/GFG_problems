#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int max_level = 0;

void get_left(Node *root, int levels)
{
    if (root == NULL)
        return;
    if (max_level < levels)
    {
        cout << root->key << " ";
        max_level = levels;
    }
    get_left(root->right, levels + 1);
    get_left(root->left, levels + 1);
}

void solve(Node *root)
{

    get_left(root, 1);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->right = new Node(8);
    while (t--)
    {
        solve(root);
    }
    return 0;
}