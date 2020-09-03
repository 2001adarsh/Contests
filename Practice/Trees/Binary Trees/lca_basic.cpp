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

bool inorder(Node* root, vector<int>& path, int val) {
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == val)
        return true;
    if (inorder(root->left, path, val) || inorder(root->right, path, val))
        return true;
    path.pop_back(); //backtracking.
    return false;
}

int lca(Node* root, int x1, int x2) {
    vector<int> path1, path2;
    if (!(inorder(root, path1, x1)) || !(inorder(root, path2, x2)))
        return -1;
    int ans = 0;
    for (auto i : path1)
        cout << i << " ";
    cout << endl;
    for (auto i : path2)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] == path2[i])
            ans = path1[i];
        else break;
    }
    return ans;
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

    cout << lca(root, 4, 7);

    return 0;
}