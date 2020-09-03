#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Binary Tree - max element
// max in left and max in right subtree, will give the maximum.
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

//with Recursion
int maximum(Node* root) {
    if ((!root->left) && (!root->right)) {
        return root->data;
    }

    int l = INT_MIN, r = INT_MIN;
    if (root->left)
        l = maximum(root->left);

    if (root->right)
        r = maximum(root->right);

    return max(l, max(r, root->data));
}
// maximum with recursion method 2:
int maximum2(Node* root) {
    int mx = INT_MIN;
    if (root != NULL) {
        int left = maximum2(root->left);
        int right = maximum2(root->right);
        mx = max(left, max(right, root->data));
    }
    return mx;
}

//can be done using inorder, preorder or levelorder
//here,level-order is done.
int maximum_withoutRecursion(Node *root) {
    int mx = INT_MIN;
    queue<Node*> Q;
    if (root)
        Q.push(root);
    while (!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();
        mx = max(temp->data, mx);

        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
    return mx;
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

    cout << maximum2(root) << endl;
    cout << maximum_withoutRecursion(root) << endl;
    return 0;
}