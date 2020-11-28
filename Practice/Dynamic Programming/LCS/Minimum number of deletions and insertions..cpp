#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
// Minimum number of deletions and insertions.
int minOperations(string str1, string str2)
{
    int m  = str1.size();
    int n = str2.size();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int res = m + n - (2 * dp[m][n]);
    return res;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;
    cout << minOperations(s1, s2);

    return 0;
}