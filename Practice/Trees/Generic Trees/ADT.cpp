#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

class Tree
{
public:
    int data;
    Tree* fchild; //first child.
    Tree* nextSib; // next sibling.
};

Tree* newNode(int data) {
    Tree* node = new Tree();
    node->data = data;
    node->fchild = NULL;
    node->nextSib = NULL;
    return node;
}

// similar to binary trees, just instead of having left and right pointers,
// here we have first child and next siblings.
int FindSum(Tree* root) {
    if (!root)
        return 0;
    return root->data + FindSum(root->fchild) + FindSum(root->nextSib);
}

//counting number of siblings for the any node.
int Csiblings(Tree* node) {
    if (!node)
        return 0;
    return 1 + Csiblings(node->nextSib);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Tree* root = newNode(1);
    root->fchild = newNode(2);
    root->fchild->nextSib = newNode(3); // child of 1
    root->fchild->nextSib->nextSib = newNode(4); //child of 1
    root->fchild->nextSib->nextSib->fchild = newNode(5); //child of 4.
    root->fchild->nextSib->fchild = newNode(6); //child of 3.

    cout << FindSum(root);

    cout << endl << Csiblings(root->fchild);



    return 0;
}