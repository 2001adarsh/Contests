#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            st.insert(x);
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (st.find(x) != st.end())
                cnt++;
        }
        cout << cnt << endl;
    }


    return 0;
}