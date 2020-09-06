#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Binary Tree - Diameter.
// It is the longest path between any two nodes, of a tree.
// This may be possible that the path may not pass through the root node.
// They can either be inside any left subtree or right subtree.
class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Efficient Method -> O(n)
// Take a global variable, and find max of left +right+1 at each node, print the max.

//In-Efficient Method -> O(n*height)
int height(Node* root) {
    if (!root)
        return 0;
    return max(height(root->left) , height(root->right)) + 1;
}
int Diameter(Node*root) {
    if (!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int l = Diameter(root->left);
    int r = Diameter(root->right);
    return max(leftHeight + rightHeight + 1, max(l, r));
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
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(8);

    cout << Diameter(root) << endl;

    return 0;
}