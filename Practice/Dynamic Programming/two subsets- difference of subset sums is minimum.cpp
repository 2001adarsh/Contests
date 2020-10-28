#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] =  {5, 1};
    int n = sizeof(arr) / sizeof(int);
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    int dp[n + 1][total + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] || ((j >= arr[i]) ? dp[i - 1][j - arr[i]] : 0);
        }
    }
    int ans = total;
    for (int i = 0; i <= total; i++) {
        if (dp[n][i]) {
            int x = abs(total - i - i);
            ans = min(ans, x);
        }
    }
    cout << ans;
    return 0;
}