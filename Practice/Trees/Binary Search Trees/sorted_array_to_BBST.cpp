#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//converting a sorted array to a Balanced BST.
class Node
{
public:
    int data;
    Node *left , *right;
};

Node* buildBST(int *arr, int s, int e) {
    if (s > e)
        return NULL;
    Node *node = new Node();
    if (s == e) {
        node->data = arr[s];
        node->left = node->right = NULL;
        return node;
    }
    int mid = s + (e - s) / 2;
    node->data = arr[mid];
    node->left = buildBST(arr, s, mid - 1);
    node->right = buildBST(arr, mid + 1, e);
    return node;
}

void inorder(Node *root) {
    if (!root)
        return ;
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

    int arr[] = {2 , 3 , 4 , 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    Node *root = buildBST(arr, 0, n - 1);
    inorder(root);
    return 0;
}