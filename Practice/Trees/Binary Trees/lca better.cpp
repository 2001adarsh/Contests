#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//LCA of two nodes.
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

//will return the data of LCA of two nodes.
int LCA(Node* root, int& A, int& B) {
    if (!root)
        return 0;
    if (root->data == A || root->data == B)
        return root->data;

    int left = LCA(root->left, A, B);
    int right = LCA(root->right, A, B);

    //this means that both elements are present on either side of root.
    //hence lca.
    if (left && right)
        return root->data;
    /*
    // this means in only one side both elements are present, hence find lca in that direction.
        return (left) ? LCA(root->left, A, B) : LCA(root->right, A, B);*/
    //we can also optimise this approach, as that result will already be stored in left.
    return (left) ? left : right;

}

bool search(Node* root, int d) {
    if (!root)
        return false;
    if (root->data == d)
        return true;
    return (search(root->left, d) or search(root->right, d));
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

    //for finding LCA, we have to first check if both nodes are in tree or not.
    if (search(root, 3) && search(root, 4)) {
        int A = 3, B = 4;
        cout << LCA(root, A, B);
    }
    return 0;
}