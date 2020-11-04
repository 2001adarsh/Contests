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
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1])
                ans++;
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            x--;
            if (arr[x] == y) {
                cout << ans << endl;
                continue;
            }

            //before
            if (x < n - 1 && (arr[x] != arr[x + 1]))
                ans--;
            if (x > 0 && (arr[x] != arr[x - 1]))
                ans--;
            //after
            arr[x] = y;
            if (x < n - 1 && (arr[x] != arr[x + 1]))
                ans++;
            if (x > 0 && (arr[x] != arr[x - 1]))
                ans++;

            cout << ans << endl;
        }
    }

    return 0;
}