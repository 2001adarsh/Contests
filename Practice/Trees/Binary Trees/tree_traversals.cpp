#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Binary Tree
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

// Recursive
void preorder(Node* root) {
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Non-recursive
void preorder_recursive(Node* root) {
    cout << "Preorder Recursive : ";
    stack<Node*> st;
    while (1) {
        while (root) {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        }
        if (st.empty()) //till the stack is not empty
            break;
        root = st.top();
        st.pop();
        root = root->right;
    }
    cout << endl;
}

//recursive
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorder_recursive(Node *root) {
    cout << "Inorder Recursive: ";
    stack<Node*> st;
    while (1) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            break;
        root = st.top();
        cout << root->data << " ";
        st.pop();
        root = root->right;
    }
    cout << endl;
}

//Post Order: LRD
void postorder(Node* root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postorder_recursive(Node* root) {
    stack<Node*> st;

}

//Level order
void level_order(Node* root) {
    if (!root) {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node *current = Q.front();
        Q.pop();
        cout << current->data << " ";

        if (current->left)
            Q.push(current->left);

        if (current->right)
            Q.push(current->right);
    }
    cout << endl;
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

    preorder(root);
    cout << endl;
    preorder_recursive(root);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    inorder_recursive(root);

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    postorder_recursive(root);

    cout << "Level Order: ";
    level_order(root);

    return 0;
}