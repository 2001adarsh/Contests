#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
const int MOD = 1000000007;

// https://atcoder.jp/contests/abc183/tasks/abc183_e
/*
    calculate for each point ways, in right down and diagonally down direction.
    ans%MOD

    using prefix array to reduce the time complexity from o(n^3) to o(n^2).
*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;
    vector<string> arr;

    for (int i = 0; i < m; i++) {
        string x;   cin >> x;
        arr.push_back(x);
    }

    int dp[m + 2][n + 2];
    int row[m + 2][n + 2];
    int col[m + 2][n + 2];
    int diag[m + 2][n + 2];

    memset(dp, 0, sizeof dp);

    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(diag, 0, sizeof diag);

    dp[1][1] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1 ) continue;
            if (arr[i - 1][j - 1] == '#') {
                row[i][j] = 0;
                col[i][j] = 0;
                diag[i][j] = 0;
                continue;
            }

            row[i][j] = row[i - 1][j] % MOD + dp[i - 1][j] % MOD;
            col[i][j] = col[i][j - 1] % MOD + dp[i][j - 1] % MOD;
            diag[i][j] = diag[i - 1][j - 1] % MOD + dp[i - 1][j - 1] % MOD;

            dp[i][j] = ((row[i][j] % MOD + col[i][j] % MOD) % MOD + diag[i][j] % MOD) % MOD;
        }
    }

    /*  for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }*/

    cout << dp[m][n];

    return 0;
}
