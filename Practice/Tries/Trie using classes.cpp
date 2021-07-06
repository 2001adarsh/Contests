#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

class Node
{
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    Node(char data) {
        this->data = data;
        this->terminal = false;
    }
    ~Node();
};

class Trie
{
public:
    Node* root;
    Trie() { //initialise the root node.
        root = new Node('\0');
    }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children.count(word[i]) == 1) {
                //letter already present -> just go to it.
                temp = temp->children[word[i]];
            } else {
                //create that letter.
                Node* ch = new Node(word[i]);
                temp->children[word[i]] = ch;
                temp = temp->children[word[i]];
            }
        }
        if (word.size() > 0) //if there is a valid input. can't mark root as terminal.
            temp->terminal = true;
    }

    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children.count(word[i]) == 0)
                return false; //not found.
            temp = temp->children[word[i]];
        }
        if (temp->terminal == true)
            return true;
        return false;
    }
};


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Trie t;
    vector<string> words = {"ab", "apple", "win", "not", "hello"};

    for (auto str : words)
        t.insert(str);

    cout << t.search("no") << endl;
    cout << t.search("hello");

    return 0;
}