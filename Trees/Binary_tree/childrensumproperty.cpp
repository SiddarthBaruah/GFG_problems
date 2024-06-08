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

bool isCsum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;
    return root->key == sum && isCsum(root->left) && isCsum(root->right);
}

void solve(Node *root)
{
    cout << isCsum(root);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(10);
    root->right->right = new Node(20);
    root->right->left->right = new Node(10);
    while (t--)
    {
        solve(root);
    }
    return 0;
}