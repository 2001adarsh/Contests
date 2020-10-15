#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
//Ladders Problem: total number of ways taken to reach the top,
// if 1...n steps can be taken.

//Top Down approach
int solve(int N, int n, int dp[]) {
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    if (dp[N] != 0)
        return dp[N];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += solve(N - i, n, dp);
    return dp[N] = ans;
}

//Bottom Up DP
int solve2(int N, int m) {
    int dp[1000] = {0};
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }
    return dp[N];
}

//More optimised.
int optimised(int N, int m) {
    int dp[1000] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= m; i++)
        dp[i] = 2 * dp[i - 1];
    for (int i = m + 1; i <= N; i++)
        dp[i] = 2 * dp[i - 1] - dp[i - m - 1];
    for (int i = 0; i <= N; i++)
        cout << dp[i] << " ";
    return dp[N];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //N is total number of steps ladders
    //n is the 1..n
    int n, N;
    cin >> n >> N;
    int dp[1000] = {0};
    cout << solve(N, n, dp) << endl;
    cout << solve2(N, n) << endl;
    cout << optimised(N, n);
    return 0;
}