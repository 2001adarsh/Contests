#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Vertical Sum of a Binary Tree.
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

map<int, int> mp;
void vertical(Node* root, int col) {
    if (!root)
        return;
    mp[col] += root->data;
    vertical(root->left, col - 1);
    vertical(root->right, col + 1);
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

    vertical(root, 0);
    for (auto p : mp) {
        cout << p.second << " ";
    }


    return 0;
}