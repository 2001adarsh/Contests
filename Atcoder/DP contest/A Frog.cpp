#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

int dp[100005];
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1)
            dp[i] = abs(arr[1] - arr[0]);
        else
            dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]) , dp[i - 2] + abs(arr[i] - arr[i - 2]));
    }
    // for (int i = 0; i < n; i++)
    // cout << dp[i] << " ";
    cout << dp[n - 1];

    return 0;
}