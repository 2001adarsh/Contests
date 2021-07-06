#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define M 32

// Maximum xor of two numbers in an array

class Node
{
public:
    int data;
    Node *zero, *one;
    bool terminal;
    Node(int data = -1) {
        this->data = data;
        terminal = false;
        zero = one = NULL;
    }
    ~Node();
};

int insert(Node* Trie, int num) {
    bitset<M> set(num);
    // cout << set << endl;
    string res = "";
    Node* temp = Trie, *opp = Trie;
    for (int i = 31; i >= 0; i--) {
        if (set[i] == 1) {
            if (temp->one == NULL)
                temp->one = new Node(1);
            temp = temp->one;

            //try to choose 0 for opp.
            if (opp->zero != NULL) {
                opp = opp->zero;
                res += "0";
            } else {
                opp = opp->one;
                res += "1";
            }
        } else {

            if (temp->zero == NULL)
                temp->zero = new Node(0);
            temp = temp->zero;

            //try to choose 1 for opp.
            if (opp->one != NULL) {
                opp = opp->one;
                res += "1";
            } else {
                opp = opp->zero;
                res += "0";
            }
        }
    }
    bitset<M> get(res);
    int ans = get.to_ulong();
    // cout << ans << endl;

    return ans ^ num;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }

    Node* Trie = new Node();

    int max_xor = 0;

    //inserting first element in Trie.
    bitset<M> set(vec[0]);
    Node* temp = Trie;
    for (int i = 31; i >= 0; i--) {
        if (set[i] == 1) {
            temp->one = new Node(1);
            temp = temp->one;
        }
        else {
            temp->zero = new Node(0);
            temp = temp->zero;
        }
    }
    // cout << set << endl;

    //find xor of numbers 1 by 1.
    for (int i = 1; i < n; i++) {
        x = insert(Trie, vec[i]);
        max_xor = max(max_xor, x);
    }

    cout << max_xor;
    return 0;
}