#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Tell if any path with the given sum is present or not.

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

bool pathWithSum(Node *root, int *path, int len, int sum, int getTill) {
    if (sum == getTill) {
        printPath(path, len);
        return true;
    }
    if (!root)
        return false;
    getTill += root->data;
    path[len] = root->data;
    len++;
    if (pathWithSum(root->left, path, len, sum, getTill) || pathWithSum(root->right, path, len, sum, getTill))
        return true;
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

    int *path = new int[1000];
    int sum = 16;
    int gotTill = 0;
    cout << pathWithSum(root, path, 0, sum, gotTill);

    return 0;
}