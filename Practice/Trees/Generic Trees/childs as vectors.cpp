#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// using vectors for formation of N-ary Tree.
class Node
{
public:
    int data;
    vector<Node*> childs; //contains all the children.
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    return node;
}

// preorder traversal of the graph.
void preorder(Node* root) {
    if (!root)
        return;
    cout << root->data << " ";
    for (auto ch : root->childs) {
        preorder(ch);
    }
}

//print all root to leaf paths
void AllPaths(Node* root, vector<int> paths) {
    if (!root)
        return;

    paths.push_back(root->data);

    if (root->childs.empty()) {
        for (auto p : paths)
            cout << p << " ";
        cout << endl;
        paths.pop_back();
        return;
    }

    for (auto ch : root->childs) {
        AllPaths(ch, paths);
    }
    paths.pop_back();
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node* root = newNode(1);
    root->childs.push_back(newNode(2)); //child of 1
    root->childs.push_back(newNode(3));//child of 1
    root->childs[0]->childs.push_back(newNode(4)); //child of 2
    root->childs[1]->childs.push_back(newNode(5)); //child of 3.
    root->childs[1]->childs.push_back(newNode(6)); //child of 3
    root->childs[1]->childs[1]->childs.push_back(newNode(7)); //child of 6.

    preorder(root);
    cout << endl;
    cout << "All paths from root to leaf:" << endl;
    vector<int> v;
    AllPaths(root, v);

    return 0;
}

/* constructed tree is below.
     1
  2     3
  4    5 6
         7

*/