#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// sorted doubly linked list to Balanced BST.
//O(N) -> as we are just traversing the linked list and operating divide and conquer
//once the process.

//Node for singly linked list.
class Node
{
public:
    int data;
    Node *next, *prev;
};

//Node for tree.
class tree
{
public:
    int data;
    tree *left, *right;
};
void push(Node **head, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (*head == NULL) {
        (*head) = temp;
        return;
    }
    //push in starting.
    temp->next = (*head);
    (*head)->prev = temp;
    *head = temp;
}

tree* convert(Node **head, int start, int end) {
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    //recursing for left child.
    tree* leftchild = convert(head, start, mid - 1);

    //creating parent node
    tree* parent = new tree();
    parent->data = (*head)->data;
    //update list when made parent.
    (*head) = (*head)->next;

    parent->left = leftchild;
    //now recurse for right child.
    parent->right = convert(head, mid + 1, end);
    return parent;
}

void inorder(tree *root) {
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

    //inputing sorted linked list.
    Node *head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    int n = 6; //n is length of linked list. if not know, traverse in o(n)

    //covert to tree.
    tree* node = convert(&head, 0, n - 1);
    inorder(node);
    return 0;
}