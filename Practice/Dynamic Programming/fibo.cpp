#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Fibonacci DP. time- O(n) and space - O(n)
int TopDown(int n, int dp[]) {
    if (n == 0 or n == 1)
        return n;
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = TopDown(n - 1, dp) + TopDown(n - 2, dp);
}

int BottomUp(int n) {
    int dp[1000] = {0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int dp[1000] = {0};
    cout << TopDown(6, dp);
    cout << BottomUp(6);
    return 0;
}