#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// minimize-cash-flow-among-given-set-friends-borrowed-money
// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int> > edgeList;
    vector<int> amount(n + 1); //store the net amount the persion has to take.

    for (int i = 0; i < m; i++) {
        int u, v, amt;
        cin >> u >> v >> amt;
        edgeList.push_back({u, v, amt});
        amount[u] -= amt;
        amount[v] += amt;
    }

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        if (amount[i] != 0)
            st.insert(amount[i]);
    }

    int transactions = 0;
    //pop out two persons (highest debitor and creditor) and settle them
    while (!st.empty()) {
        transactions++;

        int debit = *(st.begin());
        auto it = prev(st.end()); //last element from set.
        int credit = *(it);

        st.erase(st.begin());
        st.erase(it);

        //settlement
        int settlement_amount = min(abs(debit) , credit);
        debit += settlement_amount;
        credit -= settlement_amount;

        if (debit)
            st.insert(debit);
        if (credit)
            st.insert(credit);
    }

    cout << transactions << endl; //Minimum no. of transactions.
    return 0;
}