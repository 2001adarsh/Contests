#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Leetcode
// Find the maximum square of all 1's

const int N = 1005;
int arr[N][N];
int dp[N][N];

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    memset(dp, 0, sizeof dp);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = arr[i][j];
            else if (arr[i][j] == 1)
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            else dp[i][j] = 0;
            ans = max(dp[i][j] , ans);
        }
    }

    cout << ans;

    return 0;
}