#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Finding Diameter of a binary tree, using only height function.
// Since diameter is max(sum of heights at each position).

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//diameter is passed by reference.
int height(Node* root, int &diameter) {
    if (root == NULL)
        return 0;
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);

    diameter = max(diameter, left + right + 1); //calculating diameter of a tree.
    return max(left , right) + 1; //returning simple height.
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //construct a tree.
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(6);

    int diameter = 0;
    height(root, diameter);
    cout << diameter;
    return 0;
}