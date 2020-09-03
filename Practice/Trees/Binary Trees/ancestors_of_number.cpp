#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Mirror Image

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool printAnces(Node* root, int data) {
    if (!root)
        return false;
    if (root->data == data || printAnces(root->left, data) || printAnces(root->right, data)) {
        cout << root->data << " ";
        return true;
    }
    return false;
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(5);
    root->left->right = newNode(6);
    root->right = newNode(8);
    root->right->left = newNode(7);

    printAnces(root, 7);

    return 0;
}