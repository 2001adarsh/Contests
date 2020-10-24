#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

vector<int> gr[100005];
int dp[100005];

int dfs(int x) {
    if (dp[x] != -1)
        return dp[x];
    for (auto i : gr[x]) {
        dp[x] = max(dp[x], 1 + dfs(i));
    }
    return dp[x];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> out(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        out[x]++;
    }

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= n; i++) {
        if (out[i] == 0)
            dp[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}