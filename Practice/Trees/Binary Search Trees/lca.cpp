#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
//BST LCA
class Node
{
public:
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//Assuming both the data A and B are present in the BST.
int LCA(Node* root, int A, int B) {
    if (!root)
        return -1;
    if (root->data > A && root->data < B) {
        return root->data;
    }
    if (root->data == A)
        return A;
    else if (root->data == B)
        return B;

    if (root->data > A)
        return LCA(root->left, A, B);
    else
        return LCA(root->right, A, B);
    return -1; //not anywhere
}

Node* insert(Node *root, int data) {
    if (!root) { //not found.
        root = newNode(data);
        return root;
    }
    if (root->data == data) //if data already, then skip
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
    cout << endl << LCA(root, 7, 4) << endl;

    return 0;
}