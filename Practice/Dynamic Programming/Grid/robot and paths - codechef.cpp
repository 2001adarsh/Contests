#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
#define MOD 1000000007
// https://www.codechef.com/problems/CD1IT4
// Robot and Path
int dp[1000][1000];

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n, p;
    cin >> m >> n >> p;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            dp[i][j] = 4;
    }
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        dp[x][y] = -1;
    }

    //now compute no. of ways:
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == -1) { //if blocked
                dp[i][j] = 0;
                continue;
            }
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
            }
            else if (i == 1) {
                dp[i][j] = dp[i][j - 1];
            } else if ( j == 1)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
        }
    }

    /*for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/

    cout << dp[m][n];

    return 0;
}