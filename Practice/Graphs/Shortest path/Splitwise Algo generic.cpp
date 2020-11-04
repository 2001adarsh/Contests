#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// minimize-cash-flow-among-given-set-friends-borrowed-money
// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

class person_compare
{
public:
    bool operator()(pair<string, int>p1, pair<string, int> p2) {
        return p1.second < p2.second;
    }
};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    map<string, int> amount; //net amount

    string x, y;
    int amt;
    while (m--) {
        cin >> x >> y >> amt;
        if (amount.count(x) == 0)
            amount[x] = 0;
        if (amount.count(y) == 0)
            amount[y] = 0;
        amount[x] -= amt;
        amount[y] += amt;
    }

    multiset<pair<string, int>, person_compare> st;

    //Iterate over the person who have non-zero net amount.
    for (auto p : amount) {
        string person = p.first;
        int amt = p.second;
        if (amount[person] != 0)
            st.insert({person, amt});
    }
    int transaction = 0;
    while (!st.empty()) {
        auto p1 = st.begin();
        auto p2 = prev(st.end());
        int debit = p1->second;
        string debit_person = p1->first;

        int credit = p2->second;
        string credit_person = p2->first;

        st.erase(p1);
        st.erase(p2);

        //settlement
        int settle = min(-debit, credit);
        debit += settle;
        credit -= settle;

        //Print transaction between two.
        cout << debit_person << " will pay " << settle << " to " << credit_person << endl;

        if (debit)
            st.insert({debit_person, debit});
        if (credit)
            st.insert({credit_person, credit});

        transaction++;
    }

    cout << transaction;

    return 0;
}