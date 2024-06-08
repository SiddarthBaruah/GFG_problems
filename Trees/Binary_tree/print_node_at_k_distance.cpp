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

void print_k_node(Node *root, int current)
{
    if (root == NULL)
    {
        return;
    }
    else if (current == 0)
    {
        cout << root->key << " ";
    }
    else
    {
        print_k_node(root->left, current - 1);
        print_k_node(root->right, current - 1);
    }
}

void solve(Node *root)
{
    print_k_node(root, 2);
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
    while (t--)
    {
        solve(root);
    }
    return 0;
}