#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

class Trie
{
public:
    char data;
    unordered_map<char, Trie*> childs;
    int count;
    Trie(char data) {
        this->data = data;
        this->count = 0;
        this->childs = unordered_map<char, Trie*>();
    }
    ~Trie();
};

//pqert i = 0

void insert(string s, int i, Trie* root) {
    if (i == s.size())
        return;
    if (root->childs.count(s[i]) == 1)
        insert(s, i + 1, root->childs[s[i]]);
    else {
        Trie* temp = new Trie(s[i]);
        root->childs[s[i]] = temp;
        insert(s, i + 1, root->childs[s[i]]);
    }
    if (i == s.size() - 1)
        root->childs[s[i]]->count++;
}

void Print(Trie* root) {
    cout << root->data;
    if (root->count > 0)
        cout << '\n';
    for (auto x : root->childs)
        Print(x.second);
}

bool search(Trie* root, string s, int pos) {
    if (pos == s.size() - 1 and root->count > 0)
        return true;
    if (pos == s.size() - 1 and root->count == 0)
        return false;

    if (root->childs.count(s[pos + 1]) == 1)
        return search(root->childs[s[pos + 1]], s, pos + 1);
    return false;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Trie* root  = new Trie('_');
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        insert(str, 0, root);
    }

    Print(root);

    cout << search(root, "prq", -1);

    return 0;
}