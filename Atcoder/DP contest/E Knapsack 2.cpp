#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Change the perspective,
/*
    instead of calculating the dp[1..i][x] where i tells about number of items and
    x tells about the exact weight. and calculating it through that.

    We could,
    dp[1..i][v] where i tells about the number of items and v tells about the exact value
    and we can choose the min weight for achieving the v. If not possible then INF,
    Time Complexity - O(N^2 V) - space also same.
    space could be reduced to O(NV) by optimising its item row, as we only need the last
    row answers and we could easily eliminate it using 2 vectors.
*/


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, w;
    cin >> n >> w;
    int wght[n], val[n], V = 0;

    for (int i = 0; i < n; i++) {
        cin >> wght[i] >> val[i];
        V += val[i];
    }

    int dp[n + 1][V + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= val[i - 1])
                dp[i][j] = min(dp[i][j] , wght[i - 1] + dp[i - 1][j - val[i - 1]]);
        }
    }
    int ans = 0;
    for (int i = V; i > 0; i--) {
        if (dp[n][i] <= w)
            ans = max(i, ans);
    }
    cout << ans;
    return 0;
}