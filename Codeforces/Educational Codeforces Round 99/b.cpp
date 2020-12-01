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
    vector<int> st;
    int s = 0;
    for (int i = 0; ; i++) {
        s += i;
        st.push_back(s);
        if (s >= 5000006)
            break;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int low = lower_bound(st.begin(), st.end(), n) - st.begin();
        int val = st[low];
        // cout << low << " " << val << " ";
        if (val == n )
            cout << low << endl;
        else if (val == n + 1)
            cout << low + 1 << endl;
        else {
            int sum = val;
            bool flag = false;
            for (int i = 1; i <= n; i++) {
                if ( (sum - i) == (n + 1) ) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << low << endl;
            else
                cout << low + (val - n) << endl;
        }
    }

    return 0;
}