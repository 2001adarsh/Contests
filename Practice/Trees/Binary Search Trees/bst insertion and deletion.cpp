#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
//BST insertion and deletion.

class Node
{
public:
    int data;
    Node *left, *right;
    Node();
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
    ~Node();
};

Node* insert(Node* root, int data) {
    if (!root)
        return new Node(data);
    else if ( data < root->data)
        root->left = insert(root->left, data);
    else if ( data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* rightmost(Node* root) {
    if (!root)
        return root;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* deletion(Node* root, int data) {
    if (!root)
        return root;
    else if (data < root->data)
        root->left = deletion(root->left, data);
    else if (data > root->data)
        root->right = deletion(root->right, data);
    else {
        //this position is to be deleted.
        //case 1: if leaf.
        if (root->left == NULL and root->right == NULL)
            return NULL;
        //case 2: if one child
        if (root->left == NULL and root->right != NULL)
            return root->right;
        else if (root->left != NULL and root->right == NULL)
            return root->left;
        //case 3: has both childs.
        else {
            //swap the current data with rightmost child of left child.
            Node* temp = rightmost(root->left);
            root->data = temp->data;
            //now delete that rightmost child.
            root->left = deletion(root->left, root->data);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
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
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 1);

    deletion(root, 4);
    inorder(root);

    return 0;
}