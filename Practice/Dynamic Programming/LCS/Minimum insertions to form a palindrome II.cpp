#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

int fun(string str, int i, int j) {
    if (i == j)
        return 0;
    if (i > j)
        return INT_MAX;

    if (str[i] == str[j])
        return fun(str, i + 1, j - 1);

    return 1 + min(fun(str, i + 1, j), fun(str, i, j - 1));
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

    // cout << fun(str, 0, str.size() - 1);

    //converting the top down to bottom up.
    //use recursive tree generated in top down to convert.
    int n = str.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int gap = 0; gap < n; gap++) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            if (i == j)
                dp[i][j] = 0;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }


    cout << dp[0][n - 1];

    return 0;
}