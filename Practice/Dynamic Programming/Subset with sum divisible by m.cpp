#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
// Subset with sum divisible by m
// https://www.geeksforgeeks.org/subset-sum-divisible-m/
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[1000];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        dp[(sum + m) % m]++;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (dp[i] > 1)
            ans += ((dp[i] * dp[i] + 1) / 2);
    }

    cout << ans;
    return 0;
}