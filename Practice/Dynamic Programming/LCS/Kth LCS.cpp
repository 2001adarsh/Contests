#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

// Kth - order LCS

/*
In addition to the two sequences, an additional parameter k was introduced.
 A k-ordered LCS is defined to be the LCS of two sequences if you are allowed
  to change atmost k elements in the first sequence to any value you wish to.
 Can you help him solve this version of the classical problem?
*/

int m, n;
int dp[2005][2005][6];
int solve(int a[], int b[], int i, int j, int k) {
    if (i == m || j == n)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int case1 = 0, case2 = 0, case3 = 0;
    //simple lcs.
    if (a[i] == b[j])
        case1 = 1 + solve(a, b, i + 1, j + 1, k);
    //not equal, then change value using k.
    if (k > 0)
        case2 = 1 + solve(a, b, i + 1, j + 1, k - 1);
    //not equal no change.
    case3 = max(solve(a, b, i + 1, j, k), solve(a, b, i, j + 1, k));
    return dp[i][j][k] = max({case1, case2, case3});
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k;
    cin >> m >> n >> k;
    int a[m], b[n];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    memset(dp, -1, sizeof dp);
    cout << solve(a, b, 0, 0, k);

    return 0;
}