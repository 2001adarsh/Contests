#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

int highest(std::vector<int> arr, int n) {
    int pos = 0, diff = 0;
    for (int i = 1; i < n; i++) {
        if (diff < abs(arr[i] - arr[0])) {
            diff = abs(arr[i] - arr[0]);
            pos = i;
        }
    }
    return pos;
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
        int n;
        cin >> n;

        std::vector<int> arr(n);
        for (auto& i : arr) cin >> i;

        if (n == 1 || n == 2) {
            cout << 0 << endl;
            continue;
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            res += abs(arr[i] - arr[i - 1]);
        }

        int ans = res - abs(arr[1] - arr[0]);
        for (int i = 1; i < n - 1; i++) {
            ans = min(ans, res + abs(arr[i + 1] - arr[i - 1]) - abs(arr[i] - arr[i - 1]) - abs(arr[i + 1] - arr[i]));
        }

        /*int G = 0;
        // cout << ans << endl;
        int addOns = 0, flag = 0, getOns = 0;
        int ele = arr[0];
        int mxp = highest(arr, n);
        // cout << arr[mxp] << " ";
        arr[mxp] = arr[1];
        for (int i = 1; i < n; i++) {
            arr[i] += addOns;

            if (arr[i] == ele) continue;
            addOns += ele - arr[i];

            G += abs(ele - arr[i]);

        }*/

        ans = min(ans, res - abs(arr[n - 1] - arr[n - 2]));
        for (int i = n - 2; i > 0; i--) {
            ans = min(ans, res + abs(arr[i + 1] - arr[i - 1]) - abs(arr[i - 1] - arr[i]) - abs(arr[i + 1] - arr[i]));
        }
        cout << ans << endl;
        // cout << min(G, ans) << endl;
    }
    return 0;
}