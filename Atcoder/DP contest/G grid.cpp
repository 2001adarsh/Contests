#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define MOD 1000000007

int dp[1005][1005];

int solve(vector<string>& grid, int& n, int& m) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        if (grid[0][i] == '#')
            break;
        dp[0][i] = 1;
    }
    for (int j = 0; j < n; j++) {
        if (grid[j][0] == '#')
            break;
        dp[j][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
        }
    }
    return dp[n - 1][m - 1];
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
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    cout << solve(grid, n, m);

    return 0;
}