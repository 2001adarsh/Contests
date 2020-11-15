#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
const int N = 1005;

// https://www.geeksforgeeks.org/wildcard-pattern-matching/
// WILDCARD MATCHING

int dp[N][N];
int fun(string s1, string s2, int i, int j) {
    //base cases
    if (i == s1.size() && j < s2.size())
        return false;
    if (i == s1.size() && j == s2.size())
        return true;
    if (s2[j] >= 'a' && s2[j] <= 'z' && (s2[j] != s1[i]) )
        return false;

    if (dp[i][j] != -1)
        return dp[i][j];

    //recursive cases
    if (s2[j] == '*')
        return dp[i][j] = fun(s1, s2, i + 1, j) || fun(s1, s2, i + 1, j + 1) || fun(s1, s2, i, j + 1);
    else if (s2[j] == '?')
        return dp[i][j] = fun(s1, s2, i + 1, j + 1);
    else if (s2[j] == s1[i])
        return dp[i][j] = fun(s1, s2, i + 1, j + 1);
    return dp[i][j] = false;
}


void iterative(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int T[n + 1][m + 1];
    T[0][0] = 1; //when both are null

    for (int i = 0; i <= n; i++) //pattern is null
        T[i][0] = 0;
    for (int i = 0; i <= m; i++) //text is null
        if (pattern[i - 1] == '*')
            T[0][i] = T[0][i - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '?' || (pattern[j - 1] == text[i - 1]))
                T[i][j] = T[i - 1][j - 1];
            else if (pattern[j - 1] == '*')
                T[i][j] = T[i - 1][j] || T[i][j - 1];
            else
                T[i][j] = 0;
        }
    }
    cout << T[n][m];
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
    memset(dp, -1, sizeof dp);
    int x = fun(s1, s2, 0, 0);
    if (x)
        cout << "MATCHED";
    else
        cout << "NOT MATCHED";

    iterative(s1, s2);

    return 0;
}

/*
aaabac
**ab*?
*/