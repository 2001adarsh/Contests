#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Non-recursive traversals of binary tree.

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

void inorder(Node* root) {
    if (!root)
        return;
    stack<Node*> st;

    while (1) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            break;
        root = st.top();
        st.pop();
        cout << root->data << " ";
        root = root->right;
    }
}

void preorder(Node* root) {
    if (!root)
        return;
    stack<Node*> st;
    while (1) {
        while (root) {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            break;
        root = st.top();
        st.pop();
        root = root->right;
    }
}

//prev- tells the last visited node. if last visited node is root->left, then it is coming
//from left side, else it is coming from right side and we need to pop() the root.

void postorder(Node* root) {
    if (!root)
        return;

    Node* prev = NULL;
    stack<Node*> st;
    do
    {
        while (root) {
            st.push(root);
            root = root->left;
        }
        while (root == NULL and !st.empty()) {
            root = st.top();
            if (root->right == NULL || root->right == prev) {
                cout << root->data << " ";
                st.pop();
                prev = root;
                root = NULL;
            } else
                root = root->right;
        }

    } while (!st.empty());
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

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);

    return 0;
}