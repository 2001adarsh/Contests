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

//Number of Leaves in Tree
int numOfLeaves(Node* root) {
    if (!root)
        return 0;
    int cnt = 0;
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* temp = Q.front();
        if (!temp->left && !temp->right) {
            cnt++;
        }
        Q.pop();
        if (temp->left) Q.push(temp->left);
        if (temp->right) Q.push(temp->right);
    }
    return cnt;
}

//Number of Full Nodes in Tree
int numFullNodes(Node* root) {
    if (!root)
        return 0;
    int cnt = 0;
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* temp = Q.front();
        if (temp->left && temp->right) { //It has 2 childs.
            cnt++;
        }
        Q.pop();
        if (temp->left) Q.push(temp->left);
        if (temp->right) Q.push(temp->right);
    }
    return cnt;
}

//Number of Half Nodes in Tree
int numHalfNodes(Node* root) {
    if (!root)
        return 0;
    int cnt = 0;
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* temp = Q.front();
        if ((!temp->left && temp->right) || (temp->left && !temp->right)) {
            cnt++;      //It has 1 childs.
        }
        Q.pop();
        if (temp->left) Q.push(temp->left);
        if (temp->right) Q.push(temp->right);
    }
    return cnt;
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
    //root->right->right = newNode(8);

    cout << "No. of Leaves: " << numOfLeaves(root) << endl;
    cout << "No. of full nodes: " << numFullNodes(root) << endl;
    cout << "No. of half nodes: " << numHalfNodes(root) << endl;
    return 0;
}