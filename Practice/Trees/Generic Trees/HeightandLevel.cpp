#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Generic Trees:
class Node
{
public:
    int data;
    Node* firstChild;
    Node* nextSiblings;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->firstChild = NULL;
    node->nextSiblings = NULL;
    return node;
}


//return height of the maximum tree.
int height(Node* root) {
    if (!root)
        return 0;
    return 1 + max(height(root->firstChild) , height(root->nextSiblings));
}


//Problem 2-> given a parent array, determine its height.
vector<int> adj[1001]; //adjecency to store tree.
int buildTree(int *parent, int n) {
    int letRoot = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1)
            letRoot = i;
        else {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }
    return letRoot;
}

int bfs(int root_index, int n) {
    int vis[n + 1] = {};
    queue<int> Q;

    Q.push(root_index);
    vis[root_index] = 1;

    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        cout << top << " ";
        for (int nbr : adj[top]) {
            if (!vis[nbr]) {
                Q.push(nbr);
                vis[nbr] = vis[top] + 1;
            }
        }
    }
    cout << "\n Level:";
    int level = 0;
    for (int i = 0; i < n; i++)
        level = max(level, vis[i]);
    return level;
}

//Example 2 : Recur for the parent recursively and find max route till there.

int findHeight(int *parent, int node, int *height, int *vis) {
    if (parent[node] == -1) {
        vis[node] = 1;
        return 0;
    }
    if (vis[node])
        return height[node];

    vis[node] = 1;

    return height[node] = 1 + findHeight(parent, parent[node], height, vis);
}

int ans(int *parent, int n) {
    int *vis = new int[n + 1];
    int *height = new int[n + 1];

    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        height[i] = 0;
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            height[i] = findHeight(parent, i, height, vis);
        }
        //cout << height[i] + 1 << " ";
        mx = max(mx, height[i] + 1);
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

    int parent[] = { 2, 0, -1, 2, 3 };
    int n = sizeof(parent) / sizeof(int);

    int root_index = buildTree(parent, n);
    cout << "Root Index: " << root_index << endl;

    cout << "Completed " << bfs(root_index, n);

    cout << "\n" << ans(parent, n);
    return 0;
}