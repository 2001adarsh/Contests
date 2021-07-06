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

bool Lock(Node* node, int userId, mutex &m) {
    m.lock();
    cout << "Entered to lock: " << node->data << endl;
    if (node->anyLockedChild == false) {
        m.unlock();
        return false;
    }
    Node* T = node;
    bool found = false;
    for ( ; T != NULL ; T = T->parent) {
        if (T->isLock == true) {
            found = true;
            break;
        }
    }
    if (found) {
        m.unlock();
        return false;
    }
    else {
        node->isLock = true;
        node->TakenId = userId;
        T = node;
        for ( ; T != NULL ; T = T->parent) {
            T->lockedChildren.insert(node);
            T->usedUserId.insert(userId);
            T->anyLockedChild = false;
        }
        m.unlock();
        return true;
    }
}

bool unLock(Node* node, int userId, mutex &m) {
    m.lock();
    cout << "Entered to unlock: " << node->data << endl;
    if (node->isLock == false) {
        m.unlock();
        return false;
    }
    else if (node->TakenId == userId) {
        Node* T = node;
        node->isLock = false;
        node->TakenId = -1;
        for ( ; T != NULL ; T = T->parent) {
            T->lockedChildren.erase(node);
            T->usedUserId.erase(userId);
            T->anyLockedChild = true;
        }
        m.unlock();
        return true;
    }
    m.unlock();
    return false;
}

bool Upgrade(Node* node, int userId, mutex &m) {
    m.lock();
    cout << "Entered to Upgrade: " << node->data << endl;
    if (node->isLock == true or (node->anyLockedChild == false and node->usedUserId.size() != 1) or  node->usedUserId.size() == 0 or node->usedUserId.find(userId) == node->usedUserId.end()) {
        m.unlock();
        return false;
    }

    auto now = node->lockedChildren;
    mutex m2;
    for (auto x : now) {
        unLock(x, userId, ref(m2));
    }
    Lock(node, userId, ref(m2));
    m.unlock();
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

// #ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
// #endif


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
    vector<int> type(q), userId(q);
    vector<string> names(q);
    for (int i = 0; i < q; i++)
        cin >> type[i] >> names[i] >> userId[i];

    vector<std::future<bool> > myThreads;
    mutex m1;

    for (int i = 0; i < q; i++) {
        bool temp = false;
        if (type[i]  == 1) {
            //Lock
            // temp = Lock(mp[s], userId);
            myThreads.push_back(async(Lock, mp[names[i]], userId[i], ref(m1)));
        } else if (type[i] == 2) {
            //UnLock
            // temp = unLock(mp[s], userId);
            myThreads.push_back(async(unLock, mp[names[i]], userId[i], ref(m1)));
        } else if (type[i] == 3) {
            //Upgrade
            // temp = Upgrade(mp[s], userId);
            myThreads.push_back(async(Upgrade, mp[names[i]], userId[i], ref(m1)));
        }
    }

    for (int i = 0; i < q; i++) {
        cout << "Query " << i << " :" << myThreads[i].get() << endl;
    }

    // dfs(root);

    return 0;
}