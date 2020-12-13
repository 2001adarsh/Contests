#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int dp[500][500];

int ways(int L, int C) {
    if (L <= C)
        return 0;
    if (C == 1 && L > 1)
        return dp[L][C] = L - 1;
    if (dp[L][C] != -1)
        return dp[L][C];

    int ans = 0;
    //cut here
    ans += ways(L - 1, C - 1);
    ans += ways(L - 1, C);
    return dp[L][C] = ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << ways(n, 11);

    return 0;
}