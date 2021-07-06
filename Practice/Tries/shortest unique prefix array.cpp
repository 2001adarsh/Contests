#include<bits/stdc++.h>
using namespace std;
#define int long long int

//Shortest Unique Prefix Array
class Node
{
public:
    char data;
    int run;
    unordered_map<char, Node*> children;
    bool terminal;
    Node(char data) {
        this->data = data;
        this->run = 0;
        this->terminal = false;
    }
    ~Node();
};

void insert(string& s, Node* root) {
    Node* temp = root;
    for (int i = 0; i < s.size(); i++) {
        temp->run++;
        if (temp->children.count(s[i]))
            temp = temp->children[s[i]];
        else {
            temp->children[s[i]] = new Node(s[i]);
            temp = temp->children[s[i]];
        }
    }
    temp->run++;
    temp->terminal = true;
}

vector<string> result;
void uniquePrefix(Node* root, string str) {
    str += root->data;

    if (root->run == 1) {
        result.push_back(str);
        return ;
    }

    //traversing and finding smallest unique prefix.
    for (auto i : root->children) {
        uniquePrefix(i.second, str);
    }
}

void dfs(Node* root) {
    cout << root->data << " " << root->run << endl;
    for (auto i : root->children)
        dfs(i.second);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node* root = new Node('\0');
    vector<string> v = {"hello", "dog", "duck", "dove", "car", "cor"};
    for (auto i : v)
        insert(i, root);

    for (auto i : root->children) {
        uniquePrefix(i.second, "");
    }

    for (auto get : result)
        cout << get << " ";
    return 0;
}