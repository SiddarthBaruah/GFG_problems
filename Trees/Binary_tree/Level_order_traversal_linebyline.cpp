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

void print_level_order(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

void solve(Node *root)
{
    print_level_order(root);
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