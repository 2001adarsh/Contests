#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Threaded Binary Tree.
//A binary tree is made threaded by making all right child pointers
//that would normally be NULL point to the inorder successor of the node
// (if it exists).

//when already given a threaded tree.
struct Threaded
{
    int data;
    Threaded *left, *right;
    bool rThread; //if true means that is connected to successor of inoder.(parent)
};

struct Threaded* leftMostChild(Threaded *root) {
    if (root == NULL)
        return NULL; // if no node.
    if (root->left == NULL)
        return root;
    return leftMostChild(root->left);
}

void inorder(Threaded *root) {
    Threaded *current = leftMostChild(root);
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->rThread) {
            current = current->right;
        } else {
            current = leftMostChild(current->right);
        }
    }

}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    return 0;
}