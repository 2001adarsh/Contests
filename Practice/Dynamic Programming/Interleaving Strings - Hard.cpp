#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
int dp[105][105][205];

bool check(string&s1, string& s2, string& s3, int i, int j, int k) {

    if (i >= s1.size() && j >= s2.size())
        return true;
    if ( (i < s1.size() && s1[i] != s3[k]) && (j < s2.size() && s2[j] != s3[k]))
        return false;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    //recusive
    if (s1[i] == s3[k] && check(s1, s2, s3, i + 1, j, k + 1))
        return dp[i][j][k] = true;
    if (s2[j] == s3[k] && check(s1, s2, s3, i, j + 1, k + 1))
        return dp[i][j][k] = true;
    return dp[i][j][k] = false;
}

bool isInterleave(string s1, string s2, string s3) {
    memset(dp, -1, sizeof dp);
    return check(s1, s2, s3, 0, 0, 0);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << isInterleave(s1, s2, s3);

    return 0;
}