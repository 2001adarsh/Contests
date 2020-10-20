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
        int arr[n];
        int large = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            large = max(arr[i], large);
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == large) {
                if (i > 0 && arr[i - 1] < large) {
                    ans = i + 1; break;
                } else if (i < n - 1 && arr[i + 1] < large) {
                    ans = i + 1; break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}