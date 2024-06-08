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
// int size_of_binarytree(Node *root)
// {
//     if (root == NULL)
//         return 0;
//     queue<Node *> q1, q2;
//     q1.push(root);
//     while (q1.empty() == false)
//     {
//         Node *curr = q1.front();
//         q2.push(curr);
//         q1.pop();
//         if (curr->left != NULL)
//             q1.push(curr->left);
//         if (curr->right != NULL)
//             q1.push(curr->right);
//     }
//     return q2.size();
// } //This one was my implementation

int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    return getSize(root->left) + getSize(root->right) + 1;
}

void solve(Node *root)
{
    cout << getSize(root) << endl;
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