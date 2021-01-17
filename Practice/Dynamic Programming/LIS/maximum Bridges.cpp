#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
// Maximum Bridges that can be made without crossing each other.
// more than two bridge can start or end at same position.

bool comp(pair<int, int>& a, pair<int, int>&b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

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
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v.push_back({x, 0});
        }
        for (int i = 0; i < n; i++) {
            int y; cin >> y;
            v[i].second = y;
        }

        sort(v.begin(), v.end(), comp);
        int dp[n + 1] = {};
        dp[0] = 1;
        int ans = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                // = because, from 1 point we can start 2 coordinates.
                if (v[i].first >= v[j].first and dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            ans = max(dp[i], ans);
        }
        cout << ans << endl;

    }

    return 0;
}