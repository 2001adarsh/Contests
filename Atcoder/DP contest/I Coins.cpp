#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

int n;
double arr[3005];
double ans = 0.0;

double dp[3005][3005]; //dp[1..i][x] here i represents coins from 1..i, and
// x represents the exact number of heads needed.

// if dp(0,0) means that probability of getting 1 head is 1.0

double solve(int i, int x ) {
    if (x == 0) //probability will always be 1.0 to get 0 heads.
        return 1.0;

    if (i == 0) //probability of getting x heads in 0 coins is always 0.
        return 0.0;

    if (dp[i][x] > -0.9)
        return dp[i][x];

    return dp[i][x] = arr[i] * solve(i - 1, x - 1) + (1 - arr[i]) * solve(i - 1, x) ;
    //probability of getting head here + probability of this to be tail
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int minHeads = (n + 1) / 2;
    memset(dp, -1, sizeof dp);
    dp[0][0] = 1.0;

    cout << fixed << setprecision(10) << solve(n, minHeads);
    return 0;
}