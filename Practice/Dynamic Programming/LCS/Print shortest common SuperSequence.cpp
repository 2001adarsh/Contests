#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

//Printing Shortest common SuperSequence.

/*
My approach is different that given on the GKGS.
It has used simple LCS table to find the shortest common supersequence,
and doesn't use any other modified LCS whatsoever.

The idea is: the length of superSequence will be.

 = len(X) - len(LCS) + len(Y) - len(LCS);

*/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    //Printing
    int i = m, j = n;
    string res = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            res += s1[i - 1];
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            res += s1[i - 1];
            i--;
        } else {
            res += s2[j - 1];
            j--;
        }
    }

    while (i > 0) {
        res += s1[i - 1];
        i--;
    }

    while (j > 0) {
        res += s2[j - 1];
        j--;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}