#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

bool valid(int l, int r, int N) {
    int x = N % l;
    for (int i = l + 1; i <= r; i++) {
        if (x <= N % i)
            return false;
        x = N % i;
    }
    return true;
}

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
        int l, r;
        cin >> l >> r;
        if (r >= 2 * l)
            cout << -1 << endl;
        else
            cout << r << endl;
    }
    return 0;
}