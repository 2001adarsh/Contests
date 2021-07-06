#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node* parent;

    int TakenId;
    bool isLock;
    bool anyLockedChild;

    vector<Node*> children;
    unordered_set<Node*> lockedChildren;
    unordered_set<int> usedUserId;

    Node() {
        //default constructor.
        this->TakenId = -1;
        this->data = "";
        this->isLock = false;
        this->anyLockedChild = true;
        this->parent = NULL;
    }

    Node(string data) {
        this->TakenId = -1;
        this->data = data;
        this->isLock = false;
        this->anyLockedChild = true;
        this->parent = NULL;
    }

    Node(string data, Node* parent) {
        this->isLock = false;
        this->data = data;
        this->TakenId = -1;
        this->anyLockedChild = true;
        this->parent = parent;
    }
};

bool Lock(Node* node, int userId) {
    if (node->anyLockedChild == false)
        return false;
    Node* T = node;
    bool found = false;
    for ( ; T != NULL ; T = T->parent) {
        if (T->isLock == true) {
            found = true;
            break;
        }
    }
    if (found)
        return false;
    else {
        node->isLock = true;
        node->TakenId = userId;
        T = node;
        for ( ; T != NULL ; T = T->parent) {
            T->lockedChildren.insert(node);
            T->usedUserId.insert(userId);
            T->anyLockedChild = false;
        }
        return true;
    }
}

bool unLock(Node* node, int userId) {
    if (node->isLock == false)
        return false;
    else if (node->TakenId == userId) {
        Node* T = node;
        node->isLock = false;
        node->TakenId = -1;
        for ( ; T != NULL ; T = T->parent) {
            T->lockedChildren.erase(node);
            T->usedUserId.erase(userId);
            T->anyLockedChild = true;
        }
        return true;
    }
    return false;
}

bool Upgrade(Node* node, int userId) {
    if (node->isLock == true or (node->anyLockedChild == false and node->usedUserId.size() != 1) or  node->usedUserId.size() == 0 or node->usedUserId.find(userId) == node->usedUserId.end())
        return false;
    auto now = node->lockedChildren;
    for (auto x : now)
        unLock(x, userId);
    Lock(node, userId);
    return true;
}

void dfs(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        for (int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i]);
        }
    }
}

unordered_map<string, Node*> mp;
int main() {

    int n, m, q;
    cin >> n >> m >> q;
    int par = -1;

    vector<Node*> temp;
    string s;
    cin >> s;
    Node* root = new Node(s);
    mp[s] = root;
    temp.push_back(root);


    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        if ( (i % m) == 0)
            par++;
        // cout<<par<<" " << temp[par]->data<<endl;
        Node* node = new Node(s, temp[par]);
        // cout<<node->data<<endl;
        temp[par]->children.push_back(node);
        mp[s] = node;
        temp.push_back(node);
    }

    while (q--) {
        string s;
        int type, userId;
        cin >> type >> s >> userId;
        bool temp = false;
        if (type  == 1) {
            //Lock
            temp = Lock(mp[s], userId);
        } else if (type == 2) {
            //UnLock
            temp = unLock(mp[s], userId);
        } else if (type == 3) {
            //Upgrade
            temp = Upgrade(mp[s], userId);
        }
        if (temp) cout << "true" << endl;
        else cout << "false" << endl;
    }

    // dfs(root);

    return 0;
}