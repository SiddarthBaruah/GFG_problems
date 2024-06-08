/*
Problem with arrays:
    1. even for dynamicaly if the array is full then in will move all the elements to a new array of double the size,
    thus making it theta of n time complexity
    2.in case of entering a new element in the between, it again becomes a pain in ass, since we need to allocate all the
    elements after that position into  new postition.
    3. same with case for deletion
    4. queue and dequee with array is real complex
    5. in implementation:
        i. RobinHood schedulling is complex
        ii.


*/
/*
Application of linked List:
    1.Worst case insertion O(1)
    2.Worst case deletion O(1)
    3.Insertion and deletion easy if we have reference to the previos node. Need doubly liinked list
    4.Round robin implementation
    5.Merging two sorted linked list
    6.Implementation of simpe memory management system where we need to link free blocks
    7.Easier implementation of Queue and Deque

Problem:
    1.Random access data is not there

*/

// simple implementation
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
    Node *next;
    Node(int k)
    {
        key = k;
        next = NULL;
    }
};

void solve()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    // initializing
    Node *curr = head;
    cout << curr->key << endl;
    while (curr->next != NULL)
    {
        curr = curr->next;
        cout << curr->key << endl;
    }
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}