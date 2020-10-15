#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

//Min coins needed of any denominations to compute the money.

int topDown(int money, int arr[], int n, int dp[]) {
    if (money == 0)
        return 0;
    if (dp[money] != 0)
        return dp[money];
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= money)
            res = min(res, topDown(money - arr[i], arr, n, dp));
    }
    return dp[money] = res + 1;
}

int BottomUp(int money, int arr[], int n) {
    int dp[10000] = {0};
    for (int i = 1; i <= money; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min(dp[i - arr[j]], dp[i]);
            }
        }
        dp[i] += 1;
    }
    return dp[money];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, money;
    cin >> n >> money;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int dp[1000] = {0};
    cout << topDown(money, arr, n, dp);
    cout << BottomUp(money, arr, n);
    return 0;
}