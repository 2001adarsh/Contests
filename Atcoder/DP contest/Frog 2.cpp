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

    int n, K;
    cin >> n >> K;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= K; j++) {
            if (j <= i)
                dp[i] = min(dp[i], dp[i - j] + abs(arr[i - j] - arr[i]));
        }
    }

    cout << dp[n - 1];
    return 0;
}