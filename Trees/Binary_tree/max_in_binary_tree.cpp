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
    int key;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int max_element(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(max_element(root->left), max_element(root->right)));
}

void solve(Node *root)
{
    cout << max_element(root) << endl;
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    Node *root = new Node(-100);
    root->left = new Node(-10);
    root->right = new Node(-30);
    root->right->left = new Node(-40);
    root->right->right = new Node(-50);
    while (t--)
    {
        solve(root);
    }
    return 0;
}