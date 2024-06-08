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

int height_tree(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(height_tree(root->left), height_tree(root->right)) + 1;
}

void solve(Node *root)
{
    int height = height_tree(root);
    cout << "Height of the tree is: " << height;
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