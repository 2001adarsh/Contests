#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// a subarray with Maximum xor

//Binary Trie.
class Node
{
public:
    Node* go[2]; //go[0] -> for child as 0, go[1] -> child 1.
    Node() {
        this->go[0] = this->go[1] = NULL;
    }
    ~Node();
};

int find(int num, Node* root) {
    Node* temp = root, *opp = root;
    string oppositeBit = "";

    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (temp->go[bit] == NULL)
            temp->go[bit] = new Node();
        temp = temp->go[bit];
        if (opp->go[!bit] != NULL) {
            oppositeBit += to_string(!bit);
            opp = opp->go[!bit];
        } else {
            oppositeBit += to_string(bit);
            opp = opp->go[bit];
        }
    }
    // cout << oppositeBit << endl;
    bitset<32> set(oppositeBit);
    int got = set.to_ulong();
    // cout << num << " " << got << " " << (num ^ got) << endl;
    return (num ^ got);
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
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    int prefix[n];
    prefix[0] = array[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] ^ array[i];

    //now since we have prefix xor of all element.
    // and a^b^c^d^e and we need to find subarray xor of c to e,
    //then a^b^c^d^e ^ a^b = would give the ans.

    //Hence to find the result, it is now reduced to finding 2 points
    //in the array with max xor.
    Node* root = new Node();

    // inserting 1st element.
    Node *temp = root;
    for (int i = 31; i >= 0; i--) {
        int bit = ((prefix[0] >> i) & 1);
        temp->go[bit] = new Node();
        temp = temp->go[bit];
    }

    int max_xor = 0;
    for (int i = 1; i < n; i++) {
        int x = find(prefix[i], root);
        max_xor = max(max_xor, x);
    }

    cout << max_xor;

    return 0;
}