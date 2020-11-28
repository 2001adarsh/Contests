#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//shortest common supersequence

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string X, Y;
    cin >> X >> Y;
    int m = X.size();
    int n = Y.size();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // cout<<dp[m][n]<<" "<<m<<" "<<n;
    int res = dp[m][n];
    res += m - dp[m][n];
    res += n - dp[m][n];
    cout << res;

    return 0;
}