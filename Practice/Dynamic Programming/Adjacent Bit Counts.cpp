#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL
int dp[105][105][2];

// Adjacent Bit Counts
// https://www.spoj.com/problems/GNYR09F/


int ways(int prev, int places, int bits) {
    if (places == 0 && bits != 0)
        return 0;
    if (places == 0 && bits == 0)
        return 1;

    if (dp[places][bits][prev] != -1)
        return dp[places][bits][prev];

    int ans = 0;
    //check for previous.
    if (prev == 1) {
        ans += ways(1 , places - 1, bits - 1);
        ans += ways(0, places - 1, bits);
    } else {
        ans += ways(1, places - 1, bits);
        ans += ways(0, places - 1, bits);
    }
    return dp[places][bits][prev] = ans;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    while (t--) {
        int x, places, bits;
        cin >> x >> places >> bits;
        string s1 = "1", s2 = "0";
        int i = ways(1, places - 1, bits);
        int j = ways(0, places - 1, bits);
        cout << x << " " << i + j << endl;
    }

    return 0;
}