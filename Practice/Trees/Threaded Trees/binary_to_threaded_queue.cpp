#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
// Converting a binary tree to a threaded tree.

struct Threaded {
    int data;
    Threaded *left, *right;
    bool isThreaded; // points if it is the last right element,which is conected to the parent.
};

Threaded* newNode(int data) {
    Threaded *node = new Threaded;
    node->data = data;
    node->left = node->right = NULL;
    node->isThreaded = false;
    return node;
}
//For converting a tree into a threaded tree, we will first store the
//inorder of that element in a Queue, and then check if it is the last
//right node then, link it with the first element of the queue.
void convert(Threaded *root, queue<Threaded*> *Q) {
    if (!root)
        return;
    if (root->left)
        convert(root->left, Q);
    Q->pop();
    if (root->right)
        convert(root->right, Q);
    else {
        root->right = Q->front();
        root->isThreaded = true;
    }
}

void fillQueue(Threaded *root, queue<Threaded*> *Q) {
    if (!root)
        return;
    if (root->left)
        fillQueue(root->left, Q);
    Q->push(root); //Since it is a pointer, also (*Q).push(root);
    if (root->right)
        fillQueue(root->right, Q);
}

void convertTree(Threaded *root) {
    queue<Threaded*> Q;
    fillQueue(root, &Q);
    convert(root, &Q);
}

//Calculating inorder with the help of leftmost Node;
Threaded *leftmost(Threaded *root) {
    while (root != NULL && (root->left != NULL)) {
        root = root->left;
    }
    return root;
}

void inorder(Threaded *root) {
    if (!root)
        return;
    Threaded *cur = leftmost(root);
    while (cur != NULL) {
        cout << cur->data << " ";
        if (cur->isThreaded)
            cur = cur->right;
        else
            cur = leftmost(cur->right);
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Threaded *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    convertTree(root);
    inorder(root);
    return 0;
}