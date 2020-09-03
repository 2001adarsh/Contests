#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define inf 1000000000000000000ll

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data) {
    Node* node = new Node();
    if (!node) {
        //memory error
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int maxSumLevel(Node* root) {
    if (!root)
        return -1;
    int mx = INT_MIN, sum = 0;
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();
        if (!temp) {
            //NULL found, change level
            mx = max(mx, sum);
            sum = 0;
            if (!Q.empty())
                Q.push(NULL);
        } else {
            sum += temp->data;
            if (temp->left) Q.push(temp->left);
            if (temp->right) Q.push(temp->right);
        }
    }
    return mx;
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
    root->right = newNode(11);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << maxSumLevel(root) << endl;

    return 0;
}