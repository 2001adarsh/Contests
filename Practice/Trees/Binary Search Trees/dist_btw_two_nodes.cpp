#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Maximum distance between two nodes:
class Node
{
public:
    int data;
    Node *left, *right;
};
Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//Find LCA and then distance from LCA to A, and LCA to B.
bool isPresent(Node* root, int data) {
    if (!root)
        return false;
    if (root->data == data)
        return true;
    if ((root->data > data) && isPresent(root->left, data))
        return true;
    else if ((root->data < data) && isPresent(root->right, data))
        return true;
    return false;
}

Node* LCA(Node* root, int A, int B) {
    if (!root)
        return NULL;
    if (root->data == A || root->data == B)
        return root;
    if ( (root->data > A && root->data < B) || (root->data < A && root->data > B))
        return root;
    if (root->data > A)
        root->left = LCA(root->left, A, B);
    else
        root->right = LCA(root->right, A, B);
    return root;
}

int toNode(Node *root, int A) {
    if (root->data == A)
        return 0;
    else if (root->data > A)
        return 1 + toNode(root->left, A);
    return 1 + toNode(root->right, A);
}

Node* insert(Node* root, int data) {
    if (!root) {
        root = newNode(data);
        return root;
    }
    if (root->data == data)
        return root;
    if (root->data > data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
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

    Node* root = NULL;
    root = insert(root, 3);
    insert(root, 7);
    insert(root, 5);
    insert(root, 4);
    insert(root, 2);

    inorder(root);
    cout << endl;

    //Find distance between 2 and 7:
    //check if they are present
    if (isPresent(root, 2) && isPresent(root, 7))
    {
        Node *l = LCA(root, 2, 3);
        cout << toNode(l, 2) + toNode(l, 3) + 1;
    }

    return 0;
}