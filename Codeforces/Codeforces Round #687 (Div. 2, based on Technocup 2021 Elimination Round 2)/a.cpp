#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


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
        int m, n, r, c;
        cin >> m >> n >> r >> c;

        int ans = 0;

        int x = (r - 1) + (c - 1);
        int y = abs(m - r) + abs(c - 1);
        int z = abs(r - 1) + abs(n - c);
        int w = abs(r - m) + abs(n - c);

        cout << max({x, y, z, w}) << endl;

    }

    return 0;
}