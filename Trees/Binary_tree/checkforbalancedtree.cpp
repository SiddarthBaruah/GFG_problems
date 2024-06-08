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
// naive solution with Big(O)
//  int height(Node *root, int k)
//  {
//      if (root == NULL)
//          return k;
//      return max(height(root->left, k + 1), height(root->right, k + 1));
//  }

// bool checkBalanced(Node *root)
// {
//     if (root == NULL)
//         return true;
//     return (abs(height(root->left, 0) - height(root->right, 0)) <= 1) && checkBalanced(root->left) && checkBalanced(root->right);
// }

// int checkBalanced(Node *root, int k)
// {

// }

int checkBalace(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = checkBalace(root->left);
    if (lh == -1)
        return -1;
    int rh = checkBalace(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}
void solve(Node *root)
{
    cout << checkBalace(root);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    Node *root = new Node(30);
    root->left = new Node(40);
    root->left->left = new Node(50);
    root->left->right = new Node(70);
    root->left->right->left = new Node(20);
    root->left->right->right = new Node(10);
    root->right = new Node(80);
    root->right->left = new Node(5);

    // root->right->left->right = new Node(10);
    while (t--)
    {
        solve(root);
    }
    return 0;
}