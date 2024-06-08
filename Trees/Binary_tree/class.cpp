/*Binary Tree
    has atmost two children
    for leafs the left and right child are always none*/

#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    cout << root->key << endl;
    return 0;
}
