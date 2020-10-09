#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
//Binary Tree
class Node
{
public:
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(Node* A, Node* B) {
        return A->freq > B->freq;
    }
};

Node* huffmanCoding(vector<pair<char, int> > arr) {
    //Creating a priority Queue to contain the minimum elements
    priority_queue<Node*, vector<Node*> , compare> Q;
    //adding all nodes to Q first
    for (int i = 0; i < arr.size(); i++)
        Q.push(new Node(arr[i].first, arr[i].second));

    //now the algo.
    while (Q.size() != 1) {
        Node* l = Q.top();
        Q.pop();
        Node* r = Q.top();
        Q.pop();

        //now join both and create a new node.
        Node * newNode = new Node('#', l->freq + r->freq);
        newNode->left = l;
        newNode->right = r;
        Q.push(newNode);
    }
    return Q.top();
}

void printTree(Node* root, string str) {
    if (!root)
        return;
    if (root->data != '#')
        cout << root->data << " - " << str << endl;
    printTree(root->left, str + "0");
    printTree(root->right, str + "1");
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<char, int> > arr;
    for (int i = 0; i < n; i++) {
        char ch; int f;
        cin >> ch >> f;
        arr.push_back({ch, f});
    }

    //Tree after encoding.
    Node* tree = huffmanCoding(arr);
    //printing table generated:
    printTree(tree, "");

    return 0;
}