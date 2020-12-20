#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Edit Distance | DP-5
// https://www.geeksforgeeks.org/edit-distance-dp-5/

/*
Find minimum number of edits (operations) required to convert ‘str1’
into ‘str2’.
    Insert
    Remove
    Replace
*/

//recursion + memoization:
int dp[500][500];
int fun(string str1, string str2, int i, int j, int m, int n) {
    if (i == m && j == n)
        return 0;
    if (i == m)
        return n - j;//if one string ends, then we have only 1 edit to insert the elements of another.
    if (j == n)
        return m - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    // if equal
    if (str1[i] == str2[j])
        return fun(str1, str2, i + 1, j + 1, m, n);

    //else perform operations.
    //insert:
    int a = fun(str1, str2, i, j + 1, m, n);
    //delete:
    int b = fun(str1, str2, i + 1, j, m, n);
    //replace:
    int c = fun(str1, str2, i + 1, j + 1, m, n);

    //each operation needs 1 edit.
    return dp[i][j] = min({a, b, c}) + 1;
}

//Bottom Up DP
void BottomUp(string s, string t) {
    int m = s.size();
    int n = t.size();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= n; i++) // if there are 0 elements in s, then insert all of t.
        dp[0][i] = i;

    for (int i = 0; i <= m; i++) // if there are 0 elements in t, then delete all of s.
        dp[i][0] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min({
                    dp[i][j - 1] + 1, //insert
                    dp[i - 1][j] + 1, //remove
                    dp[i - 1][j - 1] + 1, //replace.
                });
            }
        }
    }

    cout << dp[m][n];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str1, str2;
    cin >> str1 >> str2;
    // memset(dp, -1, sizeof dp);
    // cout << fun(str1, str2, 0, 0, str1.size(), str2.size());
    BottomUp(str1, str2);
    return 0;
}