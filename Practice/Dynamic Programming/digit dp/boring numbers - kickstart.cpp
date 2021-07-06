#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6
// Boring Numbers:
// a positive number is called boring if all of the digits at even positions in the number are even and
// all of the digits at odd positions are odd.
// L and R,  To count how many numbers in the range [L, R] (L and R inclusive) are boring.

int dp[31][2][2][2];


int solve(string& R, int n, bool even, bool leading, bool tight) {
    if (n == 0)
        return 1;

    if (dp[n][even][leading][tight] != -1)
        return dp[n][even][leading][tight];

    if (even) { //even position.
        vector<int> digits = {0, 2, 4, 6, 8};
        int ub = tight ? (R[R.size() - n] - '0') : 9;
        int ans = 0;
        for (int dig : digits)                  //tight will be true, only when digit is equal to upper-bound.
            if (dig <= ub)
                ans += solve(R, n - 1, false, false, (tight & (dig == ub)) );
        return dp[n][even][leading][tight] = ans;

    } else { //odd position.

        //checking if leading is 0,
        vector<int> digits = {1, 3, 5, 7, 9};
        int ub = tight ? (R[R.size() - n] - '0') : 9;
        int ans = 0;

        if (leading) //there can be a leading zero.
            ans += solve(R, n - 1, false, true, false);

        for (int dig : digits)                  //tight will be true, only when digit is equal to upper-bound.
            if (dig <= ub)
                ans += solve(R, n - 1, true, false, (tight & (dig == ub)) );
        return dp[n][even][leading][tight] = ans;
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        int l, r;
        cin >> l >> r;

        l--;
        string lstr = to_string(l);
        memset(dp, -1, sizeof dp);
        int left = solve(lstr, lstr.size(), false, true, true);

        string rstr = to_string(r);
        memset(dp, -1, sizeof dp);
        int right = solve(rstr, rstr.size(), false, true, true);

        cout << right - left << endl;
    }


    return 0;
}