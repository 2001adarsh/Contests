#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
bool flag = false;
int dp[1005][1005];

// Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

int longestPalin(string &s, int i, int j) {
    if (i == j && s[i] == s[j]) {
        flag = true;
        return 1;
    }
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // if first and last are equal
    int ans = 0, x = 0, y = 0;
    if (s[i] == s[j]) {
        ans = 2 + longestPalin(s, i + 1, j - 1);
    } else {
        x = longestPalin(s, i + 1, j);
        y = longestPalin(s, i, j - 1);
    }
    return dp[i][j] = max({ans, x, y});
}

int bottomUp(string &s) {
    memset(dp, 0, sizeof dp);
    int n = s.size();

    for (int i = 0; i < n; i++) //initialising with 1 length string to 1.
        dp[i][i] = 1;

    /* Correct but taking O(N^3) time. reduce it.
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j - i == gap) {
                    //now the valid gap
                    if (s[i] == s[j])
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    else
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    }*/
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            if (j > i) {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    /*memset(dp, -1, sizeof dp);
    int ans = longestPalin(str, 0, str.size() - 1);
    cout << ans;*/

    cout << bottomUp(str);
    return 0;
}