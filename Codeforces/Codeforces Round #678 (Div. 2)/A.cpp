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
        int n, k;
        cin >> n >> k;
        int total = 0;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        if (total == k)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}