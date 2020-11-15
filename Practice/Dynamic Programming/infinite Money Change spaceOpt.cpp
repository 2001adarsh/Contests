#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
const int MOD = 1000000007;
int dp[1000005];
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int N; cin >> N;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i]; j <= N; j++) {
                dp[j] = (dp[j] % MOD + dp[j - arr[i]] % MOD) % MOD;
            }
        }
        cout << dp[N] << endl;
    }

    return 0;
}