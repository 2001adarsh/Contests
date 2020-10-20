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

    int t, q = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << q << ": ";
        q++;
        int n;
        cin >> n;
        int arr[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += arr[i][i];
        }

        for (int gap = 1; gap <= n; gap++) {

            int left = 0, right = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i + gap == j) {
                        right += arr[i][j];
                    } else if (j + gap == i)
                        left += arr[i][j];
                }
            }
            ans = max(left, max(right, ans));
        }
        cout << ans << endl;
    }

    return 0;
}