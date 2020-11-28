#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Longest Palindromic Subsequence.
// start from two ends of a same string, find the LCS till end.
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

int lps(string str, int i, int j, vector<vector<int>> dp) {
    if (i == j)
        return 1;
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    //recursive
    if (str[i] == str[j])
        return dp[i][j] = 2 + lps(str, i + 1, j - 1, dp); //palindrome. so count 2.
    return dp[i][j] = max(lps(str, i + 1, j, dp), lps(str, i, j - 1, dp));
}


//Or the simple approach could have been, to reverse the current string and store
//it in another string and find LCS of it.


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    int n = str.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    //cout << lps(str, 0, str.size() - 1, dp);


    //Bottom up approach is Tricky, so try it.
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) { //constraint will make sure that !(i>j)
            int j = i + gap;
            if (str[i] == str[j] && gap == 1)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[0][n - 1];


    return 0;
}


// A simple example demonstrating this is,
/*
void lcs(string X, string Y) {
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

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << dp[m][n];


    //printing string.
    int i = m, j = n;
    string res = "";
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            res = X[i - 1] + res;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << res;

}

*/