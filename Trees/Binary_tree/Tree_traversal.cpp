/*
    Time com: O(n)
    Space com: O(H)
*/
/*
    Three ways
    Inorder
    Preorder
    PostOrder
*/

/*
    Inorder: (Left Root Right) 40 20 70 50 80 10 30 60
    Preorder: (Root Left Right) 10 20 40 50 70 80 30 60
    PostOrder: (Left Right Root) 40 70 80 50 20 60 30 10
*/
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

// lets make a global tree

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void solve(Node *root)
{
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
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

// inorder implementation