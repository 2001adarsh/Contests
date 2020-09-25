#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"

class BST
{
public:
    int data;
    BST *left, *right;
};

BST* insert(BST *root, int data) {
    if (root == NULL) {             //Not found, then insert.
        root = new BST();           //--> creation of node is must.
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if (root->data == data) //Already there in the tree, so skip.
        return root;

    if (root->data > data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

BST* LeftMax(BST* root) {
    while (!root && root->right != NULL)
        root = root->right;
    return root;
}

//Deletes an element
BST *Delete(BST *root, int data) {
    if (!root)
        return root;
    if (root->data == data) { //Found
        if (root->right && root->left) { //If has both left and right node.
            BST *node = LeftMax(root->left);
            root->data = node->data;
            root->left = Delete(root->left, node->data);
        } else { //Either 1 or 0 childs.
            BST *temp = NULL;
            if (root->left == NULL)
                temp = root->right;
            else if (root->right == NULL)
                temp = root->left;
            delete root;
            return temp;
        }
    }
    if (root->data > data)
        root->left = Delete(root->left, data);
    else
        root->right = Delete(root->right, data);
    return root;
}

//returns true if element present.
bool find(BST *root, int data) {
    if (!root)
        return false;
    if (root->data == data)
        return true;
    if (root->data > data)
        return find(root->left, data);
    else return find(root->right, data);
    return false; //Never reachable sentence.
}

//returns minimum element. LLONG_MIN if no root present
int minimum(BST *root) {
    if (!root)
        return LLONG_MIN;
    if (root->left)
        return minimum(root->left);
    return root->data;
}

//returns maximum element. LLONG_MAX if no root present
int maximum(BST* root) {
    if (!root)
        return LLONG_MAX;
    if (root->right)
        return maximum(root->right);
    return root->data;
}

//Inorder of BST -> sorted values:
void inorder(BST* root) {
    if (!root)
        return;
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

    BST *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    Delete(root, 3);
    inorder(root);
    cout << endl;

    if (find(root, 2))
        cout << "Found" << endl;
    else cout << "Not Found" << endl;

    cout << minimum(root) << endl;
    cout << maximum(root) << endl;

    return 0;
}