#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

void lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string s = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            s = s1[i - 1] + s;
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << s;
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
    lcs(s1, s2);

    return 0;
}

/*
 //Top Down Approach

#define MAX 3000
int dp[MAX + 1][MAX + 1];

string getLCS(string& s1, string&s2, int len) {
    string LCS = "";
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            LCS.push_back(s1[i]);
            len--, i++, j++;
        }
        else if (dp[i][j + 1] > dp[i + 1][j])
            j++;
        else i++;
    }
    return LCS;
}

int length(string& s1, string& s2, int i, int j) {
    if (i >= s1.size() || j >= s2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + length(s1, s2, i + 1, j + 1);
    return dp[i][j] = max(length(s1, s2, i + 1, j), length(s1, s2, i, j + 1));
}

string solve(string s1, string s2) {
    memset(dp, -1, sizeof dp);
    int len = length(s1, s2, 0, 0);
    cout << len;
    return getLCS(s1, s2, len);
}


*/