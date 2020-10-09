#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (1) {
        int n;
        cin >> n;
        if (n == -1)
            break;
        int *arr = new int[n];
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }

        int *pre = new int[n + 1];
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + arr[i];

        if (total % n) {
            cout << -1 << endl;
            continue;
        }
        int need = total / n;
        //now taking partition to be i and n-i.
        int i = 0, ans = INT_MIN;
        while (i < n) {
            int have = pre[i];
            ans = max(ans, abs(have - (need * (i + 1))));
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}