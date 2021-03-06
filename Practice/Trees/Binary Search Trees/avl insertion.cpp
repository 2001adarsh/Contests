#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// AVL Tree. - https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
class Node
{
public:
    int data;
    int height; // taking this for easier evaluation.
    Node *left, *right;
    Node();
    Node(int data) {
        this->data = data;
        this->height = 0;
        this->left = this->right = NULL;
    }
    ~Node();
};

//Height in O(1) as we are storing it at every point, and changing after each insertion.
int Height(Node* root) {
    if (!root)
        return -1;
    return root->height;
}

// single rotate left.
Node* LL(Node* X) {
    Node* W = X->left;
    X->left = W->right;
    W->right = X;
    //fixing height again.
    X->height = max(Height(X->left), Height(X->right)) + 1;
    W->height = max(Height(W->left), X->height) + 1;
    return W;
}

// single rotate right.
Node* RR(Node* X) {
    Node* W = X->right;
    X->right = W->left;
    W->left = X;
    //fixing height again.
    X->height = max(Height(X->left), Height(X->right)) + 1;
    W->height = max(X->height, Height(W->right)) + 1;
    return W;
}

// double rotate with left.
Node* LR(Node* X) {
    X->left = RR(X->left);
    return LL(X);
}

// double rotate with right.
Node* RL(Node* X) {
    X->right = LL(X->right);
    return RR(X);
}


//insertion as BST. But after every insertion, make sure that height difference, between
//every node is less than or equal to 1.
//Since, we are doing this operation after every insertion, the max H diff will be 2.
Node* insertion(Node* root, int data) {
    if (!root) {
        Node* temp = new Node(data);
        return temp;
    }
    else if (data < root->data) {
        root->left = insertion(root->left, data);
        if (Height(root->left) - Height(root->right) == 2) {
            if (data < root->left->data)
                root = LL(root);
            else
                root = LR(root);
        }
    }
    else if (data > root->data) {
        root->right = insertion(root->right, data);
        if (Height(root->right) - Height(root->left) == 2) {
            if (data > root->right->data)
                root = RR(root);
            else
                root = RL(root);
        }
    }
    root->height = max(Height(root->left), Height(root->right)) + 1;
    return root;
}

//printing the data with height also.
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " H-" << root->height << endl;
    inorder(root->right);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node* root = insertion(NULL, 4);
    root = insertion(root, 2);
    root = insertion(root, 7);
    root = insertion(root, 6);
    root = insertion(root, 8);
    root = insertion(root, 5);

    inorder(root);

    return 0;
}

/*
4 types of violations:
1. Insertion into the left subtree of the left child of X. LL
2. Insertion into the right subtree of the left child of X. LR
3. Insertion into the left subtree of the right child of X. RL
4. Insertion into the right subtree of the right child of X. RR

*/