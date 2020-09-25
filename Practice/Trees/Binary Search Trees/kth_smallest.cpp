#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

// Kth smallest element

class Node
{
public:
    int data;
    Node *left, *right;
};
Node* newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//can also use Node to return, every thing same just NULL will replace 0.
int value(Node *root, int &k) {
    if (!root)
        return 0;
    int l = value(root->left, k);
    if (l != 0)
        return l;
    k--;
    if (k == 0)
        return root->data;
    return value(root->right, k);
}

void inorder(Node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //BST
    Node *root = newNode(4);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right = newNode(6);
    root->right->left = newNode(5);

    inorder(root);

    int k = 3;
    cout << endl <<  value(root, k );
    return 0;
}