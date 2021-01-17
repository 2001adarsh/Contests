#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 105;
int dp[N][N][N];

int lcs(string& s1, string& s2, string& s3, int i, int j, int k) {
    if (i == s1.size() or j == s2.size() or k == s3.size())
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (s1[i] == s2[j] and s2[j] == s3[k])
        return dp[i][j][k] = 1 + lcs(s1, s2, s3, i + 1, j + 1, k + 1);

    return dp[i][j][k] = max({lcs(s1, s2, s3, i + 1, j, k), lcs(s1, s2, s3, i, j + 1, k), lcs(s1, s2, s3, i, j, k + 1) });
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, z;
        cin >> n >> m >> z;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        memset(dp, -1, sizeof dp);
        cout << lcs(s1, s2, s3, 0, 0, 0) << endl;
    }
    return 0;
}