#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    int n = str.size();

    int dp[n + 1];
    memset(dp, -1, sizeof dp);

    vector<int> st; //stack

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (st.empty())
                continue;
            int start = st.back();
            st.pop_back();
            dp[i] = i - start + 1;
        } else
            st.push_back(i);
    }
    /*
        for (int i = 0; i < n; i++)
            cout << dp[i] << " ";
        cout << endl;*/

    int ans = 0, run = 0;
    for (int i = n; i >= 0; i--) {
        if (dp[i] != -1) {
            run += dp[i];
            i = (i - dp[i] + 1);
        }
        else
            run = 0;
        ans = max(run, ans);
    }
    cout << ans;
    return 0;
}