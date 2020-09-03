#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Print all paths from Root to leaf

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

void printPath(int *path, int len) {
    for (int i = 0; i < len; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return;
}

void allRoutes(Node* root, int *path, int len) {
    if (!root)
        return;
    if ((!root->left) && (!root->right)) {
        path[len] = root->data;
        len++;
        printPath(path, len);
        return;
    }
    path[len] = root->data;
    len++;
    allRoutes(root->left, path, len);
    allRoutes(root->right, path, len);
    return;
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

    int *path = new int[1000];
    allRoutes(root, path, 0);

    return 0;
}