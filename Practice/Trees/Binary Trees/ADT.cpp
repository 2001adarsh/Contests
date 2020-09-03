#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Binary Tree - find element
class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Using recursion->  Returns the level at which the element is found.
int findElement(Node* root, int data) {
    if (!root)
        return -1;
    if (root->data == data)
        return 0;
    //recursive case
    int left = findElement(root->left, data);
    if (left != -1)
        return left + 1;
    int right = findElement(root->right, data);
    if (right != -1)
        return right + 1;
    return -1;
}

//returns no. of node in a tree.
int sizeTree(Node* root) {
    if (!root)
        return 0;
    return sizeTree(root->left) + sizeTree(root->right) + 1;
    // size of left subtree + size of right subtree + 1(for current node inclusion)
}

//for binary trees - height of tree = depth of tree. but may be diffrent for a node.
int height(Node* root) {
    if (!root)
        return 0;
    return max(height(root->left) , height(root->right)) + 1;
}

//Delete whole tree -> we can delete the childs first and then the root node.
//Hence we will use postOrder as it will not take any extra space.
void deleteTree(Node *root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout << "deleting node: " << root -> data << endl;
    delete root;
}

//returns number of leaves in a tree.
int noOfLeaves(Node* root) {
    if (!root)
        return 0;
    if ((!root->left) && (!root->right))
        return 1;
    return noOfLeaves(root->left) + noOfLeaves(root->right);
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
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(8);

    cout << height(root) << endl;

    cout << findElement(root, 7) << endl;
    int size =  sizeTree(root);
    cout << size << endl;

    cout << "No. of Leaves:" << noOfLeaves(root) << endl;

    deleteTree(root);
    root = NULL; //to not to generate garbage value, we accesed later.

    return 0;
}