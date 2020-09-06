#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"

// Inorder Tree Traversal without recursion and without stack!

/*
1. Initialize current as root
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
*/
class Node
{
public:
    int data;
    Node* left, *right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = data;
    return node;
}

void inorder(Node* root) {
    Node* cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) { //If left is null
            cout << cur->data << " ";
            cur = cur->right;
        } else { // If it has left child

            Node* rightMost = cur->left;

            while (rightMost->right != NULL && rightMost->right != cur)
                rightMost = rightMost->right;

            if (rightMost->right == NULL) {
                rightMost->right = cur;
                cur = cur->left;
            }
            else {
                rightMost->right = NULL; //To make it
                cout << cur->data << " ";
                cur = cur->right;
            }
        }
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

    inorder(root);
    return 0;
}