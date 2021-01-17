#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Converting Sorted Doubly Linked List to Balanced BST.

class Node
{
public:
    int data;
    Node *prev, *next;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

Node* middle(Node* head) {
    Node *temp = head, *fast = head;
    while (fast != NULL and fast->next != NULL) {
        temp = temp->next;
        fast = fast->next->next;
    }
    return temp;
}

//finding middle element and the building the tree, on left and right.
//similar to segment tree buildtree. just that we need to traverse
//midway to find the middle element, which will increase the complexity.
Node* buildTree(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    //these nodes are used to divide the linked list into two parts,
    //by putting null at last.
    Node *mid = middle(head);
    Node *p = head;
    while (p->next != mid)
        p = p->next;
    p->next = NULL; //making left portion separate from others.
    Node *tempr = mid->next; //start of right array.
    mid->next = NULL;
    mid->prev = buildTree(head);

    if (tempr != NULL)
        mid->next = buildTree(tempr);
    return mid;
}

void inorder(Node* tree) {
    if (tree == NULL)
        return;
    inorder(tree->prev);
    cout << tree->data << " ";
    inorder(tree->next);
}

void push(Node **head, int data) {
    Node* temp = newNode(data);
    if (!(*head)) {
        (*head) = temp;
        return;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //creating a Doubly Linked List --> sorted.
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    Node* tree = buildTree(head);
    inorder(tree);

    return 0;
}