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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        int target = arr[n - 1];
        int small = arr[0];
        int ans = 0;
        for (int i = 1; (i < n - 1) && (small > 0); i++) {
            int x = target - arr[i];
            int y = min(x, small);
            small -= y;
            arr[i] += y;
        }

        for (int i = 1; i < n - 1; i++) {
            ans += target - arr[i];
        }
        if ( (small == 0) || (small % (n - 1) == 0) )
            cout << ans << endl;
        else {
            // cout << small << " " << ans << " ";
            if (n - 1 >= small)
                cout << ans + (n - 1 - small) << endl;
            else {
                int x = small % (n - 1);
                cout << ans + (n - 1 - x) << endl;
            }
        }
    }

    return 0;
}