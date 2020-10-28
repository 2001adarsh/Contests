#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//recursive -> Finding max value. use dp[N] to memoize.
int unbounded(int val[], int wt[], int W, int n) {
    if (W == 0)
        return 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (W - wt[i] >= 0)
            mx = max(mx, val[i] + unbounded(val, wt, W - wt[i], n));
    }
    return mx;
}

int bottomUp(int val[], int wt[], int n, int W) {
    int dp[10005];
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i >= wt[j])
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
        }
    }
    return dp[W];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int val[]  = {10, 40, 50, 70};
    int wt[] = {1, 3, 4, 5} ;
    int n = sizeof(val) / sizeof(int);
    int W = 8;

    cout << unbounded(val, wt, W, n) << endl;
    cout << bottomUp(val, wt, n, W);
    return 0;
}