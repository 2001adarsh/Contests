#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int n, m, t;
    cin >> n >> m >> t;
    int B = n;
    bool flag = false;
    int prev = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        B -= (x - prev);
        B = max(B, 0LL);
        if (B == 0) {flag = true; break;}
        B += (y - x);
        B = min(B, n);
        prev = y;
    }

    B -= (t - prev);
    if (flag) cout << "No";
    else if (B <= 0) cout << "No";
    else cout << "Yes";

    return 0;
}