#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Maximum sum increasing subsequence from a prefix and a given element after prefix is must
// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-from-a-prefix-and-a-given-element-after-prefix-is-must/

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, I, k;
    cin >> n >> I >> k;
    int dp[I + 1], arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i <= I; i++) {
        dp[i] = arr[i];
        int j = i - 1;
        while (j >= 0) {
            if (arr[j] < arr[i] and dp[j] + arr[i] > dp[i])
                dp[i] = arr[i] + dp[j];
            j--;
        }
    }

    int ans = arr[k] , j = I;
    while (j >= 0) {
        if (arr[j] < arr[k] and ans < dp[j] + arr[k])
            ans = dp[j] + arr[k];
        j--;
    }

    cout << ans;

    return 0;
}