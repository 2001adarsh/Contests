#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl     "\n"
#define mod    1000000007
#define inf    1e18

// Digit DP
// Count the numbers between L to R which have sum of digits = X.
int dp[21][1005][2];

int recurse(string& num, int i, int X, bool tight) {
    if (i == num.size() and X == 0)
        return 1;
    if (X < 0 or i == num.size())
        return 0;
    if (dp[i][X][tight] != -1)
        return dp[i][X][tight];
    int cnt = 0;

    // for (char k = '0'; k <= '9'; k++) {
    //     if (tight == true) {
    //         if (k < num[i])
    //             cnt += recurse(num,  i + 1, X - (k - '0'), false);
    //         else if (k == num[i])
    //             cnt += recurse(num, i + 1, X - (k - '0'), tight);
    //     }
    //     else
    //         cnt += recurse(num,  i + 1, X - (k - '0'), false);
    // }

    //a better way:
    int upper_bound = tight ? (num[i] - '0') : 9 ;
    for (int k = 0; k <= upper_bound; k++) {
        cnt += recurse(num, i + 1, X - k, tight & (k == upper_bound));
    }

    return dp[i][X][tight] = cnt;
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //first finding till R.
    // int R, X;
    // cin >> R >> X;

    // string str = to_string(R);
    // int n = str.size();

    // memset(dp, -1, sizeof dp);

    // cout << recurse(str, 0, X, true);

    //for finding [L, R]:
    // find for (0, R) and (0, L-1) then (0, R) - (0, L-1) = (L, R);
    int L, R, X;
    cin >> L >> R >> X;
    L--;
    string lstr = to_string(L);
    memset(dp, -1, sizeof dp);
    int left = recurse(lstr, 0, X, true);

    string rstr = to_string(R);
    memset(dp, -1, sizeof dp);
    int right = recurse(rstr, 0, X, true);

    cout << (right - left);
    return 0;
}