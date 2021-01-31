#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Given a BST and a key, find the element in BST which is closest to the
// given key.

class BST
{
public:
    int data;
    BST *left, *right;
    BST(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
    ~BST();
};

//worst case O(N) else, O(logN) for average case.
int closest(BST* root, int key) {
    if (!root) return inf; // when no node found.
    if (root->data == key) return root->data;
    int res = root->data;
    if (key < root->data) {
        int l = closest(root->left, key);
        if (abs(key - res) > abs(key - l))
            res = l;
    }
    else if (key > root->data) {
        int r = closest(root->right, key);
        if (abs(key - res) > abs(key - r))
            res = r;
    }

    return res;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BST* root = new BST(6);
    root->left = new BST(4);
    root->right = new BST(9);
    root->left->left = new BST(2);
    root->left->right = new BST(5);
    root->right->left = new BST(7);
    root->right->left->right = new BST(8);

    cout << closest(root, -1);

    return 0;
}