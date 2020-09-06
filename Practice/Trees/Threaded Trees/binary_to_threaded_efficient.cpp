#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"

//Making of Threaded trees.

class Node
{
public:
    int data;
    Node* left, *right;
    bool isThreaded;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = data;
    node->isThreaded = false;
    return node;
}

//Efficient way of threading.
Node* createThreaded(Node* root) {
    if (!root)
        return NULL;
    if ((!root->left) && (!root->right))
        return root;

    if (root->left) {
        Node* l = createThreaded(root->left);
        l->right = root;
        l->isThreaded = true;
    }
    if (root->right == NULL)
        return root;
    return createThreaded(root->right);
}

//printing the node:
Node* leftMost(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
void inorder(Node* root) {
    if (!root)
        return;
    Node* cur = leftMost(root);
    while (cur != NULL) {
        cout << cur->data << " ";
        if (cur->isThreaded)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    createThreaded(root);
    inorder(root);
    return 0;
}