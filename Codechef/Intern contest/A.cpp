#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

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
        int n;
        cin >> n;
        int first = 0, second = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i & 1)
                second += x;
            else
                first += x;
        }
        cout << max(first, second) << endl;
    }

    return 0;
}