#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Longest Repeating Subsequence:

//This solution is correct for TOP DOWN DP, but doesn't get AC on
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
// Hence resolve to Bottom Up solution.
int fun(string str, int i, int j, vector<vector<int>> dp) {
    if (i == str.size() || j == str.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j)
        return dp[i][j] = max(fun(str, i + 1, j, dp), fun(str, i, j + 1, dp));

    if (str[i] == str[j])
        return dp[i][j] = 1 + fun(str, i + 1, j + 1, dp);

    return dp[i][j] = max(fun(str, i + 1, j, dp), fun(str, i, j + 1, dp));
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
        string str;
        cin >> str;
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // cout << fun(str, 0, 0, dp) << endl;


        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);

        //Just one condition, that (i!=j).
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i - 1] == str[j - 1] && i != j)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }


        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        cout << dp[n][n] << endl;

        //Now printing it. follow same pattern, just don't print on i==j
        string res = "";
        int i = n, j = n;
        while (i && j) {
            if (str[i - 1] == str[j - 1] && i != j) {
                res += str[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;

    }

    return 0;
}