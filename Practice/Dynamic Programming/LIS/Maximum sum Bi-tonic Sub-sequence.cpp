#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// https://www.geeksforgeeks.org/maximum-sum-bi-tonic-sub-sequence/
// Maximum sum Bi-tonic Sub-sequence

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

    int dp[n + 1][3];
    memset(dp, 0, sizeof dp);

    //dp[i][0] -> increasing sequence till now.
    //dp[i][1] -> decreasing sequence from any element greater than this.

    int res = 0; // stores maximum sum of all.

    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = arr[i];
        int j = i - 1;
        while (j >= 0) {
            //increasing.
            if (arr[j] < arr[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + arr[i]);
            }
            //decreasing
            if (arr[j] > arr[i]) {
                dp[i][1] = max(dp[i][1] , max(dp[j][0], dp[j][1]) + arr[i]);
            }
            j--;
        }
        res = max({dp[i][0], dp[i][1] , res});
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << res;

    return 0;
}