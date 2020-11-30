#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Minimum insertions to form a palindrome | DP-28
// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/


// Simply find LCS and subtract it from N. => N-lcs(str);


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
        string str;
        cin >> str;

        int n = str.size();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);
        string Y = str;
        reverse(Y.begin(), Y.end());

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        cout << n - dp[n][n] << endl;

    }


    return 0;
}