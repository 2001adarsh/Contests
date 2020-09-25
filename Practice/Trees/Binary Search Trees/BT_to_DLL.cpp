#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Binary Tree to Doubly Linked List

class Node
{
public:
    int data;
    Node *left , *right;
};
Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// Method 1: Recursively point the middle element to rightmost in left and
// leftmost in right subtree
Node* convertToDLL(Node* root) {
    if (!root)
        return root;
    if (root->left) {
        Node* temp = convertToDLL(root->left);
        //finding inorder predecessor
        while (temp->right != NULL)
            temp = temp->right;
        temp->right = root;
        root->left = temp;
    }
    if (root->right) {
        Node* temp = convertToDLL(root->right);
        while (temp->left)
            temp = temp->left;
        root->right = temp;
        temp->left = root;
    }
    return root;
}

void printList(Node *head) {
    if (!head)
        return;
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

//Method 2:
// reverse inorder traversal and insertion at head.
void BTtoDLL(Node *root, Node **head) {
    if (!root)
        return;
    BTtoDLL(root->right, head);

    //insertion at begining.
    root->right = *head;
    if (*head)
        (*head)->left = root;
    *head = root;

    BTtoDLL(root->left, head);
}


void inorder(Node *root) {
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

    // Let us create the tree shown in above diagram
    Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    inorder(root);
    cout << endl;

    /*  Method -1
        Node *head = convertToDLL(root);
        while (head->left != NULL)
            head = head->left;

        printList(head);
    */

    //Method -2
    Node *head = NULL;
    BTtoDLL(root, &head);
    printList(head);

    return 0;
}