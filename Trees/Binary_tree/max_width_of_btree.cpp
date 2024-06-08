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

int max_width(Node *root)
{

    if (root == NULL)
        return 0;
    queue<Node *> q;
    list<Node *> l;
    q.push(root);
    l.push_back(root);
    q.push(NULL);
    int width = (int)l.size();
    l.clear();
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            width = max((int)l.size(), width);
            l.clear();
            q.push(NULL);
            continue;
        }
        if (curr->left != NULL)
        {
            q.push(curr->left);
            l.push_back(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
            l.push_back(curr->right);
        }
    }
    return width;
}

void solve(Node *root)
{
    cout << max_width(root);
}

signed main()
{
    fastio;
    int t;
    t = 1;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->right = new Node(60);
    while (t--)
    {
        solve(root);
    }
    return 0;
}